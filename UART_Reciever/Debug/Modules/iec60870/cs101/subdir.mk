################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modules/iec60870/cs101/cs101_asdu.c \
../Modules/iec60870/cs101/cs101_bcr.c \
../Modules/iec60870/cs101/cs101_information_objects.c \
../Modules/iec60870/cs101/cs101_master.c \
../Modules/iec60870/cs101/cs101_master_connection.c \
../Modules/iec60870/cs101/cs101_queue.c \
../Modules/iec60870/cs101/cs101_slave.c 

OBJS += \
./Modules/iec60870/cs101/cs101_asdu.o \
./Modules/iec60870/cs101/cs101_bcr.o \
./Modules/iec60870/cs101/cs101_information_objects.o \
./Modules/iec60870/cs101/cs101_master.o \
./Modules/iec60870/cs101/cs101_master_connection.o \
./Modules/iec60870/cs101/cs101_queue.o \
./Modules/iec60870/cs101/cs101_slave.o 

C_DEPS += \
./Modules/iec60870/cs101/cs101_asdu.d \
./Modules/iec60870/cs101/cs101_bcr.d \
./Modules/iec60870/cs101/cs101_information_objects.d \
./Modules/iec60870/cs101/cs101_master.d \
./Modules/iec60870/cs101/cs101_master_connection.d \
./Modules/iec60870/cs101/cs101_queue.d \
./Modules/iec60870/cs101/cs101_slave.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/iec60870/cs101/%.o Modules/iec60870/cs101/%.su Modules/iec60870/cs101/%.cyclo: ../Modules/iec60870/cs101/%.c Modules/iec60870/cs101/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/M24xx -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/inc/internal" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/inc/api" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/hal/tls/mbedtls" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/hal/inc" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/file-service" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/common/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Modules-2f-iec60870-2f-cs101

clean-Modules-2f-iec60870-2f-cs101:
	-$(RM) ./Modules/iec60870/cs101/cs101_asdu.cyclo ./Modules/iec60870/cs101/cs101_asdu.d ./Modules/iec60870/cs101/cs101_asdu.o ./Modules/iec60870/cs101/cs101_asdu.su ./Modules/iec60870/cs101/cs101_bcr.cyclo ./Modules/iec60870/cs101/cs101_bcr.d ./Modules/iec60870/cs101/cs101_bcr.o ./Modules/iec60870/cs101/cs101_bcr.su ./Modules/iec60870/cs101/cs101_information_objects.cyclo ./Modules/iec60870/cs101/cs101_information_objects.d ./Modules/iec60870/cs101/cs101_information_objects.o ./Modules/iec60870/cs101/cs101_information_objects.su ./Modules/iec60870/cs101/cs101_master.cyclo ./Modules/iec60870/cs101/cs101_master.d ./Modules/iec60870/cs101/cs101_master.o ./Modules/iec60870/cs101/cs101_master.su ./Modules/iec60870/cs101/cs101_master_connection.cyclo ./Modules/iec60870/cs101/cs101_master_connection.d ./Modules/iec60870/cs101/cs101_master_connection.o ./Modules/iec60870/cs101/cs101_master_connection.su ./Modules/iec60870/cs101/cs101_queue.cyclo ./Modules/iec60870/cs101/cs101_queue.d ./Modules/iec60870/cs101/cs101_queue.o ./Modules/iec60870/cs101/cs101_queue.su ./Modules/iec60870/cs101/cs101_slave.cyclo ./Modules/iec60870/cs101/cs101_slave.d ./Modules/iec60870/cs101/cs101_slave.o ./Modules/iec60870/cs101/cs101_slave.su

.PHONY: clean-Modules-2f-iec60870-2f-cs101

