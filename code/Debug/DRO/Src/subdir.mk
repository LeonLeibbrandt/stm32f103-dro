################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DRO/Src/buttons.c \
../DRO/Src/calipers.c \
../DRO/Src/fonts.c \
../DRO/Src/ssd1306_i2c.c 

C_DEPS += \
./DRO/Src/buttons.d \
./DRO/Src/calipers.d \
./DRO/Src/fonts.d \
./DRO/Src/ssd1306_i2c.d 

OBJS += \
./DRO/Src/buttons.o \
./DRO/Src/calipers.o \
./DRO/Src/fonts.o \
./DRO/Src/ssd1306_i2c.o 


# Each subdirectory must supply rules for building sources it contributes
DRO/Src/%.o DRO/Src/%.su: ../DRO/Src/%.c DRO/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"/home/leonl/Projects/dro/code/DRO/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-DRO-2f-Src

clean-DRO-2f-Src:
	-$(RM) ./DRO/Src/buttons.d ./DRO/Src/buttons.o ./DRO/Src/buttons.su ./DRO/Src/calipers.d ./DRO/Src/calipers.o ./DRO/Src/calipers.su ./DRO/Src/fonts.d ./DRO/Src/fonts.o ./DRO/Src/fonts.su ./DRO/Src/ssd1306_i2c.d ./DRO/Src/ssd1306_i2c.o ./DRO/Src/ssd1306_i2c.su

.PHONY: clean-DRO-2f-Src

