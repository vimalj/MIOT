################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
CA6-74HC595-LCD-interfacing-b00122875.lss \

FLASH_IMAGE += \
CA6-74HC595-LCD-interfacing-b00122875.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: CA6-74HC595-LCD-interfacing-b00122875.elf secondary-outputs

# Tool invocations
CA6-74HC595-LCD-interfacing-b00122875.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,CA6-74HC595-LCD-interfacing-b00122875.map -mmcu=atmega328p -o "CA6-74HC595-LCD-interfacing-b00122875.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

CA6-74HC595-LCD-interfacing-b00122875.lss: CA6-74HC595-LCD-interfacing-b00122875.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S CA6-74HC595-LCD-interfacing-b00122875.elf  >"CA6-74HC595-LCD-interfacing-b00122875.lss"
	@echo 'Finished building: $@'
	@echo ' '

CA6-74HC595-LCD-interfacing-b00122875.hex: CA6-74HC595-LCD-interfacing-b00122875.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex CA6-74HC595-LCD-interfacing-b00122875.elf  "CA6-74HC595-LCD-interfacing-b00122875.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: CA6-74HC595-LCD-interfacing-b00122875.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p CA6-74HC595-LCD-interfacing-b00122875.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) CA6-74HC595-LCD-interfacing-b00122875.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
