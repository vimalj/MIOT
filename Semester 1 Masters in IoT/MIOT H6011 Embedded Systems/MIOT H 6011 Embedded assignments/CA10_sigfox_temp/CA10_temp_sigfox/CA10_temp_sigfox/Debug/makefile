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
CA10_temp_sigfox.lss \

FLASH_IMAGE += \
CA10_temp_sigfox.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: CA10_temp_sigfox.elf secondary-outputs

# Tool invocations
CA10_temp_sigfox.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,CA10_temp_sigfox.map -Wl,-u,vfprintf -lprintf_flt -lm -mmcu=atmega328p -o "CA10_temp_sigfox.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

CA10_temp_sigfox.lss: CA10_temp_sigfox.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S CA10_temp_sigfox.elf  >"CA10_temp_sigfox.lss"
	@echo 'Finished building: $@'
	@echo ' '

CA10_temp_sigfox.hex: CA10_temp_sigfox.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex CA10_temp_sigfox.elf  "CA10_temp_sigfox.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: CA10_temp_sigfox.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p CA10_temp_sigfox.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) CA10_temp_sigfox.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
