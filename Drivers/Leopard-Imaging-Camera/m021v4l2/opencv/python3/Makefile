# Makefile : convenient for installing/testing M021 Python API
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

install:
	python setup.py install

clean:
	rm -rf build *.pyc *~

cap:
	./capture.py

flow:
	./flowcap.py

test:
	./capture.py
