INCLUDE=-I $(LIBDIR)
LIBS=-L ~/lib -lm -larduino -lNeoPixel -lSPI -lMFRC522
CFLAGS=$(MCU) $(CPU_SPEED) -Os -w -Wl,--gc-sections -ffunction-sections -fdata-sections
PORT=/dev/ttyUSB0
OBJECTS= Pixel.o Pixels.o Reader.o FiniteStateMachine.o

default: build upload

build: clean Magic.hex

Magic.hex: Magic.elf
	avr-objcopy -O ihex $< $@

Magic.elf: $(OBJECTS) main.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) $^ -o $@ $(LIBS)

upload:
	avrdude -V -F -p m328p -c arduino -b $(BAUD) -Uflash:w:Magic.hex -P$(PORT)

clean:
	@echo -n Cleaning ...
	$(shell rm Magic.elf 2> /dev/null)
	$(shell rm Magic.hex 2> /dev/null)
	$(shell rm *.o 2> /dev/null)
	@echo " done"

%.o: %.cpp
	$(CXX) $< $(CFLAGS) $(INCLUDE) -c -o $@
