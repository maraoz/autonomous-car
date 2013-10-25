#! /usr/bin/python

import serial

s = serial.Serial('/dev/ttyUSB0', 9600)


while True:
	reading = s.readline()
	sensor, value = reading.split(":")
    s.write(value)

		
	





