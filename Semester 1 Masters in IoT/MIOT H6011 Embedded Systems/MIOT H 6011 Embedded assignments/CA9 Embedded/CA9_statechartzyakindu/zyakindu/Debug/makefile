################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src-gen/subdir.mk
-include sc_timer/subdir.mk
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
zyakindu.lss \

FLASH_IMAGE += \
zyakindu.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: zyakindu.elf secondary-outputs

# Tool invocations
zyakindu.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,zyakindu.map -mmcu=atmega328p -o "zyakindu.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

zyakindu.lss: zyakindu.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S zyakindu.elf  >"zyakindu.lss"
	@echo 'Finished building: $@'
	@echo ' '

zyakindu.hex: zyakindu.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex zyakindu.elf  "zyakindu.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: zyakindu.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p zyakindu.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) zyakindu.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
