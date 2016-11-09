CFLAGS=$(MCU) $(CPU_SPEED) -Os -w
BOARD=arduino
LIBNAME=lib$(BOARD).a

OBJECTS= new.o CDC.o HID.o IPAddress.o main.o Stream.o \
		   USBCore.o wiring.o wiring_analog.o wiring_digital.o \
		   wiring_pulse.o wiring_shift.o HardwareSerial.o Print.o   \
		   Tone.o WMath.o WString.o WInterrupts.o forward.o

default: $(OBJECTS)
	avr-ar rcs $(LIBNAME) $^
	mkdir -p $(LIBDIR)
	mkdir -p ~/lib/
	cp *.h $(LIBDIR)
	mv $(LIBNAME) ~/lib/
	rm *.o

%.o : %.c
	$(CC) -I$(CURDIR) $< $(CFLAGS) -c -o $@

%.o : %.cpp
	$(CXX) -I$(CURDIR) $< $(CFLAGS) -c -o $@
