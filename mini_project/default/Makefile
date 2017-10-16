###############################################################################
# Makefile for the project ex_timer
###############################################################################

## General Flags
PROJECT = ex_timer
MCU = atmega128
TARGET = ex_timer.elf
CC = avr-gcc

CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -std=gnu99 -DF_CPU=14745600UL -O0 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=ex_timer.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Include Directories
INCLUDES = -I"E:\AVR_PROJECT\example\mini_project\..\myLib" 

## Objects that must be built in order to link
OBJECTS = mini_project.o myLib_timer.o myLib_7seg.o myLib_adc.o myLib_Uart.o myLib_util.o myLib_EXTI.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) ex_timer.hex ex_timer.eep ex_timer.lss size

## Compile
mini_project.o: ../mini_project.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

myLib_timer.o: ../../myLib/myLib_timer.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

myLib_7seg.o: ../../myLib/myLib_7seg.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

myLib_adc.o: ../../myLib/myLib_adc.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

myLib_Uart.o: ../../myLib/myLib_Uart.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

myLib_util.o: ../../myLib/myLib_util.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

myLib_EXTI.o: ../../myLib/myLib_EXTI.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) ex_timer.elf dep/* ex_timer.hex ex_timer.eep ex_timer.lss ex_timer.map


## Other dependencies
-include $(shell mkdir dep 2>NUL) $(wildcard dep/*)

