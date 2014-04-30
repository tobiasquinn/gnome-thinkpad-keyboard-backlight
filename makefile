CC=g++ 	# the C compiler is gcc
CFLAGS=-g -Wall
LDFLAGS=

SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

EXECUTABLE = gnome-keyboard-backlight

CFLAGS  += $(shell pkg-config --cflags --libs gnome-desktop-3.0)
LDFLAGS += $(shell pkg-config --libs gnome-desktop-3.0)
CFLAGS  += -I/usr/include/gnome-desktop-3.0/libgnome-desktop

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE)
