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
CA5_Keypad_interfacing_lcd_using_keypadheader.lss \

FLASH_IMAGE += \
CA5_Keypad_interfacing_lcd_using_keypadheader.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: CA5_Keypad_interfacing_lcd_using_keypadheader.elf secondary-outputs

# Tool invocations
CA5_Keypad_interfacing_lcd_using_keypadheader.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,CA5_Keypad_interfacing_lcd_using_keypadheader.map -mmcu=atmega328p -o "CA5_Keypad_interfacing_lcd_using_keypadheader.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

CA5_Keypad_interfacing_lcd_using_keypadheader.lss: CA5_Keypad_interfacing_lcd_using_keypadheader.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S CA5_Keypad_interfacing_lcd_using_keypadheader.elf  >"CA5_Keypad_interfacing_lcd_using_keypadheader.lss"
	@echo 'Finished building: $@'
	@echo ' '

CA5_Keypad_interfacing_lcd_using_keypadheader.hex: CA5_Keypad_interfacing_lcd_using_keypadheader.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex CA5_Keypad_interfacing_lcd_using_keypadheader.elf  "CA5_Keypad_interfacing_lcd_using_keypadheader.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: CA5_Keypad_interfacing_lcd_using_keypadheader.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p CA5_Keypad_interfacing_lcd_using_keypadheader.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) CA5_Keypad_interfacing_lcd_using_keypadheader.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
