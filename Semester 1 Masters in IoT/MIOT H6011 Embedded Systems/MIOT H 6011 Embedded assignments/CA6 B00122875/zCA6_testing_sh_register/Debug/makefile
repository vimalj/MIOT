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
zCA6_testing_sh_register.lss \

FLASH_IMAGE += \
zCA6_testing_sh_register.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: zCA6_testing_sh_register.elf secondary-outputs

# Tool invocations
zCA6_testing_sh_register.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,zCA6_testing_sh_register.map -mmcu=atmega328p -o "zCA6_testing_sh_register.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

zCA6_testing_sh_register.lss: zCA6_testing_sh_register.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S zCA6_testing_sh_register.elf  >"zCA6_testing_sh_register.lss"
	@echo 'Finished building: $@'
	@echo ' '

zCA6_testing_sh_register.hex: zCA6_testing_sh_register.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex zCA6_testing_sh_register.elf  "zCA6_testing_sh_register.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: zCA6_testing_sh_register.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p zCA6_testing_sh_register.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) zCA6_testing_sh_register.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
