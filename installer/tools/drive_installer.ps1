# Drive the installer window through UI Automation: fill both boxes, press
# Start, screenshot the window during and after the run.
param([string]$Exe, [string]$Package, [string]$Out, [string]$Shots)
Add-Type -AssemblyName UIAutomationClient, UIAutomationTypes
$cap = "D:\Programming\GitHub\Castle-Crashers-X\tools\capture_window.ps1"
New-Item -ItemType Directory -Force $Shots | Out-Null
$p = Start-Process -FilePath $Exe -PassThru
$win = $null
for ($i = 0; $i -lt 60 -and -not $win; $i++) {
  Start-Sleep -Milliseconds 500
  $p.Refresh()
  if ($p.MainWindowHandle -ne 0) { $win = [System.Windows.Automation.AutomationElement]::FromHandle($p.MainWindowHandle) }
}
if (-not $win) { throw "installer window did not appear" }
function Find($id) {
  $c = New-Object System.Windows.Automation.PropertyCondition([System.Windows.Automation.AutomationElement]::AutomationIdProperty, $id)
  $win.FindFirst([System.Windows.Automation.TreeScope]::Descendants, $c)
}
& powershell -NoProfile -File $cap -Process x -ProcessId $p.Id -Out "$Shots\0_start.png"
(Find "PackageBox").GetCurrentPattern([System.Windows.Automation.ValuePattern]::Pattern).SetValue($Package)
(Find "OutputBox").GetCurrentPattern([System.Windows.Automation.ValuePattern]::Pattern).SetValue($Out)
(Find "StartButton").GetCurrentPattern([System.Windows.Automation.InvokePattern]::Pattern).Invoke()
$t0 = Get-Date
$n = 1
foreach ($at in 4, 12, 30) {
  while (((Get-Date) - $t0).TotalSeconds -lt $at) { Start-Sleep -Milliseconds 200 }
  & powershell -NoProfile -File $cap -Process x -ProcessId $p.Id -Out ("$Shots\{0}_{1}s.png" -f $n, $at); $n++
}
$status = Find "StatusText"
while (((Get-Date) - $t0).TotalSeconds -lt 600) {
  $s = $status.Current.Name
  if ($s -like "Done*" -or $s -like "Stopped*" -or $s -like "Cancelled*") { break }
  Start-Sleep -Milliseconds 500
}
Start-Sleep -Milliseconds 800
& powershell -NoProfile -File $cap -Process x -ProcessId $p.Id -Out "$Shots\9_end.png"
"status: " + $status.Current.Name
"seconds: " + [int]((Get-Date) - $t0).TotalSeconds
$p.CloseMainWindow() | Out-Null
