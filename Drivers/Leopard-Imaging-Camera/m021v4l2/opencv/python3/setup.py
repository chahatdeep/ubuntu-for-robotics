#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

'''
setup.py : Python distutils install script for Leopard Imaging LI-USB30-M021 on Linux

Copyright (C) 2016 Simon D. Levy

This file is part of M021_V4L2.

M021_V4L2 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
BreezySTM32 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with M021_V4L2.  If not, see <http://www.gnu.org/licenses/>.
'''


from distutils.core import setup, Extension
import numpy as np

ext_modules = [Extension('libm021v4l2', 
    sources = ['libm021v4l2.c', '../m021_thread_support.c', '../../m021_v4l2.c'], 
    include_dirs = ['..', '../..'],
    libraries = ['pthread', 'v4l2', 'udev']
    )]

setup(
        name = 'M021V4L2',
        packages = ['m021v4l2'],
        version = '0.1',
        include_dirs = [np.get_include()], #Add Include path of numpy
        ext_modules = ext_modules
      )
