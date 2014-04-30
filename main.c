#include <stdio.h>
#define GNOME_DESKTOP_USE_UNSTABLE_API 1
#include <gnome-idle-monitor.h>

int main(void) {
    printf("Starting idle time detect\r\n");

    GnomeIdleMonitor* gim = gnome_idle_monitor_new();

    return (0);
}
