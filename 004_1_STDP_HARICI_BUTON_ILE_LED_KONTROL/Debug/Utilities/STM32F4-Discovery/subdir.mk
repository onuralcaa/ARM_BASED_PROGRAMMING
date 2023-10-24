################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/STM32F4-Discovery/stm32f4_discovery.c \
../Utilities/STM32F4-Discovery/stm32f4_discovery_audio_codec.c \
../Utilities/STM32F4-Discovery/stm32f4_discovery_lis302dl.c 

OBJS += \
./Utilities/STM32F4-Discovery/stm32f4_discovery.o \
./Utilities/STM32F4-Discovery/stm32f4_discovery_audio_codec.o \
./Utilities/STM32F4-Discovery/stm32f4_discovery_lis302dl.o 

C_DEPS += \
./Utilities/STM32F4-Discovery/stm32f4_discovery.d \
./Utilities/STM32F4-Discovery/stm32f4_discovery_audio_codec.d \
./Utilities/STM32F4-Discovery/stm32f4_discovery_lis302dl.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/STM32F4-Discovery/%.o Utilities/STM32F4-Discovery/%.su Utilities/STM32F4-Discovery/%.cyclo: ../Utilities/STM32F4-Discovery/%.c Utilities/STM32F4-Discovery/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F4XX -DSTM32F40XX -DUSE_STDPERIPH_DRIVER -DUSE_STM32F4_DISCOVERY -DHSE_VALUE=8000000 -c -I../src -I../Libraries/CMSIS/Include -I../Libraries/Device/STM32F4xx/Include -I../Libraries/STM32F4xx_StdPeriph_Driver/inc -I../Utilities/STM32F4-Discovery -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Utilities-2f-STM32F4-2d-Discovery

clean-Utilities-2f-STM32F4-2d-Discovery:
	-$(RM) ./Utilities/STM32F4-Discovery/stm32f4_discovery.cyclo ./Utilities/STM32F4-Discovery/stm32f4_discovery.d ./Utilities/STM32F4-Discovery/stm32f4_discovery.o ./Utilities/STM32F4-Discovery/stm32f4_discovery.su ./Utilities/STM32F4-Discovery/stm32f4_discovery_audio_codec.cyclo ./Utilities/STM32F4-Discovery/stm32f4_discovery_audio_codec.d ./Utilities/STM32F4-Discovery/stm32f4_discovery_audio_codec.o ./Utilities/STM32F4-Discovery/stm32f4_discovery_audio_codec.su ./Utilities/STM32F4-Discovery/stm32f4_discovery_lis302dl.cyclo ./Utilities/STM32F4-Discovery/stm32f4_discovery_lis302dl.d ./Utilities/STM32F4-Discovery/stm32f4_discovery_lis302dl.o ./Utilities/STM32F4-Discovery/stm32f4_discovery_lis302dl.su

.PHONY: clean-Utilities-2f-STM32F4-2d-Discovery

