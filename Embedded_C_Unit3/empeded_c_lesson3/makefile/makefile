
CC = arm-none-eabi
CFLAGS = -g -mcpu=arm926ej-s  
INTS = -I.
LIBS =

# Source and object files
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)


# Project name
project_name = my_app


# Build all target
build_all: $(project_name).bin
	echo Compile building...

# Compile C source files
%.o: %.c
	$(CC)-gcc -c $< $(CFLAGS) $(INTS) -o $@

# Assemble assembly files
%.o: %.s
	$(CC)-as $< $(CFLAGS) $(INTS) -o $@

# Link object files
$(project_name).elf: $(ASOBJ) $(OBJ)
	$(CC)-ld -T linker_script.ld $(LIBS) $(ASOBJ) $(OBJ) -o $@

# Create binary file from ELF file
$(project_name).bin: $(project_name).elf
	$(CC)-objcopy -O binary $< $@

# Clean all files
clean_all:
	rm -f $(OBJ) $(ASOBJ) $(project_name).elf $(project_name).bin

# Clean project files
clean:
	rm -f $(project_name).elf $(project_name).bin



