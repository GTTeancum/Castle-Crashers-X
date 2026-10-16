// SPDX-License-Identifier: MIT
// The installer window: package and output folder, Start/Cancel, a live
// progress bar and the file log. The conversion runs on worker threads;
// log lines and progress reach the window through a queue drained ten times
// a second, so thousands of lines do not stall the interface.
using System.Collections.Concurrent;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Windows;
using System.Windows.Threading;
using CastleCrashersXInstaller.Conversion;
using Microsoft.Win32;

namespace CastleCrashersXInstaller;

public partial class MainWindow : Window
{
    readonly ObservableCollection<string> _log = [];
    readonly ConcurrentQueue<string> _pending = new();
    readonly DispatcherTimer _timer;
    CancellationTokenSource? _cts;
    double _fraction;
    string _stepName = "";
    readonly Stopwatch _clock = new();

    public MainWindow()
    {
        InitializeComponent();
        LogList.ItemsSource = _log;
        _timer = new DispatcherTimer(TimeSpan.FromMilliseconds(100), DispatcherPriority.Background, (_, _) => Drain(), Dispatcher);
    }

    void Log(string line) => _pending.Enqueue($"[{_clock.Elapsed:mm\\:ss}] {line}");

    void Drain()
    {
        bool added = false;
        while (_pending.TryDequeue(out var line)) { _log.Add(line); added = true; }
        if (added) LogList.ScrollIntoView(_log[^1]);
        if (_cts != null)
        {
            Progress.Value = _fraction;
            PercentText.Text = $"{_fraction * 100:F0}%";
            StatusText.Text = _stepName + "…";
        }
    }

    void PackageBrowse_Click(object sender, RoutedEventArgs e)
    {
        var d = new OpenFileDialog { Title = "Choose your Xbox LIVE Castle Crashers package", Filter = "Xbox LIVE package|*.*", CheckFileExists = true };
        if (d.ShowDialog(this) == true) PackageBox.Text = d.FileName;
    }

    void OutputBrowse_Click(object sender, RoutedEventArgs e)
    {
        var d = new OpenFolderDialog { Title = "Choose the Xbox output folder" };
        if (d.ShowDialog(this) == true) OutputBox.Text = d.FolderName;
    }

    async void Start_Click(object sender, RoutedEventArgs e)
    {
        var package = PackageBox.Text.Trim('"', ' ');
        var output = OutputBox.Text.Trim('"', ' ');
        if (!File.Exists(package)) { MessageBox.Show(this, "Choose your Xbox LIVE Castle Crashers package first.", Title); return; }
        if (output.Length == 0) { MessageBox.Show(this, "Choose an output folder first.", Title); return; }
        if (Directory.Exists(output) && Directory.EnumerateFileSystemEntries(output).Any() &&
            MessageBox.Show(this, $"{output} is not empty. Files of a previous conversion there will be replaced. Continue?", Title,
                            MessageBoxButton.YesNo, MessageBoxImage.Question) != MessageBoxResult.Yes)
            return;

        _log.Clear();
        _cts = new CancellationTokenSource();
        SetRunning(true);
        _clock.Restart();
        _timer.Start();
        Log($"package: {package}");
        Log($"output:  {output}");
        var pipeline = new Pipeline(Log, (f, s) => { _fraction = f; _stepName = s; });
        string result;
        try
        {
            Directory.CreateDirectory(output);
            await Task.Run(() => pipeline.Run(package, output, _cts.Token));
            result = $"Done in {_clock.Elapsed:mm\\:ss}. Copy {output} to your Xbox and run default.xbe.";
            _fraction = 1;
        }
        catch (OperationCanceledException)
        {
            result = "Cancelled.";
        }
        catch (Exception ex)
        {
            result = "Stopped: " + ex.Message;
            Log("ERROR: " + ex.Message);
        }
        Log(result);
        Drain();
        _timer.Stop();
        _cts = null;
        StatusText.Text = result;
        SetRunning(false);
        if (result.StartsWith("Stopped")) MessageBox.Show(this, result, Title, MessageBoxButton.OK, MessageBoxImage.Error);
    }

    void Cancel_Click(object sender, RoutedEventArgs e) => _cts?.Cancel();

    void SetRunning(bool running)
    {
        StartButton.IsEnabled = !running;
        CancelButton.IsEnabled = running;
        PackageBox.IsEnabled = OutputBox.IsEnabled = PackageBrowse.IsEnabled = OutputBrowse.IsEnabled = !running;
    }

    protected override void OnClosing(System.ComponentModel.CancelEventArgs e)
    {
        if (_cts != null &&
            MessageBox.Show(this, "The conversion is still running. Stop it and close?", Title, MessageBoxButton.YesNo) != MessageBoxResult.Yes)
        { e.Cancel = true; return; }
        _cts?.Cancel();
        base.OnClosing(e);
    }
}
