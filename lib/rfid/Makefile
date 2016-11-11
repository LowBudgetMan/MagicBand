CFLAGS=$(MCU) $(CPU_SPEED) -Os -w
LIBNAME=libMFRC522.a
OBJECTS= MFRC522.o

build: $(OBJECTS)
	avr-ar rcs $(LIBNAME) $^
	mkdir -p $(LIBDIR)
	mkdir -p ~/lib/
	cp *.h $(LIBDIR)
	mv $(LIBNAME) ~/lib/
	rm *.o

%.o : %.cpp
	$(CXX) $(LIBRARIES) $< $(CFLAGS) -c -o $@
