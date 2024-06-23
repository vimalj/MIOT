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
CA8_part1_timers_millis.lss \

FLASH_IMAGE += \
CA8_part1_timers_millis.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: CA8_part1_timers_millis.elf secondary-outputs

# Tool invocations
CA8_part1_timers_millis.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,CA8_part1_timers_millis.map -mmcu=atmega328p -o "CA8_part1_timers_millis.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

CA8_part1_timers_millis.lss: CA8_part1_timers_millis.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S CA8_part1_timers_millis.elf  >"CA8_part1_timers_millis.lss"
	@echo 'Finished building: $@'
	@echo ' '

CA8_part1_timers_millis.hex: CA8_part1_timers_millis.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex CA8_part1_timers_millis.elf  "CA8_part1_timers_millis.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: CA8_part1_timers_millis.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p CA8_part1_timers_millis.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) CA8_part1_timers_millis.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
