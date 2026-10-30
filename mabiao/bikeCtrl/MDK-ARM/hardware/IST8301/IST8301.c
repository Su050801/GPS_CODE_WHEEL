#include "ist8301.h"
#include "stdio.h"
#include "math.h"

#define PI 3.1415926f

void IST8310_Init(void) 
{
	uint8_t STAT2 = 0x00;
	uint8_t AVGCNTL = 0x12;
	uint8_t CNTL1 = 0x0B;
	
  HAL_GPIO_WritePin(IST_RST_GPIO_Port,IST_RST_Pin,GPIO_PIN_RESET);
	HAL_Delay(50);
	HAL_GPIO_WritePin(IST_RST_GPIO_Port,IST_RST_Pin,GPIO_PIN_SET);
	HAL_Delay(50);
	
	HAL_I2C_Mem_Write(&hi2c1,IST8310_I2C_ADDR,IST8310_CNTL2_ADDR,I2C_MEMADD_SIZE_8BIT,&STAT2,1,1000);
	HAL_Delay(50);
	HAL_I2C_Mem_Write(&hi2c1,IST8310_I2C_ADDR,IST8310_AVGCNTL_ADDR,I2C_MEMADD_SIZE_8BIT,&AVGCNTL,1,1000);
	HAL_Delay(50);
	HAL_I2C_Mem_Write(&hi2c1,IST8310_I2C_ADDR,IST8310_CNTL1_ADDR,I2C_MEMADD_SIZE_8BIT,&CNTL1,1,1000);
}

void IST8310_ReadData(float* mx, float* my, float* mz) 
{
	uint8_t Data[6];

	HAL_I2C_Mem_Read(&hi2c1,IST8310_I2C_ADDR,IST8310_DATA_XL_ADDR,I2C_MEMADD_SIZE_8BIT,Data,6,1000);
	
	*mx = Data[0] + (Data[1]<<8);
	if(*mx > 32768-1)*mx = *mx - 65536;
	*my = Data[2] + (Data[3]<<8);
	if(*my > 32768-1)*my = *my - 65536;
	*mz = Data[4] + (Data[5]<<8);
	if(*mz > 32768-1)*mz = *mz - 65536;
	
}

 
// 输入：Roll角（弧度）、Pitch角（弧度）、磁力计原始数据（μT）
// 输出：航向角（度）
float calculate_heading(float mx, float my) 
{
    float heading;
 
    heading = atan2(mx, my) * (180.0f / PI);
 
    if (heading < 0) {
        heading += 360.0f;
    }
 
    return heading;
}

