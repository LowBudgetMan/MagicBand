########################
# Script to debug Band Reader
# Listens for anything coming in from the serial
########################
import serial

ser = serial.Serial("/dev/ttyUSB0", 9600)
while True:
    print(repr(ser.readline()))
