################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
lap2_lesson4_unit6.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
lap2_lesson4_unit6.list \

OBJCOPY_HEX += \
lap2_lesson4_unit6.hex \

OBJCOPY_BIN += \
lap2_lesson4_unit6.bin \

OBJCOPY_VERILOG += \
lap2_lesson4_unit6.verilog \

OBJCOPY_SREC += \
lap2_lesson4_unit6.srec \

OBJCOPY_SYMBOLSREC += \
lap2_lesson4_unit6.symbolsrec \


# All Target
all: lap2_lesson4_unit6.elf secondary-outputs

# Tool invocations
lap2_lesson4_unit6.elf: $(OBJS) $(USER_OBJS) E:\github\unit6_lesson4\lab2_Use_irq_ToggleLed_stm32f103\implemention\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc  -gdwarf-2 -o "lap2_lesson4_unit6.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"E:\github\unit6_lesson4\lab2_Use_irq_ToggleLed_stm32f103\implemention\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="lap2_lesson4_unit6.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

lap2_lesson4_unit6.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "lap2_lesson4_unit6.list"
	@echo 'Finished building: $@'
	@echo ' '

lap2_lesson4_unit6.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "lap2_lesson4_unit6.hex"
	@echo 'Finished building: $@'
	@echo ' '

lap2_lesson4_unit6.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "lap2_lesson4_unit6.bin"
	@echo 'Finished building: $@'
	@echo ' '

lap2_lesson4_unit6.verilog: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O verilog $(EXECUTABLES) "lap2_lesson4_unit6.verilog"
	@echo 'Finished building: $@'
	@echo ' '

lap2_lesson4_unit6.srec: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O srec $(EXECUTABLES) "lap2_lesson4_unit6.srec"
	@echo 'Finished building: $@'
	@echo ' '

lap2_lesson4_unit6.symbolsrec: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O symbolsrec $(EXECUTABLES) "lap2_lesson4_unit6.symbolsrec"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN) $(OBJCOPY_VERILOG) $(OBJCOPY_SREC) $(OBJCOPY_SYMBOLSREC)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
