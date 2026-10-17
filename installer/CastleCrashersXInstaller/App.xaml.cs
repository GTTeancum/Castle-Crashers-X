// SPDX-License-Identifier: MIT
using System.Windows;

namespace CastleCrashersXInstaller;

public partial class App : Application
{
    // An unexpected error is shown, not swallowed: the window would
    // otherwise just vanish.
    protected override void OnStartup(StartupEventArgs e)
    {
        DispatcherUnhandledException += (_, args) =>
        {
            MessageBox.Show(args.Exception.ToString(), "Castle Crashers X Installer: unexpected error",
                            MessageBoxButton.OK, MessageBoxImage.Error);
            args.Handled = true;
            Shutdown(1);
        };
        base.OnStartup(e);
    }
}
