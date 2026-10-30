#ifndef __DPS310_H
#define __DPS310_H

#include "stdlib.h"
#include "main.h"
#include "i2c.h"

#define ISP_ADD    	0X76
#define ISP_READ    (ISP_ADD<<1)+1
#define ISP_WRITE   (ISP_ADD<<1)

#define PSR_BX    	0X00
#define TMP_BX    	0X03

#define PRS_CFG   	0X06   //0X33
#define TMP_CFG   	0X07   //0X33
#define MEAS_CFG   	0X08
#define CFG_REG   	0X09
#define INT_STS   	0X0A
#define FIFO_STS   	0X0B
#define RESET   	  0X0C

#define COEF   	    0X10
/*
C0  [11:0] 	0X10 + 0X11[7:4]
C1  [11:0] 	0X11[3:0] + 0X12  
C00 [19:0]  0X13 + 0X14 = 0X15[7:4]
C10 [19:0]  0X15[3:0] + 0X16 + 0X17
C01 [15:0]  0X18 + 0X19
C11 [15:0]  0X1A + 0X1B
C20 [15:0]  0X1C + 0X1D
C21 [15:0]  0X1E + 0X1F
C30 [15:0]  0X20 + 0X21
*/

void DSP310_Init(void);
void DPS310_ReadDate(float * P, float * M);

#endif



