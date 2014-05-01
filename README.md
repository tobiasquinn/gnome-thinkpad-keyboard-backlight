gnome-macbook-keyboard-backlight
================================

Keyboard backlight idler for Macbook Pro 11,1 and gnome 3 desktop

This uses the filesystem under /sys to control the backlight on a macbook
pro 11,1. It currently sets a timeout of 10 seconds idle from the gnome
desktop and saves the keyboard backlight value and switches it off. When
the user is not idle it restores the backlight setting.

It uses the utility kbdlight which can be found at:
https://github.com/hobarrera/kbdlight/

There is an archlinux package that can be built using makepkg and uses the
master of the github repository. It requires the package kbdlight from AUR.

It is GPL3, please see the LICENSE file

(c) Tobias Quinn, April 2014
