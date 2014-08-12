################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/enrico/Entwicklung/C/tools/arduino-1.5.5/libraries/Ethernet/src/Dhcp.cpp \
/home/enrico/Entwicklung/C/tools/arduino-1.5.5/libraries/Ethernet/src/Dns.cpp \
/home/enrico/Entwicklung/C/tools/arduino-1.5.5/libraries/Ethernet/src/Ethernet.cpp \
/home/enrico/Entwicklung/C/tools/arduino-1.5.5/libraries/Ethernet/src/EthernetClient.cpp \
/home/enrico/Entwicklung/C/tools/arduino-1.5.5/libraries/Ethernet/src/EthernetServer.cpp \
/home/enrico/Entwicklung/C/tools/arduino-1.5.5/libraries/Ethernet/src/EthernetUdp.cpp 

CPP_DEPS += \
./Libraries/Ethernet/src/Dhcp.cpp.d \
./Libraries/Ethernet/src/Dns.cpp.d \
./Libraries/Ethernet/src/Ethernet.cpp.d \
./Libraries/Ethernet/src/EthernetClient.cpp.d \
./Libraries/Ethernet/src/EthernetServer.cpp.d \
./Libraries/Ethernet/src/EthernetUdp.cpp.d 

LINK_OBJ += \
./Libraries/Ethernet/src/Dhcp.cpp.o \
./Libraries/Ethernet/src/Dns.cpp.o \
./Libraries/Ethernet/src/Ethernet.cpp.o \
./Libraries/Ethernet/src/EthernetClient.cpp.o \
./Libraries/Ethernet/src/EthernetServer.cpp.o \
./Libraries/Ethernet/src/EthernetUdp.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Ethernet/src/Dhcp.cpp.o: /home/enrico/Entwicklung/C/tools/arduino-1.5.5/libraries/Ethernet/src/Dhcp.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/enrico/Entwicklung/C/tools/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Ethernet/src/Dns.cpp.o: /home/enrico/Entwicklung/C/tools/arduino-1.5.5/libraries/Ethernet/src/Dns.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/enrico/Entwicklung/C/tools/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Ethernet/src/Ethernet.cpp.o: /home/enrico/Entwicklung/C/tools/arduino-1.5.5/libraries/Ethernet/src/Ethernet.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/enrico/Entwicklung/C/tools/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Ethernet/src/EthernetClient.cpp.o: /home/enrico/Entwicklung/C/tools/arduino-1.5.5/libraries/Ethernet/src/EthernetClient.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/enrico/Entwicklung/C/tools/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Ethernet/src/EthernetServer.cpp.o: /home/enrico/Entwicklung/C/tools/arduino-1.5.5/libraries/Ethernet/src/EthernetServer.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/enrico/Entwicklung/C/tools/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Ethernet/src/EthernetUdp.cpp.o: /home/enrico/Entwicklung/C/tools/arduino-1.5.5/libraries/Ethernet/src/EthernetUdp.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/enrico/Entwicklung/C/tools/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


