################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include Utilities/STM32F4-Discovery/subdir.mk
-include Libraries/STM32F4xx_StdPeriph_Driver/src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := 004_1_STDP_HARICI_BUTON_ILE_LED_KONTROL
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
004_1_STDP_HARICI_BUTON_ILE_LED_KONTROL.elf \

MAP_FILES += \
004_1_STDP_HARICI_BUTON_ILE_LED_KONTROL.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
004_1_STDP_HARICI_BUTON_ILE_LED_KONTROL.list \


# All Target
all: main-build

# Main-build Target
main-build: 004_1_STDP_HARICI_BUTON_ILE_LED_KONTROL.elf secondary-outputs

# Tool invocations
004_1_STDP_HARICI_BUTON_ILE_LED_KONTROL.elf 004_1_STDP_HARICI_BUTON_ILE_LED_KONTROL.map: $(OBJS) $(USER_OBJS) ../stm32f4_flash.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "004_1_STDP_HARICI_BUTON_ILE_LED_KONTROL.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"../stm32f4_flash.ld" --specs=nosys.specs -Wl,-Map="004_1_STDP_HARICI_BUTON_ILE_LED_KONTROL.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

004_1_STDP_HARICI_BUTON_ILE_LED_KONTROL.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "004_1_STDP_HARICI_BUTON_ILE_LED_KONTROL.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) 004_1_STDP_HARICI_BUTON_ILE_LED_KONTROL.elf 004_1_STDP_HARICI_BUTON_ILE_LED_KONTROL.list 004_1_STDP_HARICI_BUTON_ILE_LED_KONTROL.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
