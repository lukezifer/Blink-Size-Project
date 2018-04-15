# Blink-Size-Project

## Idea
The goal of this project is to showcase the difference in binary size for different implementations of the same blinky-task on an Arduino Mega2560.
The idea is to have the LED blinking at roughly 1Hz and try to get a minimum in binary size for the executable with different implementation approaches, for now in the C and C++.

## Build
To build the project, go to the subproject-folder and use the make targets, e.g.:

	cd simple_blink/
	make
	make upload
	make info

## Misc
This is an early version, not much there yet.

