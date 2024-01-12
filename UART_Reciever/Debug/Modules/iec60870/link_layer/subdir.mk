################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modules/iec60870/link_layer/buffer_frame.c \
../Modules/iec60870/link_layer/link_layer.c \
../Modules/iec60870/link_layer/serial_transceiver_ft_1_2.c 

OBJS += \
./Modules/iec60870/link_layer/buffer_frame.o \
./Modules/iec60870/link_layer/link_layer.o \
./Modules/iec60870/link_layer/serial_transceiver_ft_1_2.o 

C_DEPS += \
./Modules/iec60870/link_layer/buffer_frame.d \
./Modules/iec60870/link_layer/link_layer.d \
./Modules/iec60870/link_layer/serial_transceiver_ft_1_2.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/iec60870/link_layer/%.o Modules/iec60870/link_layer/%.su Modules/iec60870/link_layer/%.cyclo: ../Modules/iec60870/link_layer/%.c Modules/iec60870/link_layer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/M24xx -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/inc/internal" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/inc/api" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/hal/tls/mbedtls" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/hal/inc" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/file-service" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/common/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Modules-2f-iec60870-2f-link_layer

clean-Modules-2f-iec60870-2f-link_layer:
	-$(RM) ./Modules/iec60870/link_layer/buffer_frame.cyclo ./Modules/iec60870/link_layer/buffer_frame.d ./Modules/iec60870/link_layer/buffer_frame.o ./Modules/iec60870/link_layer/buffer_frame.su ./Modules/iec60870/link_layer/link_layer.cyclo ./Modules/iec60870/link_layer/link_layer.d ./Modules/iec60870/link_layer/link_layer.o ./Modules/iec60870/link_layer/link_layer.su ./Modules/iec60870/link_layer/serial_transceiver_ft_1_2.cyclo ./Modules/iec60870/link_layer/serial_transceiver_ft_1_2.d ./Modules/iec60870/link_layer/serial_transceiver_ft_1_2.o ./Modules/iec60870/link_layer/serial_transceiver_ft_1_2.su

.PHONY: clean-Modules-2f-iec60870-2f-link_layer

