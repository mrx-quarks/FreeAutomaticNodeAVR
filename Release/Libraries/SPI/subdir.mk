################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/enrico/Entwicklung/C/tools/arduino-1.5.5/hardware/arduino/avr/libraries/SPI/SPI.cpp 

CPP_DEPS += \
./Libraries/SPI/SPI.cpp.d 

LINK_OBJ += \
./Libraries/SPI/SPI.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/SPI/SPI.cpp.o: /home/enrico/Entwicklung/C/tools/arduino-1.5.5/hardware/arduino/avr/libraries/SPI/SPI.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/enrico/Entwicklung/C/tools/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


