################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../src/portASM.S 

C_SRCS += \
../src/croutine.c \
../src/heap_4.c \
../src/list.c \
../src/main.c \
../src/port.c \
../src/queue.c \
../src/stream_buffer.c \
../src/tasks.c \
../src/timers.c 

CREF += \
freertos_port.cref 

C_DEPS += \
./src/croutine.d \
./src/heap_4.d \
./src/list.d \
./src/main.d \
./src/port.d \
./src/queue.d \
./src/stream_buffer.d \
./src/tasks.d \
./src/timers.d 

OBJS += \
./src/croutine.o \
./src/heap_4.o \
./src/list.o \
./src/main.o \
./src/port.o \
./src/portASM.o \
./src/queue.o \
./src/stream_buffer.o \
./src/tasks.o \
./src/timers.o 

MAP += \
freertos_port.map 

S_UPPER_DEPS += \
./src/portASM.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	$(file > $@.in,--target=riscv32 -mabi=ilp32 -march=rv32imaczba_zbb_zbs -Og -ffunction-sections -fdata-sections -fdiagnostics-parseable-fixits -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -g -v -I"/home/user0/e2_studio/workspace/freertos_port/src/smc_gen/r_pincfg" -I"/home/user0/e2_studio/workspace/freertos_port/includes/include" -I"/home/user0/e2_studio/workspace/freertos_port/src/smc_gen/r_bsp/mcu/r9a02g021/register_access/llvm" -I"/home/user0/e2_studio/workspace/freertos_port/src/smc_gen/Config_ICU" -I"/home/user0/e2_studio/workspace/freertos_port/src/smc_gen/Config_PORT" -I"/home/user0/e2_studio/workspace/freertos_port/src/smc_gen/general" -I"/home/user0/e2_studio/workspace/freertos_port/src/smc_gen/r_config" -I"/home/user0/e2_studio/workspace/freertos_port/src/smc_gen/r_bsp" -I"/home/user0/e2_studio/workspace/freertos_port/FreeRTOSConfig" -I"/home/user0/e2_studio/workspace/freertos_port/portable/GCC/RISC-V/chip_specific_extensions/RISCV_no_extensions" -I"/home/user0/e2_studio/workspace/freertos_port/portable/GCC/RISC-V" -I"/home/user0/e2_studio/workspace/freertos_port/portable/GCC" -I"/home/user0/e2_studio/workspace/freertos_port/portable/GCC/RISC-V/chip_specific_extensions/RV32I_CLINT_no_extensions" -I"/home/user0/e2_studio/workspace/freertos_port/portable" -I"/home/user0/e2_studio/workspace/freertos_port/portable/GCC/RISC-V/chip_specific_extensions" -I"/home/user0/e2_studio/workspace/freertos_port/portable/GCC/RISC-V/chip_specific_extensions/RISCV_MTIME_CLINT_no_extensions" -I"/home/user0/e2_studio/workspace/freertos_port/portable/GCC/RISC-V/chip_specific_extensions/Pulpino_Vega_RV32M1RM" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" "$<" -c -o "$@")
	@clang @"$@.in"
src/%.o: ../src/%.S
	@echo 'Building file: $<'
	$(file > $@.in,--target=riscv32 -mabi=ilp32 -march=rv32imaczba_zbb_zbs -Og -ffunction-sections -fdata-sections -fdiagnostics-parseable-fixits -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -g -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c "$<" -o "$@")
	@clang @"$@.in"

