/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "adc.h"
#include "eth.h"
#include "fdcan.h"
#include "ltdc.h"
#include "quadspi.h"
#include "rtc.h"
#include "sai.h"
#include "spi.h"
#include "usart.h"
#include "usb_otg.h"
#include "gpio.h"
#include "fmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
// #include <stdio.h>
#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
int Cnt=0;

#define BUFSIZE 256
char SendBuffer[BUFSIZE];

int KeyState=0;

/* CANBUS related */
HAL_StatusTypeDef retval;
uint32_t CanRxMsgCnt = 0;
uint32_t CanTxMsgCnt = 0;

FDCAN_TxHeaderTypeDef TxHeader;
uint8_t TxData[8];
//FDCAN_FilterTypeDef sFilterConfig;

FDCAN_RxHeaderTypeDef RxHeader;
uint8_t RxData[8];

uint32_t CurTimeStamp, lastTime1s;

// ------------------------------------------------------
//          IEX Modules configuration setup
// ------------------------------------------------------


// ------------------------------------------------------

#define CLASS_MASK 0xF0       /* mask for class - command        */
#define DIR_MASK   0x08       /* mask for direction bit  */
#define ARG_MASK   0x07       /* mask for argument       */

#define IEX2_COMMAND_BIT_DATA   0x6000000
#define IEX2_DIRECTION_NODE2RC  0x1000000
#define IEX2_ARGUMENT_SYS_DATA16 0x800000
#define IEX2_ID_SEND_ONBUS_STATUS  (IEX2_COMMAND_BIT_DATA | IEX2_DIRECTION_NODE2RC | IEX2_ARGUMENT_SYS_DATA16)

//----------------------------------------------------------------------------
// S T A R T   O F   G L O B A L    C O N F I G    S E C T I O N

#define NAD_default (long)750				/*!< Defines Node V4 NAD for IEX bus protocol. It could be NAD_v2+27. */
// These are IDs that are reported to IEX master for module identification (read appropriate .cym files)
#define IEX2_CYM_ID     251   // 255 is max, select unique ID, also specified in .cym file

unsigned long status_id = NAD_default +IEX2_ID_SEND_ONBUS_STATUS;
unsigned char status_data[4] = {0,0,0,IEX2_CYM_ID};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/** @brief Prepares D13 ERR data to be sent to TCP server.
 *
  */
uint32_t CANBus_Parse_RX_Message (uint32_t ID,uint32_t msg_size, unsigned char dptr [])
{
  int iex_cmd;
  long iex_NAD;
  int iex_arg;
  int iex_slot;
  uint8_t bitmask, iex_dir, iex_class;
  uint16_t ix_temp;



  iex_cmd = ID >> 21;
  iex_NAD = ID & 0x1fffff;
  iex_arg = iex_cmd & ARG_MASK;
  iex_dir = (iex_cmd & DIR_MASK) >> 3;
  iex_class = (iex_cmd & CLASS_MASK) >> 4 ;

  if ( iex_class != 15) {
	  snprintf (SendBuffer,BUFSIZE,"CAN_RX: Class:%d|Dir:%d|Arg:%d|NAD:%d|Len:%d| 0x%02x %02x %02x %02x\r\n", iex_class, iex_dir, iex_arg, iex_NAD, msg_size,dptr [0],dptr [1],dptr [2],dptr [3]);
	  HAL_UART_Transmit(&huart3,SendBuffer,strlen(SendBuffer),1000);
  }
}

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

/* Configure the peripherals common clocks */
  PeriphCommonClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_ADC3_Init();
  MX_ETH_Init();
  MX_FDCAN1_Init();
  MX_FDCAN2_Init();
  MX_FMC_Init();
  MX_LTDC_Init();
  MX_QUADSPI_Init();
  MX_RTC_Init();
  MX_SAI2_Init();
  MX_SPI2_Init();
  MX_USART3_UART_Init();
  MX_USB_OTG_FS_PCD_Init();
  /* USER CODE BEGIN 2 */


  // Set LEDs
  HAL_GPIO_WritePin(GPIOI, GPIO_PIN_13,0);
  HAL_GPIO_WritePin(GPIOJ, GPIO_PIN_2,0);

  // Welcome message
  snprintf (SendBuffer,BUFSIZE,"\r\nVIN H7 CANBUS IEX Module - Hello!\r\n");
  HAL_UART_Transmit(&huart3,SendBuffer,strlen(SendBuffer),1000);

  // Prepare Tx Header

  //TxHeader.Identifier = 0x15555555;  // 101010...
  TxHeader.Identifier = status_id;
  TxHeader.IdType = FDCAN_EXTENDED_ID;
  TxHeader.TxFrameType = FDCAN_DATA_FRAME;
  //TxHeader.DataLength = FDCAN_DLC_BYTES_2;
  TxHeader.DataLength = FDCAN_DLC_BYTES_4;
  TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
  TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
  TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
  TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
  TxHeader.MessageMarker = 0;

  // TxData[0] = 0xCC;
  // TxData[1] = 0xCC;

  // CAN_SetAllFilter(&hcan1); on STM32F4
  // Start the FDCAN module
  HAL_FDCAN_Start(&hfdcan1);

  lastTime1s = HAL_GetTick();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  //  Check for received CANBUS messages
	  if(HAL_FDCAN_GetRxFifoFillLevel(&hfdcan1, FDCAN_RX_FIFO0) != 0)
	  {

	    retval = HAL_FDCAN_GetRxMessage(&hfdcan1, FDCAN_RX_FIFO0, &RxHeader, RxData);
   	    CanRxMsgCnt++;
//		snprintf (SendBuffer,BUFSIZE,"\r\nCAN Message Nr. %d received!\r\n", CanRxMsgCnt);
//		HAL_UART_Transmit(&huart3,SendBuffer,strlen(SendBuffer),1000);
        CANBus_Parse_RX_Message (RxHeader.Identifier,RxHeader.DataLength, RxData);

	  }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

		CurTimeStamp = HAL_GetTick();
	 	if ((CurTimeStamp - lastTime1s) >= 500) {
	    	// Send two bytes (0xCC,0xCC) on FDCAN1 (as normal classic CAN message with ID 0x555)
			retval = HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, status_data);

			if (retval == HAL_OK) {
				  CanTxMsgCnt++;
				  snprintf (SendBuffer,BUFSIZE,"\r\nCAN Message Nr. %d sent!\r\n", CanTxMsgCnt);
				  HAL_UART_Transmit(&huart3,SendBuffer,strlen(SendBuffer),1000);

			}

			lastTime1s = HAL_GetTick();
	 	}


	    KeyState = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);


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

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI
                              |RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 22;
  RCC_OscInitStruct.PLL.PLLN = 169;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_0;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV1;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief Peripherals Common Clock Configuration
  * @retval None
  */
void PeriphCommonClock_Config(void)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Initializes the peripherals clock
  */
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInitStruct.PLL2.PLL2M = 2;
  PeriphClkInitStruct.PLL2.PLL2N = 12;
  PeriphClkInitStruct.PLL2.PLL2P = 5;
  PeriphClkInitStruct.PLL2.PLL2Q = 2;
  PeriphClkInitStruct.PLL2.PLL2R = 2;
  PeriphClkInitStruct.PLL2.PLL2RGE = RCC_PLL2VCIRANGE_3;
  PeriphClkInitStruct.PLL2.PLL2VCOSEL = RCC_PLL2VCOMEDIUM;
  PeriphClkInitStruct.PLL2.PLL2FRACN = 0;
  PeriphClkInitStruct.AdcClockSelection = RCC_ADCCLKSOURCE_PLL2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

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
