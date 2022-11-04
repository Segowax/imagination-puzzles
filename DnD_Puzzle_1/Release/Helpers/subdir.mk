################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Helpers/keys.c \
../Helpers/led_display.c \
../Helpers/leds.c 

OBJS += \
./Helpers/keys.o \
./Helpers/led_display.o \
./Helpers/leds.o 

C_DEPS += \
./Helpers/keys.d \
./Helpers/led_display.d \
./Helpers/leds.d 


# Each subdirectory must supply rules for building sources it contributes
Helpers/%.o: ../Helpers/%.c Helpers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


