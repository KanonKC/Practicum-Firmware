TARGET=first.hex
MCU=atmega328p
F_CPU=16000000
CFLAGS=-mmcu=$(MCU) -Os -DF_CPU=$(F_CPU)
OBJS=
 
all: $(TARGET)
	 
%.flash: %.hex
	avrdude -p $(MCU) -c usbasp -U flash:w:$<
		 
%.hex: %.elf
	avr-objcopy -j .text -j .data -O ihex $< $@
		 
%.elf: %.o $(OBJS)
	avr-gcc $(CFLAGS) -o $@ $^
		 
%.o: %.c
	avr-gcc $(CFLAGS) -c -o $@ $<
		 
clean:
	rm -f *.o *.elf *.hex

