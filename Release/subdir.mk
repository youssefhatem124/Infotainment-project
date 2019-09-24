################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dio.c \
../TIMERS.c \
../TIMERS2.c \
../keypad.c \
../lcd.c \
../main.c \
../os_program.c 

OBJS += \
./Dio.o \
./TIMERS.o \
./TIMERS2.o \
./keypad.o \
./lcd.o \
./main.o \
./os_program.o 

C_DEPS += \
./Dio.d \
./TIMERS.d \
./TIMERS2.d \
./keypad.d \
./lcd.d \
./main.d \
./os_program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


