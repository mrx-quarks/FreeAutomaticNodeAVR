################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Examples/FreeAutomaticNode.cpp \
../Examples/NodeEtherImplTest.cpp \
../Examples/NodeRF24ImplTest.cpp 

CPP_DEPS += \
./Examples/FreeAutomaticNode.cpp.d \
./Examples/NodeEtherImplTest.cpp.d \
./Examples/NodeRF24ImplTest.cpp.d 

LINK_OBJ += \
./Examples/FreeAutomaticNode.cpp.o \
./Examples/NodeEtherImplTest.cpp.o \
./Examples/NodeRF24ImplTest.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
Examples/FreeAutomaticNode.cpp.o: ../Examples/FreeAutomaticNode.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/enrico/Entwicklung/C/tools/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Examples/NodeEtherImplTest.cpp.o: ../Examples/NodeEtherImplTest.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/enrico/Entwicklung/C/tools/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Examples/NodeRF24ImplTest.cpp.o: ../Examples/NodeRF24ImplTest.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/enrico/Entwicklung/C/tools/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


