gnome-keyboard-backlight
========================

Keyboard backlight idler for Macbook Pro 11,1 and gnome 3 desktop

This uses the filesystem under /sys to control the backlight on a macbook
pro 11,1. It currently sets a timeout of 10 seconds idle from the gnome
desktop and saves the keyboard backlight values and switches it off. When
the user is not idle it restores the backlight setting.

Is expects to be about to run tee using sudo eg. a command like:

echo 33 | sudo tee /sys/class/leds/smc::kbd_backlight/backlight

There is an archlinux package that can be built using makepkg and uses the
master of the github repository.

It is GPL3, please see the LICENSE file

(c) Tobias Quinn, April 2014
