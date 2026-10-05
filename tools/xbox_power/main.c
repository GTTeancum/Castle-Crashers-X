// SPDX-License-Identifier: MIT
// Console power tool for unattended test runs (launched by
// tools/xbox_console.py poweroff / ledtest).
//   make            power off: tells the system management controller (SMC,
//                   SMBus address 0x20) to switch the console off
//                   (command 0x02, value 0x80)
//   make LEDTEST=1  harmless check of the same SMBus path: the front LED
//                   blinks orange for 10 s, then goes back to system control
#include <windows.h>
#include <xboxkrnl/xboxkrnl.h>

int main(void)
{
#ifdef LEDTEST
    // SMC 0x08: LED sequence (red phases high nibble, green low; 0xAA =
    // orange, off, orange, off); 0x07 = 1 selects it, 0 returns the LED to
    // the system. The statuses show whether the SMBus writes went through.
    const NTSTATUS a = HalWriteSMBusValue(0x20, 0x08, FALSE, 0xAA);
    const NTSTATUS b = HalWriteSMBusValue(0x20, 0x07, FALSE, 1);
    DbgPrint("POWERTOOL led test status=%08lx,%08lx\n", (unsigned long)a, (unsigned long)b);
    Sleep(10000);
    const NTSTATUS c = HalWriteSMBusValue(0x20, 0x07, FALSE, 0);
    DbgPrint("POWERTOOL led reset status=%08lx\n", (unsigned long)c);
#else
    DbgPrint("POWERTOOL power off\n");
    Sleep(500);
    HalWriteSMBusValue(0x20, 0x02, FALSE, 0x80);
#endif
    for (;;)
        Sleep(1000);
    return 0;
}
