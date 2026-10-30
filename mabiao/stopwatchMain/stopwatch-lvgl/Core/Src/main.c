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
#include "adc.h"
#include "fatfs.h"
#include "i2c.h"
#include "memorymap.h"
#include "sdmmc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "fmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "tftlcd.h"
#include "ctp.h"
#include "string.h"
#include "gps.h"
#include "lvgl.h"                
#include "lv_port_disp.h"        
#include "lv_port_indev.h"  
#include "dps310.h"
#include "ist8301.h"
#include "gui_guider.h"
#include "events_init.h"
#include "mpu6050.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "bikesys.h"
#include "file_operate.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
uint8_t IDLE_Rx[200];
uint8_t IDLE_Rx1[50];
GPRMC_Data data;
lv_ui guider_ui;
uint16_t adcValue;
bikeSys bike;

uint16_t show_direction;
uint8_t  directiom_acc;

FIL txt;
FRESULT txtres;
UINT changdu;
char aaa;
char temdata[5];
uint8_t bbb;
uint8_t havecar = 0;

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
void timeSet(void);
void BLUE_Deal(void);
void GPS_Deal(void);
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
	uint16_t skipTime = 200;
	int setline = 20;
	lv_point_t line[] = {{50, setline},{0, 45},};
	char angele[7];
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
  MX_TIM6_Init();
  MX_I2C4_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_USART6_UART_Init();
  MX_ADC1_Init();
  MX_TIM1_Init();
  MX_SDMMC1_SD_Init();
  MX_FATFS_Init();
  /* USER CODE BEGIN 2 */
	HAL_UARTEx_ReceiveToIdle_IT(&huart2,IDLE_Rx1,50);
	lcd_init();
	while(MPU_Init())
		HAL_Delay(100);
	while(mpu_dmp_init())
		HAL_Delay(100);
	lcd_clear(BLACK);
	FT6336_Init();
	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();
	setup_ui(&guider_ui);
  events_init(&guider_ui);
	HAL_TIM_Base_Start_IT(&htim6);
	DSP310_Init();
	IST8310_Init();
	
	HAL_TIM_Base_Start(&htim1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
	htim1.Instance->CCR2 = 700;
	data.speed = 0.0;
	lv_bar_set_value(guider_ui.open_open_bar1, 100, LV_ANIM_ON);
	while(skipTime--)
	{
		HAL_Delay(5);
	  lv_timer_handler();
	}
	lv_obj_clear_flag(guider_ui.open_btn_1, LV_OBJ_FLAG_HIDDEN);
	
	
	HAL_GPIO_WritePin(BUZZER_GPIO_Port,BUZZER_Pin,GPIO_PIN_SET);
	HAL_Delay(200);
	HAL_GPIO_WritePin(BUZZER_GPIO_Port,BUZZER_Pin,GPIO_PIN_RESET);
	while(bike.currentScr == 0)
	{
		HAL_Delay(5);
	  lv_timer_handler();
	}
	if(Mount_FatFs())
		lv_obj_set_style_text_color(guider_ui.show_sdcard, lv_color_hex(0x00ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	FatFs_GetDiskInfo();
	HAL_GPIO_WritePin(GPS_ON_GPIO_Port,GPS_ON_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(BLUE_RST_GPIO_Port,BLUE_RST_Pin,GPIO_PIN_SET);
	HAL_Delay(100); 
	HAL_GPIO_WritePin(BLUE_RST_GPIO_Port,BLUE_RST_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPS_RST_GPIO_Port,GPS_RST_Pin,GPIO_PIN_SET);
	HAL_UARTEx_ReceiveToIdle_IT(&huart1,IDLE_Rx,150);
	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		HAL_Delay(4);
	  lv_timer_handler();
		BLUE_Deal();
		GPS_Deal();
		if(bike.skp++ == 15)
		{
			bike.skp = 0;
			mpu_dmp_get_data( &bike.pitch,&bike.roll,&bike.yaw);
			line[0].y = 45 -  (int)bike.pitch+15;
			lv_line_set_points(guider_ui.show_angle, line, 2);
			sprintf(angele,"%d",(int)bike.pitch - 15);
			lv_label_set_text(guider_ui.show_ange, angele);
			
			DPS310_ReadDate(&bike.temperature, &bike.alt);
			sprintf(bike.altitude,"%.1fM",bike.alt);
			lv_label_set_text(guider_ui.show_pressure, bike.altitude);
			
			
			bike.direction = (uint16_t)IST8310_ReadData();
			show_direction += bike.direction;
			if(directiom_acc++ == 2)
			{
				directiom_acc = 0;
				show_direction = show_direction / 3;
				sprintf(bike.Direction,"%d",show_direction);
			  lv_label_set_text(guider_ui.show_label_13, bike.Direction);
				show_direction = 0;
			}
		}
	
		if(bike.ctlFlag)
		{
			bike.turnState = 0;
			if(bike.ctlFlag == 1)
			{
				HAL_UART_Transmit(&huart2,(uint8_t*)"LsP:3",5,1000);
				bike.turnFlag = 1;
			}
			else if(bike.ctlFlag == 2)
			{
				HAL_UART_Transmit(&huart2,(uint8_t*)"LsP:2",5,1000);
				bike.turnFlag = 2;
			}
			else if(bike.ctlFlag == 3)
			{
				HAL_UART_Transmit(&huart2,(uint8_t*)"LsV:1",5,1000);
				bike.turnFlag = 3;
			}
			else if(bike.ctlFlag == 4)
			{
				HAL_UART_Transmit(&huart2,(uint8_t*)"LsT:1",5,1000);
				bike.turnFlag = 3;
			}
			else if(bike.ctlFlag == 5)
			{
				HAL_UART_Transmit(&huart2,(uint8_t*)"LsP:1",5,1000);
			}
			bike.ctlFlag = 0;
		}
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 2;
  RCC_OscInitStruct.PLL.PLLN = 80;
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

void autoDataSet(void)
{
	if(bike.AUTO_DATA_Flag == 1)
	{
		txtres = f_open(&txt, "rundata.c", FA_READ);
		if(txtres == FR_OK)
		{
			bike.AUTO_DATA_Flag = 2;
		}
	}
	else if(bike.AUTO_DATA_Flag == 2)
	{
			txtres = f_read(&txt, &aaa, 1, &changdu);
			if (txtres != FR_OK || changdu == 0) {
					f_close(&txt);
				}
			bbb = 0;
			while(aaa != ',')
			{
				temdata[bbb] = aaa;
				txtres = f_read(&txt, &aaa, 1, &changdu);
				if (txtres != FR_OK || changdu == 0) {
					break; 
					f_close(&txt);
				}
				bbb++;
			}
			if(sscanf(temdata,"%f",&data.speed) == 1)
			{
				data.status = 'A';
			}
	}
}

void timeSet(void)
{
	if(bike.RUN_Flag == 1)
	{
		bike.runSecond++;
		if(bike.runSecond == 120)
		{
			bike.runSecond = 0;
			bike.runMin++;
			if(bike.runMin == 120)
			{
				bike.runMin = 0;
				bike.runHour++;
			}
		}
		sprintf(bike.runTime,"%d:%d:%d",bike.runHour,bike.runMin,bike.runSecond/2);
		lv_label_set_text(guider_ui.show_runTime, bike.runTime);
		
		bike.allKm += (data.speed / 7200)*1.2;
		sprintf(bike.allLong,"%.1fKm",bike.allKm);
		lv_label_set_text(guider_ui.show_allKm, bike.allLong);
		bike.avgSpeed = bike.allKm / (float)(((float)bike.runSecond/7200.0f) + (float)((float)bike.runMin / 60.0f) + bike.runHour);
		sprintf(bike.avgspeed,"%.1fKm/h",bike.avgSpeed/1.2);
		lv_label_set_text(guider_ui.show_avgSpeed, bike.avgspeed);
	}
	sprintf(bike.realtime,"%d:%d",data.hours,data.minutes);
	lv_label_set_text(guider_ui.show_time, bike.realtime);
}



void BLUE_Deal(void)
{
	if(bike.BLUE_Flag == 1)
	{
		printf("%s\r\n",IDLE_Rx1);
		if(sscanf((char*)IDLE_Rx1,"rpm:%f",&bike.tp) == 1)
		{
			sprintf(bike.TP,"%.1fR/m",bike.tp);
			lv_label_set_text(guider_ui.show_label_3, bike.TP);
		} 
		else if(strcmp((char*)IDLE_Rx1, (char*)"rightee") == 0) {
			bike.ctlFlag = 1;
			HAL_UART_Transmit(&huart2,(uint8_t*)"LsP:3",5,1000);
			HAL_Delay(100);
			HAL_UART_Transmit(&huart2,(uint8_t*)"rightee",8,1000);
		}
		else if(strcmp((char*)IDLE_Rx1, (char*)"leftee") == 0) {
			bike.ctlFlag = 2;
			HAL_UART_Transmit(&huart2,(uint8_t*)"LsP:2",5,1000);
			HAL_Delay(100);
			HAL_UART_Transmit(&huart2,(uint8_t*)"leftee",8,1000);
		}
		else if(strcmp((char*)IDLE_Rx1, (char*)"rightfrontee") == 0) {
			bike.ctlFlag = 1;
			HAL_UART_Transmit(&huart2,(uint8_t*)"LsP:3",5,1000);
			HAL_Delay(100);
			HAL_UART_Transmit(&huart2,(uint8_t*)"rightee",8,1000);
		}
		else if(strcmp((char*)IDLE_Rx1, (char*)"leftfrontee") == 0) {
			bike.ctlFlag = 2;
			HAL_UART_Transmit(&huart2,(uint8_t*)"LsP:2",5,1000);
			HAL_Delay(100);
			HAL_UART_Transmit(&huart2,(uint8_t*)"leftee",8,1000);
		}
		
		else if(strcmp((char*)IDLE_Rx1, (char*)"LsP:1") == 0) {
			bike.ctlFlag = 1;
		}
		else if(strcmp((char*)IDLE_Rx1, (char*)"LsP:2") == 0) {
			bike.ctlFlag = 2;
		}
		else if(strcmp((char*)IDLE_Rx1, (char*)"LsV:1") == 0) {
			bike.ctlFlag = 3;
		}
		else if(strcmp((char*)IDLE_Rx1, (char*)"LsT:1") == 0) {
			bike.ctlFlag = 4;
		}
		else if(strcmp((char*)IDLE_Rx1, (char*)"LsS:1") == 0) {
			bike.ctlFlag = 5;
		}
		
		else if(strcmp((char*)IDLE_Rx1, (char*)"dis:1") == 0) {
			havecar = 1;   //有后车
			HAL_GPIO_WritePin(BUZZER_GPIO_Port,BUZZER_Pin,GPIO_PIN_RESET);
		}
		else if(strcmp((char*)IDLE_Rx1, (char*)"dis:2") == 0) {
			havecar = 0;   //无后车
			HAL_GPIO_WritePin(BUZZER_GPIO_Port,BUZZER_Pin,GPIO_PIN_RESET);
		}
		
		memset(IDLE_Rx1,0,50);
		bike.BLUE_Flag = 0;
	}
}
void GPS_Deal(void)
{
	if(bike.GPS_Flag == 1)
	{
		printf("%s",IDLE_Rx);
		parse_gprmc((char*)IDLE_Rx, &data);
		if(bike.AUTO_DATA_Flag)autoDataSet();
		timeSet();
		if(bike.AUTO_STOP_Flag == 1)
		{
			HAL_GPIO_WritePin(BUZZER_GPIO_Port,BUZZER_Pin,GPIO_PIN_RESET);
			if(data.speed == 0 && bike.RUN_Flag)
			{
				bike.auto_stopTime++;
				if(bike.auto_stopTime >= 10)
				{
					bike.RUN_Flag = 0;
					bike.auto_stopTime = 0;
					lv_label_set_text(guider_ui.show_start_label,LV_SYMBOL_PLAY);
					HAL_GPIO_WritePin(BUZZER_GPIO_Port,BUZZER_Pin,GPIO_PIN_SET);
				}
			}
			else if(data.speed > 5 && bike.RUN_Flag == 0)
			{
				bike.auto_stopTime++;
				if(bike.auto_stopTime >= 10)
				{
					bike.RUN_Flag = 1;
					bike.auto_stopTime = 0;
					lv_label_set_text(guider_ui.show_start_label,LV_SYMBOL_PAUSE);
					HAL_GPIO_WritePin(BUZZER_GPIO_Port,BUZZER_Pin,GPIO_PIN_SET);
				}
			}
		}
		
		
		if(bike.turnFlag)
		{
			bike.turnState++;
			if((bike.turnState % 2) == 0 && bike.turnFlag == 1)
			{
				HAL_GPIO_WritePin(BUZZER_GPIO_Port,BUZZER_Pin,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,GPIO_PIN_SET);
				lv_obj_set_style_img_opa(guider_ui.show_turnRight, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
			}
			else if((bike.turnState % 2) == 1 && bike.turnFlag == 1)
			{
				HAL_GPIO_WritePin(BUZZER_GPIO_Port,BUZZER_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,GPIO_PIN_RESET);
				lv_obj_set_style_img_opa(guider_ui.show_turnRight, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
			}
			
			if((bike.turnState % 2) == 0 && bike.turnFlag == 2)
			{
				HAL_GPIO_WritePin(BUZZER_GPIO_Port,BUZZER_Pin,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,GPIO_PIN_SET);
				lv_obj_set_style_img_opa(guider_ui.show_turnLeft, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
			}
			else if((bike.turnState % 2) == 1 && bike.turnFlag == 2)
			{
				HAL_GPIO_WritePin(BUZZER_GPIO_Port,BUZZER_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,GPIO_PIN_RESET);
				lv_obj_set_style_img_opa(guider_ui.show_turnLeft, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
			}
			if(bike.turnState == 5 && bike.turnFlag == 1)
			{
				bike.turnState = 0;
				HAL_GPIO_WritePin(BUZZER_GPIO_Port,BUZZER_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,GPIO_PIN_RESET);
				lv_obj_set_style_img_opa(guider_ui.show_turnRight, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_img_opa(guider_ui.show_turnLeft, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
				bike.turnFlag = 0;
			}
			else if(bike.turnState == 3 && bike.turnFlag == 2)
			{
				bike.turnState = 0;
				HAL_GPIO_WritePin(BUZZER_GPIO_Port,BUZZER_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,GPIO_PIN_RESET);
				lv_obj_set_style_img_opa(guider_ui.show_turnRight, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_img_opa(guider_ui.show_turnLeft, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
				bike.turnFlag = 0;
			}
		}
		
		if(bike.LIGHT_Flag == 1)
		{
			HAL_ADC_Start(&hadc1);
			if(HAL_OK == HAL_ADC_PollForConversion(&hadc1,50))
				adcValue = HAL_ADC_GetValue(&hadc1);
			htim1.Instance->CCR2 = 1000 - ((adcValue * 1000) / 65535);
		}
		if(data.status == 'A')
		{
			sprintf(bike.speeD,"%.1f",data.speed);
			lv_label_set_text(guider_ui.show_speed, bike.speeD);
			
			if(bike.maxSpeed <= data.speed && bike.RUN_Flag == 1)
			{
				bike.maxSpeed = data.speed;
				sprintf(bike.maxspeed,"%.1fKm/h",bike.maxSpeed);
				lv_label_set_text(guider_ui.show_maxSpeed, bike.maxspeed);
			}
			
			lv_obj_set_style_text_color(guider_ui.show_gps,lv_color_hex(0x00ff00),LV_PART_MAIN|LV_STATE_DEFAULT);
		}
		else
		{
			lv_obj_set_style_text_color(guider_ui.show_gps,lv_color_hex(0xff0000),LV_PART_MAIN|LV_STATE_DEFAULT);
			data.speed = 0;
			sprintf(bike.speeD,"%.1f",data.speed);
			lv_label_set_text(guider_ui.show_speed, bike.speeD);
		}
			

		bike.GPS_Flag = 0;
		memset(IDLE_Rx,0,150);			
	}
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	static uint16_t cunt = 0;
	if (htim->Instance == TIM6)
	{
		lv_tick_inc(1);
		if(havecar == 1)
		{
			cunt++;
			if(cunt%60 == 0)
			{
				HAL_GPIO_TogglePin(BUZZER_GPIO_Port,BUZZER_Pin);
			}
		}
	}
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	if(huart->Instance == USART2)
	{
		bike.BLUE_Flag = 1;
		HAL_UARTEx_ReceiveToIdle_IT(&huart2,IDLE_Rx1,50);
	}
	if(huart->Instance == USART1)
	{
		bike.GPS_Flag = 1;
		HAL_UARTEx_ReceiveToIdle_IT(&huart1,IDLE_Rx,150);
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
