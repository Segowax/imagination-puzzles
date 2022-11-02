################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Helpers/buttons.c \
../Helpers/custom_functions.c \
../Helpers/led_display.c \
../Helpers/leds.c 

OBJS += \
./Helpers/buttons.o \
./Helpers/custom_functions.o \
./Helpers/led_display.o \
./Helpers/leds.o 

C_DEPS += \
./Helpers/buttons.d \
./Helpers/custom_functions.d \
./Helpers/led_display.d \
./Helpers/leds.d 


# Each subdirectory must supply rules for building sources it contributes
Helpers/%.o: ../Helpers/%.c Helpers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


