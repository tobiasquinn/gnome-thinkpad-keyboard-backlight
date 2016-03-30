#!/bin/sh
#gcc -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include ThinkLight.c -o ThinkLight -lglib-2.0
gcc `pkg-config --cflags glib-2.0` ThinkLight.c -o ThinkLight -lglib-2.0

