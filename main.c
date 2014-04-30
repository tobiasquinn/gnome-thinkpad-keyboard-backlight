#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define GNOME_DESKTOP_USE_UNSTABLE_API 1
#include <gnome-idle-monitor.h>

#define DELAY_TIME 10000
#define BACKLIGHT_SYS_FILE "/sys/class/leds/smc::kbd_backlight/brightness"
#define BACKLIGHT_SUDO_COMMAND "echo %d | sudo tee %s\n"

static int saved_backlight_value = -1;
//int backlight_fp; // backlight control file
GnomeIdleMonitor *gim; // idle monitor instance

#define MAX_LINE 255

void set_backlight_value(int value) {
    char line[MAX_LINE];
    sprintf(line, BACKLIGHT_SUDO_COMMAND, value, BACKLIGHT_SYS_FILE);
    printf("VAL %d LINE:%s\n", value, line);
    system(line);
}

int get_backlight_value(void) {
    // read the SYS_FILE
    int n;
    char line[MAX_LINE];

    // open the backlight control file
    int backlight_fp = open(BACKLIGHT_SYS_FILE, O_RDONLY);
    n = read(backlight_fp, line, MAX_LINE);
    if (n == -1)
        printf("File read error\n");
    n = atoi(line);
    close(backlight_fp);
    return n;
}

void active_watch_func(GnomeIdleMonitor *monitor,
        guint id,
        gpointer user_data) {
    // restore the backlight
    set_backlight_value(saved_backlight_value);
    printf("user active\n");
}

void idle_watch_func(GnomeIdleMonitor *monitor,
        guint id,
        gpointer user_data) {
    printf("user idle\n");
    // we want to save the existing backlight value
    saved_backlight_value = get_backlight_value();
    printf("saved backlight value %d\n", saved_backlight_value);
    // and turn it down to zero
    set_backlight_value(0);
    gnome_idle_monitor_add_user_active_watch(gim,
            &active_watch_func,
            0,
            0);
}

int main(void) {
    printf("Starting idle time detect\n");

    GMainLoop *loop;

    gim = gnome_idle_monitor_new();

    gnome_idle_monitor_add_idle_watch(gim,
            DELAY_TIME,
            &idle_watch_func,
            0,
            0);

    loop = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(loop);
    g_main_loop_unref(loop);

    return 0;
}
