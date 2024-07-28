
CC = arm-none-eabi
CFLAGS = -gdwarf-2 -mcpu=cortex-m3 -mthumb 
INTS = -I.
LIBS =

# Source and object files
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)


# Project name
project_name = toggle_led_ByCortex-m3


# Build all target
build_all: $(project_name).bin
	echo Compile building...

# Compile C source files
%.o: %.c
	$(CC)-gcc -c $< $(CFLAGS) -std=c99 $(INTS) -o $@

# Assemble assembly files
%.o: %.s
	$(CC)-as $< $(CFLAGS) $(INTS) -o $@

# Link object files
$(project_name).elf: $(ASOBJ) $(OBJ)
	$(CC)-ld -T linker_script.ld $(LIBS) $(ASOBJ) $(OBJ) -o $@ -Map =Map_file.map

# Create binary file from ELF file
$(project_name).bin: $(project_name).elf
	$(CC)-objcopy -O binary $< $@

# Clean all files
clean_all:
	rm -f $(OBJ) $(ASOBJ) $(project_name).elf $(project_name).bin

# Clean project files
clean:
	rm -f $(project_name).elf $(project_name).bin

