# odroid-xu4-fan-control
Adopted settings to get odroid-xu3-fan-control working on XU4.

Makes Odroid XU4 Lite fan silent on idle load

## Odroid XU4

Will only work on:
* *Ubuntu 15.04.1*

Was not tested anywhere else. Might work though after adjusting script variables

## Precautions

### Only *Odroid XU4* is supported

### Is it safe to use?

When script quits it brings fan mode back to *automatic* "factory" settings.

## Usage

    sudo apt-get install git
    git clone https://github.com/f1vefour/odroid-xu4-fan-control.git
    cd odroid-xu4-fan-control
    sudo ./odroid-xu4-fan-control.sh

## Installation

To make it start when system boots:

edit odroid-fan-controller and add the path of the odroid-xu3-fan-control.sh script (full-pathname), then do the following to add it
to the runlevels

    cd /etc/init.d/
    #adjust to correct, absolute path below
    sudo ln -s ~/odroid-xu4-fan-control/odroid-fan-controller
    sudo update-rc.d odroid-fan-controller defaults

you can also use the following to start the controller

    sudo /etc/init.d/odroid-fan-controller start

or

    sudo /etc/init.d/odroid-fan-controller stop

to stop the controller
