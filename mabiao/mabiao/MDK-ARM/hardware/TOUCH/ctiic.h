#ifndef __MYCT_IIC_H
#define __MYCT_IIC_H

#include <inttypes.h>
#define CT_IIC_WR	0		/* 写控制bit */
#define CT_IIC_RD	1		/* 读控制bit */
//IIC所有操作函数
void CT_IIC_Start(void);
void CT_IIC_Stop(void);
void CT_IIC_Send_Byte(uint8_t _ucByte);
uint8_t CT_IIC_Read_Byte(uint8_t ack);
uint8_t CT_IIC_Wait_Ack(void);
void CT_IIC_Ack(void);
void CT_IIC_NAck(void);
uint8_t CT_IIC_CheckDevice(uint8_t _Address);
void CT_IIC_GPIO_Init(void);

#endif







