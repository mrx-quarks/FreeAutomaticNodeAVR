################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include arduino/core/avr-libc/subdir.mk
-include arduino/core/subdir.mk
-include RF24/subdir.mk
-include Libraries/Wire/utility/subdir.mk
-include Libraries/Wire/subdir.mk
-include Libraries/SPI/subdir.mk
-include Libraries/Ethernet/src/subdir.mk
-include Libraries/Ethernet/arch/avr/utility/subdir.mk
-include Examples/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
/home/enrico/Entwicklung/C/ProjekteArduino/FreeAutomaticNodeAvr/Release/arduino.ar \

ELF += \
FreeAutomaticNodeAvr.elf \

EEP += \
FreeAutomaticNodeAvr.eep \

FLASH_IMAGE += \
FreeAutomaticNodeAvr.hex \


# All Target
all: FreeAutomaticNodeAvr

# Tool invocations
FreeAutomaticNodeAvr: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/home/enrico/Entwicklung/C/tools/arduino-1.5.5/hardware/tools/avr/bin/avr-size" -A "/home/enrico/Entwicklung/C/ProjekteArduino/FreeAutomaticNodeAvr/Release/FreeAutomaticNodeAvr.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/home/enrico/Entwicklung/C/ProjekteArduino/FreeAutomaticNodeAvr/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/home/enrico/Entwicklung/C/tools/arduino-1.5.5/hardware/tools/avr/bin/avr-ar" rcs "/home/enrico/Entwicklung/C/ProjekteArduino/FreeAutomaticNodeAvr/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

FreeAutomaticNodeAvr.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/home/enrico/Entwicklung/C/tools/arduino-1.5.5/hardware/tools/avr/bin/avr-gcc" -Os -Wl,--gc-sections -mmcu=atmega328p -o "/home/enrico/Entwicklung/C/ProjekteArduino/FreeAutomaticNodeAvr/Release/FreeAutomaticNodeAvr.elf"   $(LINK_OBJ) $(AR)  "/home/enrico/Entwicklung/C/ProjekteArduino/FreeAutomaticNodeAvr/Release/arduino.ar" "-L/home/enrico/Entwicklung/C/ProjekteArduino/FreeAutomaticNodeAvr/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

FreeAutomaticNodeAvr.eep: $(ELF)
	@echo 'Create eeprom image'
	"/home/enrico/Entwicklung/C/tools/arduino-1.5.5/hardware/tools/avr/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 "/home/enrico/Entwicklung/C/ProjekteArduino/FreeAutomaticNodeAvr/Release/FreeAutomaticNodeAvr.elf" "/home/enrico/Entwicklung/C/ProjekteArduino/FreeAutomaticNodeAvr/Release/FreeAutomaticNodeAvr.eep"
	@echo 'Finished building: $@'
	@echo ' '

FreeAutomaticNodeAvr.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"/home/enrico/Entwicklung/C/tools/arduino-1.5.5/hardware/tools/avr/bin/avr-objcopy" -O ihex -R .eeprom "/home/enrico/Entwicklung/C/ProjekteArduino/FreeAutomaticNodeAvr/Release/FreeAutomaticNodeAvr.elf" "/home/enrico/Entwicklung/C/ProjekteArduino/FreeAutomaticNodeAvr/Release/FreeAutomaticNodeAvr.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELF)$(C++_DEPS)$(AR)$(C_DEPS)$(CC_DEPS)$(FLASH_IMAGE)$(AR_OBJ)$(CPP_DEPS)$(LINK_OBJ)$(EEP)$(CXX_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) FreeAutomaticNodeAvr
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
