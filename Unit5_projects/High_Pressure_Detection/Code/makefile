
CC = arm-none-eabi-
CFLAGS = -gdwarf-2 -mcpu=cortex-m4 -mthumb
INGS = -I.

#wildcard 
SRC =$(wildcard *.c)
AS =$(wildcard *.s)
#command to all object files
OBJ =$(SRC:.c=.o)
ASOBJ =$(AS:.s=.o)

#project name
project_name = High_Pressure_Detection

#buliding
build : $(project_name).bin
	echo DONE...

%.o : %.c 
	$(CC)gcc -c $< $(CFLAGS) $(INGS) -o $@

%.o : %.s 
	$(CC)AS $< $(CFLAGS) $(INGS) -std=c99 -o $@

$(project_name).elf : $(ASOBJ) $(OBJ)
	$(CC)ld -T linker.ld $(ASOBJ) $(OBJ) -o $@ -Map Map_file.map
	cp $(project_name).elf  $(project_name).hex

$(project_name).bin : $(project_name).elf
	$(CC)objcopy -O binary $< $@

#clean all files
cleanAll: 
	rm -f  $(ASOBJ) $(OBJ) $(project_name).bin $(project_name).elf $(project_name).hex
#clean after the object files
clean: 
	rm -f  $(project_name).bin $(project_name).elf $(project_name).hex


