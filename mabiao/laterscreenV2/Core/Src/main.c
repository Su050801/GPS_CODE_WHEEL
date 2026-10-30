/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "fatfs.h"
#include "memorymap.h"
#include "sdmmc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "fmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "tftlcd.h"
#include "stdio.h"
#include "file_operate.h"

#include "lvgl.h"               
#include "lv_port_disp.h"       
#include "lv_port_indev.h"      

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
uint8_t framebuffer[307209];
UINT bytesRead;
uint8_t showtime = 0;

int picNum = 0;
int vdNum = 0;
int txNum = 0;

uint8_t IDLE_Rx[20];
FIL picFile;
FIL vdFile;
bool vdOn = 0;
bool rxFlag = 0;
uint8_t sxTime = 0;
void txtShow(void);
LV_FONT_DECLARE(lv_front_cn);

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
void picShow(uint8_t num);
void vdShow(uint8_t num);
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MPU_Config(void);
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

  /* MPU Configuration--------------------------------------------------------*/
  MPU_Config();

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
  MX_FMC_Init();
  MX_SDMMC1_SD_Init();
  MX_TIM7_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_FATFS_Init();
  MX_TIM6_Init();
  /* USER CODE BEGIN 2 */
	HAL_UARTEx_ReceiveToIdle_IT(&huart1,IDLE_Rx,15);
	lcd_init();
	lv_init();                            
	lv_port_disp_init();   
	HAL_TIM_Base_Start_IT(&htim7);
	HAL_TIM_Base_Start_IT(&htim6);
	Mount_FatFs();
	FatFs_GetDiskInfo();
	HAL_Delay(100);

	if(f_open(&picFile, "0:qslogo.ebm", FA_READ) == FR_OK)
	{
		lv_obj_t * imgBg = lv_img_create(lv_scr_act());
		lv_img_dsc_t testimg = {
		.header.w = 480,
		.header.h = 320,
		.data_size = 307200,
		.header.cf = LV_IMG_CF_TRUE_COLOR,
		};
		lv_obj_align(imgBg,LV_ALIGN_CENTER, 0, 0);
		f_read(&picFile,framebuffer,307200,&bytesRead);
		testimg.data = framebuffer;
		lv_img_set_src(imgBg, &testimg);
		lv_timer_handler();
		f_close(&picFile);
		printf("ok\r\n");
	}

