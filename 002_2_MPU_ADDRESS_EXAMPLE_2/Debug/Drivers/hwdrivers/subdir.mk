################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/hwdrivers/mpu6050.c \
../Drivers/hwdrivers/sensorDriver.c 

OBJS += \
./Drivers/hwdrivers/mpu6050.o \
./Drivers/hwdrivers/sensorDriver.o 

C_DEPS += \
./Drivers/hwdrivers/mpu6050.d \
./Drivers/hwdrivers/sensorDriver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/hwdrivers/%.o Drivers/hwdrivers/%.su Drivers/hwdrivers/%.cyclo: ../Drivers/hwdrivers/%.c Drivers/hwdrivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/hwdrivers -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-hwdrivers

clean-Drivers-2f-hwdrivers:
	-$(RM) ./Drivers/hwdrivers/mpu6050.cyclo ./Drivers/hwdrivers/mpu6050.d ./Drivers/hwdrivers/mpu6050.o ./Drivers/hwdrivers/mpu6050.su ./Drivers/hwdrivers/sensorDriver.cyclo ./Drivers/hwdrivers/sensorDriver.d ./Drivers/hwdrivers/sensorDriver.o ./Drivers/hwdrivers/sensorDriver.su

.PHONY: clean-Drivers-2f-hwdrivers

