################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/smc_gen/r_pincfg/Pin.c 

CREF += \
freertos_port.cref 

C_DEPS += \
./src/smc_gen/r_pincfg/Pin.d 

OBJS += \
./src/smc_gen/r_pincfg/Pin.o 

MAP += \
freertos_port.map 


# Each subdirectory must supply rules for building sources it contributes
src/smc_gen/r_pincfg/%.o: ../src/smc_gen/r_pincfg/%.c
	@echo 'Building file: $<'
	$(file > $@.in,--target=riscv32 -mabi=ilp32 -march=rv32imaczba_zbb_zbs -Og -ffunction-sections -fdata-sections -fdiagnostics-parseable-fixits -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -g -v -I"/home/user0/e2_studio/workspace/freertos_port/src/smc_gen/r_pincfg" -I"/home/user0/e2_studio/workspace/freertos_port/includes/include" -I"/home/user0/e2_studio/workspace/freertos_port/src/smc_gen/r_bsp/mcu/r9a02g021/register_access/llvm" -I"/home/user0/e2_studio/workspace/freertos_port/src/smc_gen/Config_ICU" -I"/home/user0/e2_studio/workspace/freertos_port/src/smc_gen/Config_PORT" -I"/home/user0/e2_studio/workspace/freertos_port/src/smc_gen/general" -I"/home/user0/e2_studio/workspace/freertos_port/src/smc_gen/r_config" -I"/home/user0/e2_studio/workspace/freertos_port/src/smc_gen/r_bsp" -I"/home/user0/e2_studio/workspace/freertos_port/FreeRTOSConfig" -I"/home/user0/e2_studio/workspace/freertos_port/portable/GCC/RISC-V/chip_specific_extensions/RISCV_no_extensions" -I"/home/user0/e2_studio/workspace/freertos_port/portable/GCC/RISC-V" -I"/home/user0/e2_studio/workspace/freertos_port/portable/GCC" -I"/home/user0/e2_studio/workspace/freertos_port/portable/GCC/RISC-V/chip_specific_extensions/RV32I_CLINT_no_extensions" -I"/home/user0/e2_studio/workspace/freertos_port/portable" -I"/home/user0/e2_studio/workspace/freertos_port/portable/GCC/RISC-V/chip_specific_extensions" -I"/home/user0/e2_studio/workspace/freertos_port/portable/GCC/RISC-V/chip_specific_extensions/RISCV_MTIME_CLINT_no_extensions" -I"/home/user0/e2_studio/workspace/freertos_port/portable/GCC/RISC-V/chip_specific_extensions/Pulpino_Vega_RV32M1RM" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" "$<" -c -o "$@")
	@clang @"$@.in"

