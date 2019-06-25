# Makefile : builds M021_V4L2 OpenCV examples
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

LIBS = -L /usr/lib/x86_64-linux-gnu -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_video \
	   -lpthread -lv4l2 -ludev

OBJS = m021_v4l2_opencv.o m021_v4l2.o m021_thread_support.o

CFLAGS = -Wall

all: capture flowcap

test: capture
	./capture

cap: capture
	./capture

capture: capture.o $(OBJS)
	g++ -o capture capture.o $(OBJS) $(LIBS)

capture.o: capture.cpp
	g++ $(CFLAGS) -c capture.cpp

flow: flowcap
	./flowcap

flowcap: flowcap.o $(OBJS)
	g++ -o flowcap flowcap.o $(OBJS) $(LIBS)

flowcap.o: flowcap.cpp
	g++ $(CFLAGS) -c flowcap.cpp

m021_v4l2.o: ../../m021_v4l2.c
	g++ -c -I .. -I ../.. ../../m021_v4l2.c 

m021_v4l2_opencv.o: m021_v4l2_opencv.cpp  
	g++ -c -I .. -I ../.. m021_v4l2_opencv.cpp 

m021_thread_support.o: ../m021_thread_support.c ../m021_thread_support.h
	g++ -c -I.. -I../.. ../m021_thread_support.c

clean:
	rm -rf capture flowcap *.o Documentation *~ 

edit:
	vim capture.cpp

doc: Doxyfile
	doxygen

commit:
	git commit -a --allow-empty-message -m '' 
	git push
