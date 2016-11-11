export LIBRARIES= -I$(CURDIR) -I$(LIBDIR)

build:
	(cd neopixel; make)
	(cd SPI; make)
	(cd rfid; make)

clean:
	(rm -r headers)
