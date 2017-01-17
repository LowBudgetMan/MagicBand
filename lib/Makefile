export LIBRARIES= -I$(CURDIR) -I$(LIBDIR)

build:
	(cd neopixel; make)
	(cd SPI; make)
	(cd rfid; make)
	(cd EEPROM; make)

clean:
	(rm -r headers)
