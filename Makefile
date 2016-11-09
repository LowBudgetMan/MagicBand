export BINDIR=$(CURDIR)/bin
export LIBDIR=$(CURDIR)/lib/headers
export MCU=-mmcu=atmega328p
export CPU_SPEED=-DF_CPU=16000000UL
export BAUD=57600
export CC=avr-gcc
export CXX=avr-g++

build:
	(cd arduino-lib; make)
	(cd lib; make build)
	(cd src; make build)

upload: build
	(cd src; make upload)

clean:
	(cd lib; make clean)
	(cd src; make clean)

