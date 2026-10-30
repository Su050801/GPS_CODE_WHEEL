#ifndef __IST8301_H
#define __IST8301_H

#include "stdlib.h"
#include "main.h"
#include "i2c.h"

/**
 * @Author         : Minghang Li
 * @Date           : 2022-12-03 15:27
 * @LastEditTime   : 2022-12-03 16:53
 * @Note           :
 * @Copyright(c)   : Minghang Li Copyright
 */

/*-----IST8310¼Ä´æÆ÷µØÖ·-----*/
#define IST8310_I2C_ADDR   0x18
#define IST8310_CHIP_ID_ADDR 0x00
#define IST8310_CHIP_ID_VAL 0x10

#define IST8310_STAT1_ADDR 0x02
#define IST8310_DATA_XL_ADDR 0x03
#define IST8310_DATA_XH_ADDR 0x04
#define IST8310_DATA_YL_ADDR 0x05
#define IST8310_DATA_YH_ADDR 0x06
#define IST8310_DATA_ZL_ADDR 0x07
#define IST8310_DATA_ZH_ADDR 0x08

#define IST8310_STAT2_ADDR 0x09

#define IST8310_CNTL1_ADDR 0x0A
#define IST8310_CNTL1_SLEEP 0x00
#define IST8310_CNTL1_SINGLE 0x01
#define IST8310_CNTL1_CONTINUE 0x0B

#define IST8310_CNTL2_ADDR 0x0B
#define IST8310_STAT2_NONE_ALL 0x00

#define IST8310_SELF_CHECK_ADDR 0x0C

#define IST8310_TEMPL_ADDR 0x1C
#define IST8310_TEMPH_ADDR 0x1D

#define IST8310_AVGCNTL_ADDR 0x41
#define IST8310_AVGCNTL_TWICE 0x09
#define IST8310_AVGCNTL_FOURTH 0x12

void IST8310_Init(void);
uint16_t IST8310_ReadData(void);
float calculate_heading(float mx, float my);
#endif



