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
#include "i2c.h"
#include "memorymap.h"
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

#include "lv_demo_benchmark.h"

#include "gui_guider.h"
#include "events_init.h"
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
uint8_t rx_flag=0;
uint16_t Ss;
GPRMC_Data data;

uint8_t ctp_valid = 0;

float maxspeed;
float Real_speed = 0,Avg_speed = 0,Max_speed = 0,calorie = 0,Latitude = 0,Longitude = 0,Altitude=0;
uint32_t Cadence=0,Distance = 0;

int year = 0+2024;
int month = 0 + 12;
int day = 25;
int weekday = 3;
int hour = 12;
int minutes = 26;
int second = 40;

int spd_hour;
int spd_minute;
int spd_second;
static lv_obj_t * login_win;//����
static lv_obj_t * AVG, *AVG_lab;
static lv_obj_t * MAX, *MAX_lab;
static lv_obj_t * CAD, *CAD_lab;
static lv_obj_t * DIS, *DIS_lab;
static lv_obj_t * Main_SPE, *Main_SPE_S;
lv_obj_t *gps_label;

lv_timer_t* task_timer;

typedef struct _lv_clock
{
    lv_obj_t *time_label; // ʱ���ǩ
    lv_obj_t *date_label; // ���ڱ�ǩ
    lv_obj_t *weekday_label; // ���ڱ�ǩ
	int align;
}lv_clock_t;
 

static lv_clock_t lv_clock = { 0 };
lv_obj_t   *battery_bar;



static void clock_date_task_callback(lv_timer_t *timer)
{
    static const char *week_day[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };

//    static struct tm *time_info; 
	
	second+=1;
	if(second == 240)
	{
		second = 0;
		minutes++;
		if(minutes == 60)
		{
			minutes = 0;
			hour++;
			if(hour == 24)
			{
				hour = 0;
			}
		}
	}
	
//	lv_label_set_text_fmt(Main_SPE,"\n%.2f",Real_speed);
//	lv_label_set_text_fmt(AVG,"\n%.2fkm/h",Avg_speed);
//	lv_label_set_text_fmt(MAX,"%.2fkm/h",Max_speed);
//	lv_label_set_text_fmt(CAD,"%drpm",Cadence);
//	lv_label_set_text_fmt(DIS,"%dKm",Distance);
	
    if (timer != NULL && timer->user_data != NULL)
    {
        lv_clock_t * clock = (lv_clock_t *)(timer->user_data);
        if (clock->time_label != NULL)
        {
						lv_text_align_t align = lv_obj_get_style_align(clock->time_label, LV_STATE_DEFAULT);
            lv_label_set_text_fmt(clock->time_label, "%02d:%02d", hour, minutes);
            lv_obj_align_to(clock->time_label, lv_obj_get_parent(clock->time_label), clock->align, 0, 0);
        }
		
        if (clock->date_label != NULL)
        {
            lv_label_set_text_fmt(clock->date_label, "%d-%02d-%02d", year, month, day);
            lv_obj_align_to(clock->date_label, lv_obj_get_parent(clock->date_label), LV_ALIGN_TOP_MID, 2, 0);
        }
 
         if (clock->weekday_label != NULL)
         {
            lv_label_set_text_fmt(clock->weekday_label, "%s", week_day[weekday]);
            lv_obj_align_to(clock->weekday_label, lv_obj_get_parent(clock->weekday_label), LV_ALIGN_BOTTOM_MID, -2, 0);
         }
    }
//	task_timer = lv_timer_create(clock_date_task_callback, 200, (void *)&lv_clock); // ������ʱ����200msˢ��һ��
}

