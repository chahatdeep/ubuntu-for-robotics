# Makefile : builds M021_V4L2 capture example for YUYV images using GTK + SDL.
#
# Copyright (C) Simon D. Levy 2016
#
# This file is part of M021_V4L2.
#
# M021_V4L2 is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# M021_V4L2 is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with M021_V4L2.  If not, see <http://www.gnu.org/licenses/>.

CC = gcc

m021cap_OBJECTS = m021cap.o m021_v4l2.o

m021cap_LINK = $(CC) $(m021cap_CFLAGS) $(CFLAGS) \
	$(m021cap_LDFLAGS) $(LDFLAGS) -o $@

QUIET = @echo "  CC      " $@;

COMPILE = $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	$(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)

LINK = $(CC) $(AM_CFLAGS) $(CFLAGS) $(AM_LDFLAGS) $(LDFLAGS) -o $@

INCLUDES = -I/usr/include/gtk-3.0 \
		   -I/usr/include/pango-1.0 \
		   -I/usr/include/atk-1.0 \
		   -I/usr/include/cairo \
		   -I/usr/include/gdk-pixbuf-2.0 \
		   -I/usr/include/glib-2.0 \
		   -I/usr/lib/x86_64-linux-gnu/glib-2.0/include

DEPS_CFLAGS = $(INCLUDES) -pthread -D_GNU_SOURCE=1 -D_REENTRANT -pthread 

DEPS_LIBS = -lgtk-3 -lgdk-3 -lpango-1.0 -lgobject-2.0 -lglib-2.0 -lSDL -lpthread -lv4l2 -ludev

m021cap_SOURCES = m021cap.c ../m021_v4l2.h ../m021_v4l2.c 

m021cap_CFLAGS = -DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
				  -DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
				  -DPACKAGE_DATA_DIR=\""$(datadir)"\" \
				  $(DEPS_CFLAGS) \
				  $(EXTRA_CFLAGS) \
				  $(PTHREAD_CFLAGS) \
				  -D_REENTRANT \
	 			  -D_FILE_OFFSET_BITS=64 \
	 			  -Wall

m021cap_LDFLAGS = $(LIBINTL)
m021cap_LDADD = $(DEPS_LIBS) $(EXTRA_LIBS) $(PTHREAD_LIBS)

all: m021cap

m021cap: $(m021cap_OBJECTS) $(m021cap_DEPENDENCIES) $(EXTRA_m021cap_DEPENDENCIES) 
	$(m021cap_LINK) $(m021cap_OBJECTS) $(m021cap_LDADD) $(LIBS)

m021cap.o: m021cap.c ../m021_v4l2.h
	 $(QUIET) $(CC)  $(m021cap_CFLAGS) -c -o m021cap.o m021cap.c

m021_v4l2.o: ../m021_v4l2.c ../m021_v4l2*.h
	$(QUIET) $(CC)  $(m021cap_CFLAGS) -c -o m021_v4l2.o ../m021_v4l2.c

clean:
	rm -f m021cap *.o

run: m021cap
	./m021cap

commit:
	git commit -a --allow-empty-message -m ''; git push

edit:
	vim m021cap.c
