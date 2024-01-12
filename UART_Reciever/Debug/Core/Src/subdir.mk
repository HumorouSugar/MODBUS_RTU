################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/main.c \
../Core/Src/mb.c \
../Core/Src/mbascii.c \
../Core/Src/mbcrc.c \
../Core/Src/mbfunccoils.c \
../Core/Src/mbfuncdiag.c \
../Core/Src/mbfuncdisc.c \
../Core/Src/mbfuncholding.c \
../Core/Src/mbfuncinput.c \
../Core/Src/mbfuncother.c \
../Core/Src/mbrtu.c \
../Core/Src/mbtcp.c \
../Core/Src/mbutils.c \
../Core/Src/mt_port.c \
../Core/Src/portevent.c \
../Core/Src/portserial.c \
../Core/Src/porttimer.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/main.o \
./Core/Src/mb.o \
./Core/Src/mbascii.o \
./Core/Src/mbcrc.o \
./Core/Src/mbfunccoils.o \
./Core/Src/mbfuncdiag.o \
./Core/Src/mbfuncdisc.o \
./Core/Src/mbfuncholding.o \
./Core/Src/mbfuncinput.o \
./Core/Src/mbfuncother.o \
./Core/Src/mbrtu.o \
./Core/Src/mbtcp.o \
./Core/Src/mbutils.o \
./Core/Src/mt_port.o \
./Core/Src/portevent.o \
./Core/Src/portserial.o \
./Core/Src/porttimer.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/main.d \
./Core/Src/mb.d \
./Core/Src/mbascii.d \
./Core/Src/mbcrc.d \
./Core/Src/mbfunccoils.d \
./Core/Src/mbfuncdiag.d \
./Core/Src/mbfuncdisc.d \
./Core/Src/mbfuncholding.d \
./Core/Src/mbfuncinput.d \
./Core/Src/mbfuncother.d \
./Core/Src/mbrtu.d \
./Core/Src/mbtcp.d \
./Core/Src/mbutils.d \
./Core/Src/mt_port.d \
./Core/Src/portevent.d \
./Core/Src/portserial.d \
./Core/Src/porttimer.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/M24xx -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/inc/internal" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/inc/api" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/hal/tls/mbedtls" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/hal/inc" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/file-service" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/common/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/mb.cyclo ./Core/Src/mb.d ./Core/Src/mb.o ./Core/Src/mb.su ./Core/Src/mbascii.cyclo ./Core/Src/mbascii.d ./Core/Src/mbascii.o ./Core/Src/mbascii.su ./Core/Src/mbcrc.cyclo ./Core/Src/mbcrc.d ./Core/Src/mbcrc.o ./Core/Src/mbcrc.su ./Core/Src/mbfunccoils.cyclo ./Core/Src/mbfunccoils.d ./Core/Src/mbfunccoils.o ./Core/Src/mbfunccoils.su ./Core/Src/mbfuncdiag.cyclo ./Core/Src/mbfuncdiag.d ./Core/Src/mbfuncdiag.o ./Core/Src/mbfuncdiag.su ./Core/Src/mbfuncdisc.cyclo ./Core/Src/mbfuncdisc.d ./Core/Src/mbfuncdisc.o ./Core/Src/mbfuncdisc.su ./Core/Src/mbfuncholding.cyclo ./Core/Src/mbfuncholding.d ./Core/Src/mbfuncholding.o ./Core/Src/mbfuncholding.su ./Core/Src/mbfuncinput.cyclo ./Core/Src/mbfuncinput.d ./Core/Src/mbfuncinput.o ./Core/Src/mbfuncinput.su ./Core/Src/mbfuncother.cyclo ./Core/Src/mbfuncother.d ./Core/Src/mbfuncother.o ./Core/Src/mbfuncother.su ./Core/Src/mbrtu.cyclo ./Core/Src/mbrtu.d ./Core/Src/mbrtu.o ./Core/Src/mbrtu.su ./Core/Src/mbtcp.cyclo ./Core/Src/mbtcp.d ./Core/Src/mbtcp.o ./Core/Src/mbtcp.su ./Core/Src/mbutils.cyclo ./Core/Src/mbutils.d ./Core/Src/mbutils.o ./Core/Src/mbutils.su ./Core/Src/mt_port.cyclo ./Core/Src/mt_port.d ./Core/Src/mt_port.o ./Core/Src/mt_port.su ./Core/Src/portevent.cyclo ./Core/Src/portevent.d ./Core/Src/portevent.o ./Core/Src/portevent.su ./Core/Src/portserial.cyclo ./Core/Src/portserial.d ./Core/Src/portserial.o ./Core/Src/portserial.su ./Core/Src/porttimer.cyclo ./Core/Src/porttimer.d ./Core/Src/porttimer.o ./Core/Src/porttimer.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su

.PHONY: clean-Core-2f-Src

