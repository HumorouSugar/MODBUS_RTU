/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "mb.h"
#include "mbport.h"
#include "mt_port.h"
#include "errno.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define REG_INPUT_START 100
#define REG_INPUT_NREGS 8

#define REG_COILS_START 5
#define REG_COILS_NREGS 9

#define REG_DISCRETE_START 200
#define REG_DISCRETE_NREGS 8

#define REG_HOLDING_START 10
#define REG_HOLDING_NREGS 7
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
RTC_HandleTypeDef hrtc;

TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
extern __IO uint32_t uwTick;
static USHORT usRegInputStart = REG_INPUT_START;
static USHORT usRegInputBuf[REG_INPUT_NREGS] = {'M', 'o', 'd', 'b', 'u', 's', 0, 0};

static UCHAR usRegCoilStart = REG_COILS_START;
static UCHAR usRegCoilBuf[REG_DISCRETE_NREGS] = {0,0,0,0,0,0,0,0};

static UCHAR usRegDiscreteStart = REG_DISCRETE_START;
static UCHAR usRegDiscreteBuf[REG_DISCRETE_NREGS] = {0,0,0,0,0,0,0,0};

static USHORT usRegHoldingStart = REG_HOLDING_START;
static USHORT usRegHoldingBuf[REG_HOLDING_NREGS] = {0,0,0,0,0,0,0};
int a = 0;
//char argv[20];
uint8_t argv[2];
uint32_t argc;

RTC_TimeTypeDef sTime;
RTC_DateTypeDef sDate;
uint8_t rdy_set_time = 0;
//static bool running = true;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_TIM3_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_RTC_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_TIM3_Init();
  MX_USART2_UART_Init();
  MX_RTC_Init();
  /* USER CODE BEGIN 2 */
	MT_PORT_SetTimerModule(&htim3);
	MT_PORT_SetUartModule(&huart1);

//	const char* serialPort = "/dev/ttyUSB0";
//	SerialPort_create(&huart1, 9600, 8, 'E',1);
//	printCP56Time2a(56);
//	SerialPort_destroy(serialPort);
//	 CS101_Slave_run(&htim3);
	eMBErrorCode eStatus;
	eStatus = eMBInit(MB_RTU, 0x0A, 0, 19200, MB_PAR_NONE);
	eStatus = eMBEnable();
	if (eStatus != MB_ENOERR)
	{
		// Error handling
	}

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

	while (1)
	{

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		eMBPoll();
		usRegInputBuf[REG_INPUT_NREGS - 2] =  HAL_GetTick() / 1000;
		usRegInputBuf[REG_INPUT_NREGS - 1] =  HAL_GetTick();
		HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

	}

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef sDate = {0};

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */

  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN Check_RTC_BKUP */

  /* USER CODE END Check_RTC_BKUP */

  /** Initialize RTC and set the Time and Date
  */
  sTime.Hours = 14;
  sTime.Minutes = 52;
  sTime.Seconds = 0;
  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  sTime.StoreOperation = RTC_STOREOPERATION_RESET;
  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  sDate.WeekDay = RTC_WEEKDAY_THURSDAY;
  sDate.Month = RTC_MONTH_JANUARY;
  sDate.Date = 11;
  sDate.Year = 24;

  if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 83;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 50;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 19200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA4 PA5 PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);

  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	usRegDiscreteBuf[0] = 0;
	usRegDiscreteBuf[1] = (GPIOA->IDR & GPIO_IDR_ID4) >> 4;
	usRegDiscreteBuf[2] = (GPIOA->IDR & GPIO_IDR_ID5) >> 5;
	usRegDiscreteBuf[3] = (GPIOA->IDR & GPIO_IDR_ID6) >> 6;
	usRegDiscreteBuf[4] = (GPIOA->IDR & GPIO_IDR_ID7) >> 7;
	usRegDiscreteBuf[5] = (GPIOB->IDR & GPIO_IDR_ID0);
	usRegDiscreteBuf[6] = (GPIOB->IDR & GPIO_IDR_ID1) >> 1;
	usRegDiscreteBuf[7] = (GPIOB->IDR & GPIO_IDR_ID2) >> 2;
	a = ((GPIOB->IDR & GPIO_IDR_ID0) | (GPIOB->IDR & GPIO_IDR_ID1) | (GPIOB->IDR & GPIO_IDR_ID2) | (GPIOA->IDR & GPIO_IDR_ID3)
| (GPIOA->IDR & GPIO_IDR_ID4) | (GPIOA->IDR & GPIO_IDR_ID5) | (GPIOA->IDR & GPIO_IDR_ID6) | (GPIOA->IDR & GPIO_IDR_ID7));
}
/*----------------------------------------------------------------------------*/
eMBErrorCode eMBRegInputCB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs)
{
	return MB_ENOREG;
}



