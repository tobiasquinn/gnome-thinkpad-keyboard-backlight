#include <stdio.h>
#define GNOME_DESKTOP_USE_UNSTABLE_API 1
#include <gnome-idle-monitor.h>

#define DELAY_TIME 1000

void watch_func(GnomeIdleMonitor *monitor,
        guint id,
        gpointer user_data) {
    printf("watch_func\r\n");
}

int main(void) {
    printf("Starting idle time detect\r\n");
    GMainLoop *loop;

    GnomeIdleMonitor *gim = gnome_idle_monitor_new();
    guint64 idle_time = gnome_idle_monitor_get_idletime(gim);
    printf("%ld idle time\n", idle_time);

    gnome_idle_monitor_add_idle_watch(gim,
            DELAY_TIME,
            &watch_func,
            0,
            0);

    loop = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(loop);
    g_main_loop_unref(loop);

    return 0;
}
