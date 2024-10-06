################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/GUIConf.c \
../Core/Src/GUI_X.c \
../Core/Src/LCDConf_FlexColor.c \
../Core/Src/PersonelGecisDLG.c \
../Core/Src/fatfs_sd.c \
../Core/Src/main.c \
../Core/Src/rc522.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_hal_timebase_tim.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/GUIConf.o \
./Core/Src/GUI_X.o \
./Core/Src/LCDConf_FlexColor.o \
./Core/Src/PersonelGecisDLG.o \
./Core/Src/fatfs_sd.o \
./Core/Src/main.o \
./Core/Src/rc522.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_hal_timebase_tim.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/GUIConf.d \
./Core/Src/GUI_X.d \
./Core/Src/LCDConf_FlexColor.d \
./Core/Src/PersonelGecisDLG.d \
./Core/Src/fatfs_sd.d \
./Core/Src/main.d \
./Core/Src/rc522.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_hal_timebase_tim.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../GUI/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/GUIConf.cyclo ./Core/Src/GUIConf.d ./Core/Src/GUIConf.o ./Core/Src/GUIConf.su ./Core/Src/GUI_X.cyclo ./Core/Src/GUI_X.d ./Core/Src/GUI_X.o ./Core/Src/GUI_X.su ./Core/Src/LCDConf_FlexColor.cyclo ./Core/Src/LCDConf_FlexColor.d ./Core/Src/LCDConf_FlexColor.o ./Core/Src/LCDConf_FlexColor.su ./Core/Src/PersonelGecisDLG.cyclo ./Core/Src/PersonelGecisDLG.d ./Core/Src/PersonelGecisDLG.o ./Core/Src/PersonelGecisDLG.su ./Core/Src/fatfs_sd.cyclo ./Core/Src/fatfs_sd.d ./Core/Src/fatfs_sd.o ./Core/Src/fatfs_sd.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/rc522.cyclo ./Core/Src/rc522.d ./Core/Src/rc522.o ./Core/Src/rc522.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_hal_timebase_tim.cyclo ./Core/Src/stm32f4xx_hal_timebase_tim.d ./Core/Src/stm32f4xx_hal_timebase_tim.o ./Core/Src/stm32f4xx_hal_timebase_tim.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su

.PHONY: clean-Core-2f-Src