void stopwatch(void)
{
	
    static lv_style_t time_label_style; // ʱ���ǩ��ʽ
	
    static lv_style_t label_back; // �ı���ǩ��ʽ
    static lv_style_t label_show; // �ı���ǩ��ʽ
	
		login_win =  lv_obj_create(lv_scr_act());
		lv_obj_set_scroll_dir(login_win, LV_DIR_NONE);  // ���ù�������
	
		lv_obj_set_size(login_win,480,160);//���ô�С
    lv_obj_align_to(login_win, lv_scr_act(), LV_ALIGN_TOP_MID, 0, 0);
	
    lv_style_reset(&time_label_style); // ������ʽ
    lv_style_init(&time_label_style); // ��ʼ����ʽ
    lv_style_set_text_color(&time_label_style , lv_color_white()); // ���ñ�ǩ��ʽ�ı���ɫ
    lv_style_set_text_font(&time_label_style, &lv_font_montserrat_16); // ����������
    lv_style_set_text_opa(&time_label_style, LV_OPA_COVER); // ��������͸����
    lv_style_set_bg_opa(&time_label_style, LV_OPA_0); // ������ʽ����͸����
	

    lv_style_reset(&label_back); // ������ʽ
    lv_style_init(&label_back); // ��ʼ����ʽ
    lv_style_set_text_color(&label_back , lv_color_white()); // ���ñ�ǩ��ʽ�ı���ɫ
    lv_style_set_text_opa(&label_back, LV_OPA_COVER); // ��������͸����
    lv_style_set_bg_opa(&label_back, LV_OPA_100); // ������ʽ����͸����
    lv_style_set_border_width(&label_back, 2);
    lv_style_set_border_color(&label_back, lv_color_black());
    lv_style_set_border_opa(&label_back, LV_OPA_COVER);
		lv_style_set_bg_color(&label_back , lv_color_black());
	
    lv_style_reset(&label_show); // ������ʽ
    lv_style_init(&label_show); // ��ʼ����ʽ
		lv_style_set_radius(&label_show, 6); // ����Բ��Ϊ6
    lv_style_set_text_align(&label_show, LV_TEXT_ALIGN_CENTER);
	
	//ʱ��

    lv_clock.time_label = lv_label_create(lv_scr_act()); // ����time_obj���󴴽�ʱ����ʾ��ǩ���� lv_clock.time_label
    lv_obj_add_style(lv_clock.time_label, &time_label_style, LV_STATE_DEFAULT); // ������ lv_clock.time_label�����ʽ
		lv_clock.align = LV_ALIGN_TOP_MID;
    lv_obj_align_to(lv_clock.time_label, login_win, lv_clock.align, 0, 0);
    lv_obj_set_style_text_font(lv_clock.time_label,&lv_font_montserrat_16,0); // ����������
	
		task_timer = lv_timer_create(clock_date_task_callback, 200, (void *)&lv_clock); // ������ʱ����200msˢ��һ��
	
		lv_obj_t *label_temp = lv_label_create(lv_scr_act()); 
    lv_obj_add_style(label_temp, &time_label_style, LV_STATE_DEFAULT); //����
    lv_obj_align_to(label_temp, lv_scr_act(), LV_ALIGN_TOP_RIGHT, -30, 0);
		lv_label_set_text(label_temp, LV_SYMBOL_BATTERY_2 "30%");

		label_temp = lv_label_create(lv_scr_act()); 
    lv_obj_align_to(label_temp, lv_scr_act(), LV_ALIGN_TOP_LEFT, 0, 0);
		lv_label_set_text(label_temp, " "LV_SYMBOL_SD_CARD);
	
		
	//�ٶ�
    Main_SPE = lv_label_create(lv_scr_act()); // ����time_obj���󴴽�ʱ����ʾ��ǩ���� lv_clock.time_label
		lv_obj_align_to(Main_SPE, login_win, LV_ALIGN_CENTER, -30, -50);
    lv_obj_set_style_text_font(Main_SPE,&lv_font_montserrat_32,0); // ����������
		lv_label_set_text_fmt(Main_SPE,"\n%.2f",Real_speed);
//	
		Main_SPE_S = lv_label_create(lv_scr_act());
		lv_obj_align_to(Main_SPE_S, Main_SPE, LV_ALIGN_OUT_BOTTOM_RIGHT, -75, 0);
    lv_obj_set_style_text_font(Main_SPE_S,&lv_font_montserrat_16,0); // ����������
		lv_obj_set_size(Main_SPE_S,150,80);
		lv_label_set_text_fmt(Main_SPE_S,"RT SPEED(kph)");
	
	
    AVG = lv_label_create(lv_scr_act()); // ����time_obj���󴴽�ʱ����ʾ��ǩ���� lv_clock.time_label
		lv_obj_align_to(AVG, login_win, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
    lv_obj_set_style_text_font(AVG,&lv_font_montserrat_16,0); // ����������
		lv_label_set_text_fmt(AVG,"\n%.2fkm/h",Avg_speed);
//	
		AVG_lab = lv_label_create(lv_scr_act());
		lv_obj_align_to(AVG_lab, AVG, LV_ALIGN_OUT_BOTTOM_RIGHT, -50, 0);
    lv_obj_set_style_text_font(AVG_lab,&lv_font_montserrat_12,0); // ����������
		lv_obj_set_size(AVG_lab,100,80);
		lv_label_set_text_fmt(AVG_lab,"AVG");
	
    MAX = lv_label_create(lv_scr_act()); // ����time_obj���󴴽�ʱ����ʾ��ǩ���� lv_clock.time_label
		lv_obj_align_to(MAX, AVG, LV_ALIGN_OUT_RIGHT_MID, 50, 10);
    lv_obj_set_style_text_font(MAX,&lv_font_montserrat_16,0); // ����������
		lv_label_set_text_fmt(MAX,"%.2fkm/h",Max_speed);
//	
		MAX_lab = lv_label_create(lv_scr_act());
		lv_obj_align_to(MAX_lab, MAX, LV_ALIGN_OUT_BOTTOM_RIGHT, -50, 0);
    lv_obj_set_style_text_font(MAX_lab,&lv_font_montserrat_12,0); // ����������
		lv_obj_set_size(MAX_lab,100,80);
		lv_label_set_text_fmt(MAX_lab,"MAX");
	
	
    CAD = lv_label_create(lv_scr_act()); // ����time_obj���󴴽�ʱ����ʾ��ǩ���� lv_clock.time_label
		lv_obj_align_to(CAD, MAX, LV_ALIGN_OUT_RIGHT_MID, 50, 0);
    lv_obj_set_style_text_font(CAD,&lv_font_montserrat_16,0); // ����������
		lv_label_set_text_fmt(CAD,"%drpm",Cadence);
//	
		CAD_lab = lv_label_create(lv_scr_act());
		lv_obj_align_to(CAD_lab, CAD, LV_ALIGN_OUT_BOTTOM_RIGHT, -50, 0);
    lv_obj_set_style_text_font(CAD_lab,&lv_font_montserrat_12,0); // ����������
		lv_obj_set_size(CAD_lab,100,80);
		lv_label_set_text_fmt(CAD_lab,"CAD");
	
    DIS = lv_label_create(lv_scr_act()); // ����time_obj���󴴽�ʱ����ʾ��ǩ���� lv_clock.time_label
		lv_obj_align_to(DIS, CAD, LV_ALIGN_OUT_RIGHT_MID, 50, 0);
    lv_obj_set_style_text_font(DIS,&lv_font_montserrat_16,0); // ����������
		lv_label_set_text_fmt(DIS,"%dKm",Distance);
//	
		DIS_lab = lv_label_create(lv_scr_act());
		lv_obj_align_to(DIS_lab, DIS, LV_ALIGN_OUT_BOTTOM_RIGHT, -50, 0);
    lv_obj_set_style_text_font(DIS_lab,&lv_font_montserrat_12,0); // ����������
		lv_obj_set_size(DIS_lab,100,80);
		lv_label_set_text_fmt(DIS_lab,"DIS");
	
		lv_obj_t * btn1 = lv_btn_create(lv_scr_act());
    lv_obj_align_to(btn1,lv_scr_act(), LV_ALIGN_BOTTOM_MID, 0,-50);

    label_temp = lv_label_create(btn1);
    lv_label_set_text(label_temp, LV_SYMBOL_HOME);
    lv_obj_center(label_temp);
	
		btn1 = lv_btn_create(lv_scr_act());
    lv_obj_align_to(btn1,lv_scr_act(), LV_ALIGN_BOTTOM_LEFT, 0,-50);

    label_temp = lv_label_create(btn1);
    lv_label_set_text(label_temp, LV_SYMBOL_NEXT);
    lv_obj_center(label_temp);
	
		btn1 = lv_btn_create(lv_scr_act());
    lv_obj_align_to(btn1,lv_scr_act(), LV_ALIGN_BOTTOM_RIGHT, -50,-50);

    label_temp = lv_label_create(btn1);
    lv_label_set_text(label_temp, LV_SYMBOL_LIST);
    lv_obj_center(label_temp);
		
		gps_label = lv_label_create(lv_scr_act()); 
    lv_obj_align_to(gps_label, lv_scr_act(), LV_ALIGN_TOP_LEFT, 26, 0);
		lv_label_set_text(gps_label, LV_SYMBOL_GPS);
		lv_obj_set_style_text_color(gps_label,lv_color_hex(0xff0000),LV_STATE_DEFAULT);
		
    lv_timer_t* task_timer = lv_timer_create(clock_date_task_callback, 200, (void *)&lv_clock); 
}
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MPU_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

lv_ui guider_ui;
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
  MX_TIM6_Init();
  MX_I2C4_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_USART6_UART_Init();
  /* USER CODE BEGIN 2 */
	lcd_init();
	lcd_fill(0,0,480,320,BLACK);
	HAL_Delay(100);
	LCD_BL(1);
	
	HAL_GPIO_WritePin(GPS_RST_GPIO_Port,GPS_RST_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPS_ON_GPIO_Port,GPS_ON_Pin,GPIO_PIN_SET);
	
	HAL_UARTEx_ReceiveToIdle_IT(&huart1,IDLE_Rx,150);
	
	//FT6336_Init();
	lv_init();                            
	lv_port_disp_init();                   
	HAL_TIM_Base_Start_IT(&htim6);
	stopwatch();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  
		HAL_Delay(5);
	  lv_timer_handler();
		if(rx_flag == 1)
		{
			parse_gprmc((char*)IDLE_Rx, &data);
			if(data.status == 'A')
			{
				if(maxspeed < data.speed)
					maxspeed = data.speed;
				lv_obj_set_style_text_color(gps_label,lv_color_hex(0x00ff00),LV_STATE_DEFAULT);
				Real_speed = data.speed;
				
				lv_label_set_text_fmt(Main_SPE,"\n%.2f",Real_speed);
				lv_label_set_text_fmt(AVG,"\n%.2fkm/h",Avg_speed);
				lv_label_set_text_fmt(MAX,"%.2fkm/h",maxspeed);
				lv_label_set_text_fmt(CAD,"%drpm",Cadence);
				lv_label_set_text_fmt(DIS,"%dKm",Distance);
				//HAL_GPIO_TogglePin(BUZZER_GPIO_Port,BUZZER_Pin);
			}
			else
				lv_obj_set_style_text_color(gps_label,lv_color_hex(0xff0000),LV_STATE_DEFAULT);
			rx_flag = 0;	
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
  RCC_OscInitStruct.PLL.PLLQ = 2;
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
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM6)
	{
		lv_tick_inc(1);
	}
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	if(huart->Instance == USART1)
	{
		rx_flag = 1;
		Ss = Size;
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