//	HAL_Delay(50);
//	HAL_UARTEx_ReceiveToIdle_IT(&huart1,IDLE_Rx,15);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		picShow(picNum);
		vdShow(vdNum);
		HAL_Delay(5);
		if(rxFlag == 1)
		{
			LCD_BL(1);
			rxFlag = 0;
			lv_obj_clean(lv_scr_act());
			printf("%s\r\n",IDLE_Rx);
			txNum = 0;
			if(sscanf((char*)IDLE_Rx,"LsP:%d",&picNum) == 1)
			{
				showtime = 3;
				vdNum = 0;
			}
			else if(sscanf((char*)IDLE_Rx,"LsV:%d",&vdNum) == 1)
			{
				showtime = 0;
				vdOn = 1;
				picNum = 0;
			}
//			else if(sscanf((char*)IDLE_Rx,"LsT:%d",&txNum) == 1)
//			{
//				showtime = 0;
//				picNum = 0;
//				vdNum = 0;
//				//txtShow();
//			}
			memset(IDLE_Rx,0,20);
		}
		lv_timer_handler();
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 60;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
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
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void picShow(uint8_t num)
{
	if(showtime)
	{
		switch(num)
		{
			case 1:
				if(f_open(&picFile, "0:redAll.ebm", FA_READ) != FR_OK) {
					printf("file open fial\r\n");
					Mount_FatFs();
					f_open(&picFile, "0:redAll.ebm", FA_READ);
				}
				else 
				{
					printf("file open ok\r\n");
					
				}
				break;
				
			case 2:
				if(f_open(&picFile, "0:redRight.ebm", FA_READ) != FR_OK) {
					printf("file open fial\r\n");
					Mount_FatFs();
					f_open(&picFile, "0:redRight.ebm", FA_READ);
				}
				else 
				{
					printf("file open ok\r\n");
					
				}
				break;
				
			case 3:
				if(f_open(&picFile, "0:redLeft.ebm", FA_READ) != FR_OK) {
					printf("file open fial\r\n");
					Mount_FatFs();
					f_open(&picFile, "0:redLeft.ebm", FA_READ);
				}
				else 
				{
					printf("file open ok\r\n");
					
				}
			  break;
			case 4:
				if(f_open(&picFile, "0:qslogo.ebm", FA_READ) != FR_OK) {
					printf("file open fial\r\n");
					Mount_FatFs();
					f_open(&picFile, "0:qslogo.ebm", FA_READ);
				}
				else 
				{
					printf("file open ok\r\n");
					
				}
				break;
		}
		lv_obj_t * imgBg = lv_img_create(lv_scr_act());
		lv_img_dsc_t testimg = {
		.header.w = 480,
		.header.h = 320,
		.data_size = 307200,
		.header.cf = LV_IMG_CF_TRUE_COLOR,
		};
		lv_obj_align(imgBg,LV_ALIGN_CENTER, 0, 0);
		f_read(&picFile,framebuffer,307200,&bytesRead);
		testimg.data = framebuffer;
		lv_img_set_src(imgBg, &testimg);
		lv_timer_handler();
		f_close(&picFile);
		showtime--;
	}
}
void vdShow(uint8_t num)
{
	if(vdOn)
	{
		lcd_clear(BLACK);
		switch(num)
		{
			case 1:
				if(f_open(&vdFile, "0:all.ebm", FA_READ) != FR_OK) {
					printf("file open fial\r\n");
					Mount_FatFs();
					f_open(&vdFile, "0:all.ebm", FA_READ);
				}
				else 
				{
					printf("file open ok\r\n");
					
				}
				break;
		}
		lv_obj_t * imgBg = lv_img_create(lv_scr_act());
		lv_img_dsc_t testimg = {
		.header.w = 480,
		.header.h = 298,
		.data_size = 286080,
		.header.cf = LV_IMG_CF_TRUE_COLOR,
		};
		lv_obj_align(imgBg,LV_ALIGN_CENTER, 0, 0);
		while(1)
		{ 
			if(picNum != 0 )
				break;
			f_read(&vdFile,framebuffer,286080,&bytesRead);
			if(bytesRead != 286080 || rxFlag == 1)break;
			testimg.data = framebuffer;
			lv_img_set_src(imgBg, &testimg);
			lv_timer_handler();
		}
		HAL_Delay(100);
		f_close(&vdFile);
		lv_obj_clean(lv_scr_act());
		vdOn = 0;
		
		showtime = 4;
		picNum = 4;
		
	}
}

void txtShow(void)
{
	lv_obj_t *scr = lv_scr_act();
	lv_obj_t *label = lv_label_create(scr);
	lv_label_set_text(label, "好消息今晚6点超市全场商品88折买得多送得多");
	lv_obj_set_size(label,480,320);
	lv_obj_set_style_text_font(label, &lv_front_cn, LV_PART_MAIN);
	lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL);
	lv_obj_set_style_anim_speed(label, 180, LV_PART_MAIN); 
	lv_obj_set_pos(label,0,40);
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	if(huart->Instance == USART1)
	{ 
		if(Size == 5)
		{
			rxFlag = 1;
			sxTime = 10;
		}
	}
	HAL_UARTEx_ReceiveToIdle_IT(&huart1,IDLE_Rx,15);
}



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM7)
	{
		lv_tick_inc(1);
	}
	else if(htim->Instance == TIM6 && sxTime)
	{
		if(picNum == 2 || picNum == 3)
		{
			LCD_BL(sxTime%2);
		}
		sxTime--;
		if(sxTime == 0 && vdOn == 0 && txNum == 0)
		{
			showtime = 3;
			picNum = 4;
		}
	}
}
/* USER CODE END 4 */

 /* MPU Configuration */

void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct = {0};

  /* Disables the MPU */
  HAL_MPU_Disable();

  /** Initializes and configures the Region and the memory to be protected
  */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.BaseAddress = 0x0;
  MPU_InitStruct.Size = MPU_REGION_SIZE_4GB;
  MPU_InitStruct.SubRegionDisable = 0x87;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.AccessPermission = MPU_REGION_NO_ACCESS;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);
  /* Enables the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);

}

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
