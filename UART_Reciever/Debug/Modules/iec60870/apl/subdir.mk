################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modules/iec60870/apl/cpXXtime2a.c 

OBJS += \
./Modules/iec60870/apl/cpXXtime2a.o 

C_DEPS += \
./Modules/iec60870/apl/cpXXtime2a.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/iec60870/apl/%.o Modules/iec60870/apl/%.su Modules/iec60870/apl/%.cyclo: ../Modules/iec60870/apl/%.c Modules/iec60870/apl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/M24xx -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/inc/internal" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/inc/api" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/hal/tls/mbedtls" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/hal/inc" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/file-service" -I"D:/STM32CubeIDE_1.7.0/Workspace/UART_Reciever/Modules/iec60870/common/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Modules-2f-iec60870-2f-apl

clean-Modules-2f-iec60870-2f-apl:
	-$(RM) ./Modules/iec60870/apl/cpXXtime2a.cyclo ./Modules/iec60870/apl/cpXXtime2a.d ./Modules/iec60870/apl/cpXXtime2a.o ./Modules/iec60870/apl/cpXXtime2a.su

.PHONY: clean-Modules-2f-iec60870-2f-apl

