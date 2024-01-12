################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modules/iec60870/hal/serial/win32/iec101_arm_port.c 

OBJS += \
./Modules/iec60870/hal/serial/win32/iec101_arm_port.o 

C_DEPS += \
./Modules/iec60870/hal/serial/win32/iec101_arm_port.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/iec60870/hal/serial/win32/%.o Modules/iec60870/hal/serial/win32/%.su Modules/iec60870/hal/serial/win32/%.cyclo: ../Modules/iec60870/hal/serial/win32/%.c Modules/iec60870/hal/serial/win32/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/M24xx -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/inc/internal" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/inc/api" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/hal/tls/mbedtls" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/hal/inc" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/file-service" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/common/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Modules-2f-iec60870-2f-hal-2f-serial-2f-win32

clean-Modules-2f-iec60870-2f-hal-2f-serial-2f-win32:
	-$(RM) ./Modules/iec60870/hal/serial/win32/iec101_arm_port.cyclo ./Modules/iec60870/hal/serial/win32/iec101_arm_port.d ./Modules/iec60870/hal/serial/win32/iec101_arm_port.o ./Modules/iec60870/hal/serial/win32/iec101_arm_port.su

.PHONY: clean-Modules-2f-iec60870-2f-hal-2f-serial-2f-win32