/*----------------------------------------------------------------------------*/
eMBErrorCode eMBRegHoldingCB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs,
		eMBRegisterMode eMode)
{
	eMBErrorCode eStatus = MB_ENOERR;
	short iNRegs = ( short )usNRegs;
	int iRegIndex = 0;

	if(( usAddress >= REG_HOLDING_START ) &&( usAddress + usNRegs <= REG_HOLDING_START + REG_HOLDING_NREGS ))
	{
		iRegIndex = (int)(usAddress - usRegHoldingStart);
		switch ( eMode )
		{
		case MB_REG_READ:
			usRegHoldingBuf[REG_HOLDING_NREGS - 7] = sDate.Year;
			usRegHoldingBuf[REG_HOLDING_NREGS - 6] = sDate.Month;
			usRegHoldingBuf[REG_HOLDING_NREGS - 5] = sDate.Date;
			usRegHoldingBuf[REG_HOLDING_NREGS - 4] = sTime.Hours;
			usRegHoldingBuf[REG_HOLDING_NREGS - 3] = sTime.Minutes;
			usRegHoldingBuf[REG_HOLDING_NREGS - 2] = sTime.Seconds;
			usRegHoldingBuf[REG_HOLDING_NREGS - 1] = ((sTime.Seconds)*1000) + (999 - ((sTime.SubSeconds)*3.91)+3);
			while(iNRegs > 0)
			{
				*pucRegBuffer++ = (usRegHoldingBuf[iRegIndex] >> 8);
				*pucRegBuffer++ = (usRegHoldingBuf[iRegIndex] & 0xFF);

				iRegIndex++;
				iNRegs--;
			}
		case MB_REG_WRITE:
			while( iNRegs > 0 )
			{
				usRegHoldingBuf[iRegIndex] = *pucRegBuffer++ << 8;
				usRegHoldingBuf[iRegIndex] |= *pucRegBuffer++;
				iRegIndex++;
				iNRegs--;
				rdy_set_time = 1;
			}
			if(rdy_set_time == 1)
			{
				__HAL_RTC_WRITEPROTECTION_DISABLE(&hrtc);
				sTime.Hours = usRegHoldingBuf[REG_HOLDING_NREGS - 4];
				sTime.Minutes = usRegHoldingBuf[REG_HOLDING_NREGS - 3];
				sTime.Seconds = usRegHoldingBuf[REG_HOLDING_NREGS - 2];
				sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
				sTime.StoreOperation = RTC_STOREOPERATION_RESET;
				if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
				{
					Error_Handler();
				}
				sDate.WeekDay = RTC_WEEKDAY_THURSDAY;
				sDate.Date = usRegHoldingBuf[REG_HOLDING_NREGS - 5];
				sDate.Month = usRegHoldingBuf[REG_HOLDING_NREGS - 6];
				sDate.Year = usRegHoldingBuf[REG_HOLDING_NREGS - 7];

				if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
				{
					Error_Handler();
				}
				__HAL_RTC_WRITEPROTECTION_ENABLE(&hrtc);
				rdy_set_time = 0;
			}
			break;
		}
	}
	else
	{
		eStatus = MB_ENOREG;
	}
	return eStatus;
}



/*----------------------------------------------------------------------------*/
eMBErrorCode eMBRegCoilsCB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils,
		eMBRegisterMode eMode)
{

	eMBErrorCode    eStatus = MB_ENOERR;
	short           iNCoils = ( short )usNCoils;
	int iRegIndex = 0;

	if( ( usAddress >= REG_COILS_START ) &&( usAddress + usNCoils <= REG_COILS_START + REG_COILS_NREGS ) )
	{
		iRegIndex = (int)(usAddress - usRegCoilStart);
		switch ( eMode )
		{
		case MB_REG_READ:
			*pucRegBuffer = 0x00;
			while( iNCoils > 0 )
			{
				if (usRegCoilBuf[iRegIndex] != 0x0000)
				{
					*pucRegBuffer |= ( 1 << iRegIndex);
				}

				iRegIndex++;
				iNCoils--;
			}
			break;
		case MB_REG_WRITE:
			while( iNCoils > 0 )
			{
				usRegCoilBuf[iRegIndex] = *pucRegBuffer++;
				usRegCoilBuf[iRegIndex] |= *pucRegBuffer++ << 8;
				iRegIndex++;
				iNCoils--;
			}
			break;
		}
	}
	else
	{
		eStatus = MB_ENOREG;
	}
	return eStatus;
}



/*----------------------------------------------------------------------------*/
eMBErrorCode eMBRegDiscreteCB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete)
{
	eMBErrorCode    eStatus = MB_ENOERR;
	short           iNCoils = ( short )usNDiscrete;
	int iRegIndex = 0;

	if( ( usAddress >= REG_DISCRETE_START ) &&( usAddress + usNDiscrete <= REG_DISCRETE_START + REG_DISCRETE_NREGS ) )
	{
		iRegIndex = (int)(usAddress - usRegDiscreteStart);
		*pucRegBuffer = 0x00;
		while( iNCoils > 0 )
		{
			if (usRegDiscreteBuf[iRegIndex] != 0x0000)
			{
				*pucRegBuffer |= ( 1 << iRegIndex);
			}

			iRegIndex++;
			iNCoils--;
		}
	}
	else
	{
		eStatus = MB_ENOREG;
	}
	return eStatus;

}

/*----------------------------------------------------------------------------*/

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
