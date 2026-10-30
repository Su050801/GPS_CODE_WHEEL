#include "dps310.h"
#include "stdio.h"
#include "math.h"

uint8_t Init[5]={0xB3,0X07,0x01,0x36,0x04};

int c0,c1,c01,c11,c20,c21,c30;
long int c00,c10;
int Pressure, Temperature;


#define P0 101325.0    // ??????????????¦Ë??Pa
#define T0 288.15      // ?????????????¦Ë??K
#define L 0.0065       // ??????????¦Ë??K/m
#define g 9.80665      // ????????????¦Ë??m/s^2
#define M 0.0289644    // ???????????????¦Ë??kg/mol
#define R 8.3144598    // ??????i??????¦Ë??J/(mol??K)
 
// ??????????


void DSP310_Init(void)
{
	uint8_t CC[18] = {0};

	HAL_I2C_Mem_Read(&hi2c4,ISP_READ,COEF,I2C_MEMADD_SIZE_8BIT,CC,18,1000);
	c0 = ((CC[1]/16)&0x0F) + (CC[0]*16);
	if(c0 > 2048-1)c0 = c0 - 4096;
//	printf("c0:%d\r\n",c0);
	c1 = ((CC[1]&0x0F)<<8) + CC[2];
	if(c1 > 2048-1)c1 = c1 - 4096;
//	printf("c1:%d\r\n",c1);
	c00 = ((CC[5]&0xF0)/16) + (CC[4]<<4) + (CC[3]<<12);
	if(c00 > 524288-1)c00 = c00 - 1048576;
//	printf("c00:%ld\r\n",c00);
	c10 = ((CC[5]&0x0F)<<16) + (CC[6]<<8) + CC[7];
	if(c10 > 524288-1)c10 = c10 - 1048576;
//	printf("c10:%ld\r\n",c10);
	c01 = (CC[8]<<8) + CC[9];
	if(c01 > 32768-1)c01 = c01 - 65536;
//	printf("c01:%d\r\n",c01);
	c11 = (CC[10]<<8) + CC[11];
	if(c11 > 32768-1)c11 = c11 - 65536;
//	printf("c11:%d\r\n",c11);
	c20 = (CC[12]<<8) + CC[13];
	if(c20 > 32768-1)c20 = c20 - 65536;
//	printf("c20:%d\r\n",c20);
	c21 = (CC[14]<<8) + CC[15];
	if(c21 > 32768-1)c21 = c21 - 65536;
//	printf("c21:%d\r\n",c21);
	c30 = (CC[16]<<8) + CC[17];
	if(c30 > 32768-1)c30 = c30 - 65536;
//	printf("c30:%d\r\n",c30);

	HAL_I2C_Mem_Write(&hi2c4,ISP_WRITE,PRS_CFG,I2C_MEMADD_SIZE_8BIT,&Init[3],1,1000);
	HAL_I2C_Mem_Write(&hi2c4,ISP_WRITE,TMP_CFG,I2C_MEMADD_SIZE_8BIT,&Init[0],1,1000);
	HAL_I2C_Mem_Write(&hi2c4,ISP_WRITE,CFG_REG,I2C_MEMADD_SIZE_8BIT,&Init[4],1,1000);
	
	HAL_I2C_Mem_Write(&hi2c4,ISP_WRITE,MEAS_CFG,I2C_MEMADD_SIZE_8BIT,&Init[1],1,1000);
}

void DPS310_ReadDate(float * P, float * Me)
{
	uint8_t Temp[3];
	static uint8_t count = 0; 
	double exponent,ratio,altitude;
	float T;
	
	HAL_I2C_Mem_Read(&hi2c4,ISP_READ,MEAS_CFG,I2C_MEMADD_SIZE_8BIT,Temp,1,1000);
	if(count++ > 10)
	{
		HAL_I2C_Mem_Read(&hi2c4,ISP_READ,TMP_BX,I2C_MEMADD_SIZE_8BIT,Temp,3,1000);
		Temperature = (Temp[0]<<16)+(Temp[1]<<8)+Temp[2];
		if(Temperature > 8388608-1)Temperature = Temperature - 16777216;
		T = c0*0.5+c1*(Temperature/7864320.0f);
		count = 0;
	}
	if(Temp[0] & 0x10)
	{
		HAL_I2C_Mem_Read(&hi2c4,ISP_READ,PSR_BX,I2C_MEMADD_SIZE_8BIT,Temp,3,1000);
		Pressure = (Temp[0]<<16)+(Temp[1]<<8)+Temp[2];
		if(Pressure > 8388608-1)Pressure = Pressure - 16777216;
		*P = c00 + Pressure/1040384.0f*(c10+Pressure/1040384.0f*(c20+Pressure/1040384.0f*c30))+ (Temperature/7864320.0f)*c01+(Temperature/7864320.0f)*(Pressure/1040384.0f)*(c11+(Pressure/1040384.0f)*c21);
		exponent = (g * M) / (R * L);
		ratio = *P / P0;
		altitude = (T0 / L) * (1 - pow(ratio, 1.0 / exponent));
		*Me = altitude;
	}
}

