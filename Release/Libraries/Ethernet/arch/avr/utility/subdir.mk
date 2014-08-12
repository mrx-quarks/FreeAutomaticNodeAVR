################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/enrico/Entwicklung/C/tools/arduino-1.5.5/libraries/Ethernet/arch/avr/utility/socket.cpp \
/home/enrico/Entwicklung/C/tools/arduino-1.5.5/libraries/Ethernet/arch/avr/utility/w5100.cpp 

CPP_DEPS += \
./Libraries/Ethernet/arch/avr/utility/socket.cpp.d \
./Libraries/Ethernet/arch/avr/utility/w5100.cpp.d 

LINK_OBJ += \
./Libraries/Ethernet/arch/avr/utility/socket.cpp.o \
./Libraries/Ethernet/arch/avr/utility/w5100.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Ethernet/arch/avr/utility/socket.cpp.o: /home/enrico/Entwicklung/C/tools/arduino-1.5.5/libraries/Ethernet/arch/avr/utility/socket.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/enrico/Entwicklung/C/tools/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Ethernet/arch/avr/utility/w5100.cpp.o: /home/enrico/Entwicklung/C/tools/arduino-1.5.5/libraries/Ethernet/arch/avr/utility/w5100.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/enrico/Entwicklung/C/tools/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


