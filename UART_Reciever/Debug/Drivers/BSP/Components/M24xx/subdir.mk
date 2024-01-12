################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/M24xx/m24xx.c 

OBJS += \
./Drivers/BSP/Components/M24xx/m24xx.o 

C_DEPS += \
./Drivers/BSP/Components/M24xx/m24xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/M24xx/%.o Drivers/BSP/Components/M24xx/%.su Drivers/BSP/Components/M24xx/%.cyclo: ../Drivers/BSP/Components/M24xx/%.c Drivers/BSP/Components/M24xx/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/M24xx -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/inc/internal" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/inc/api" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/hal/tls/mbedtls" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/hal/inc" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/file-service" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/common/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-M24xx

clean-Drivers-2f-BSP-2f-Components-2f-M24xx:
	-$(RM) ./Drivers/BSP/Components/M24xx/m24xx.cyclo ./Drivers/BSP/Components/M24xx/m24xx.d ./Drivers/BSP/Components/M24xx/m24xx.o ./Drivers/BSP/Components/M24xx/m24xx.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-M24xx

