################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/STM32F4xx_StdPeriph_Driver/src/misc.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_adc.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_can.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_crc.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_aes.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_des.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_tdes.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dac.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dbgmcu.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dcmi.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_exti.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_flash.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_fsmc.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_md5.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_sha1.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_i2c.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_iwdg.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_pwr.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rng.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rtc.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_sdio.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_spi.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_syscfg.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_tim.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_usart.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_wwdg.c 

OBJS += \
./Libraries/STM32F4xx_StdPeriph_Driver/src/misc.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_adc.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_can.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_crc.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_aes.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_des.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_tdes.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dac.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dbgmcu.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dcmi.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_exti.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_flash.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_fsmc.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_md5.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_sha1.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_i2c.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_iwdg.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_pwr.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rng.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rtc.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_sdio.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_spi.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_syscfg.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_tim.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_usart.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_wwdg.o 

C_DEPS += \
./Libraries/STM32F4xx_StdPeriph_Driver/src/misc.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_adc.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_can.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_crc.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_aes.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_des.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_tdes.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dac.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dbgmcu.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dcmi.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_exti.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_flash.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_fsmc.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_md5.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_sha1.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_i2c.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_iwdg.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_pwr.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rng.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rtc.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_sdio.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_spi.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_syscfg.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_tim.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_usart.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/STM32F4xx_StdPeriph_Driver/src/%.o Libraries/STM32F4xx_StdPeriph_Driver/src/%.su Libraries/STM32F4xx_StdPeriph_Driver/src/%.cyclo: ../Libraries/STM32F4xx_StdPeriph_Driver/src/%.c Libraries/STM32F4xx_StdPeriph_Driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F4XX -DSTM32F40XX -DUSE_STDPERIPH_DRIVER -DUSE_STM32F4_DISCOVERY -DHSE_VALUE=8000000 -c -I../src -I../Libraries/CMSIS/Include -I../Libraries/Device/STM32F4xx/Include -I../Libraries/STM32F4xx_StdPeriph_Driver/inc -I../Utilities/STM32F4-Discovery -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Libraries-2f-STM32F4xx_StdPeriph_Driver-2f-src

clean-Libraries-2f-STM32F4xx_StdPeriph_Driver-2f-src:
	-$(RM) ./Libraries/STM32F4xx_StdPeriph_Driver/src/misc.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/misc.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/misc.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/misc.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_adc.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_adc.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_adc.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_adc.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_can.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_can.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_can.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_can.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_crc.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_crc.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_crc.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_crc.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_aes.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_aes.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_aes.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_aes.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_des.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_des.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_des.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_des.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_tdes.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_tdes.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_tdes.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_tdes.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dac.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dac.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dac.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dac.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dbgmcu.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dbgmcu.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dbgmcu.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dbgmcu.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dcmi.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dcmi.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dcmi.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dcmi.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_exti.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_exti.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_exti.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_exti.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_flash.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_flash.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_flash.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_flash.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_fsmc.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_fsmc.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_fsmc.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_fsmc.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_md5.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_md5.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_md5.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_md5.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_sha1.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_sha1.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_sha1.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_sha1.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_i2c.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_i2c.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_i2c.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_i2c.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_iwdg.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_iwdg.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_iwdg.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_iwdg.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_pwr.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_pwr.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_pwr.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_pwr.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rng.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rng.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rng.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rng.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rtc.cyclo
	-$(RM) ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rtc.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rtc.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rtc.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_sdio.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_sdio.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_sdio.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_sdio.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_spi.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_spi.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_spi.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_spi.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_syscfg.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_syscfg.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_syscfg.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_syscfg.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_tim.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_tim.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_tim.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_tim.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_usart.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_usart.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_usart.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_usart.su ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_wwdg.cyclo ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_wwdg.d ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_wwdg.o ./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_wwdg.su

.PHONY: clean-Libraries-2f-STM32F4xx_StdPeriph_Driver-2f-src

