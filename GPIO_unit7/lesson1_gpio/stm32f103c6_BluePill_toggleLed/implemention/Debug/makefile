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
lab1_GPIO_toggleLed.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
lab1_GPIO_toggleLed.list \

OBJCOPY_HEX += \
lab1_GPIO_toggleLed.hex \

OBJCOPY_BIN += \
lab1_GPIO_toggleLed.bin \


# All Target
all: lab1_GPIO_toggleLed.elf secondary-outputs

# Tool invocations
lab1_GPIO_toggleLed.elf: $(OBJS) $(USER_OBJS) E:\github\GPIO_unit7\lesson1_gpio_7segment\stm32f103c6_BluePill_toggleLed\implemention\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "lab1_GPIO_toggleLed.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"E:\github\GPIO_unit7\lesson1_gpio_7segment\stm32f103c6_BluePill_toggleLed\implemention\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="lab1_GPIO_toggleLed.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

lab1_GPIO_toggleLed.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "lab1_GPIO_toggleLed.list"
	@echo 'Finished building: $@'
	@echo ' '

lab1_GPIO_toggleLed.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "lab1_GPIO_toggleLed.hex"
	@echo 'Finished building: $@'
	@echo ' '

lab1_GPIO_toggleLed.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "lab1_GPIO_toggleLed.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
