#include "ctp.h"
#include "ctiic.h"
#include "main.h"
#include "string.h"
#include "stdio.h"

_m_tp_dev tp_dev;

uint8_t FT6336_WR_Reg(uint16_t reg,uint8_t *buf,uint8_t len)
{
	uint8_t i;
	uint8_t ret=0;
	CT_IIC_Start();	 
	CT_IIC_Send_Byte(FT_CMD_WR);	//发送写命令 	 
	CT_IIC_Wait_Ack(); 	 										  		   
	CT_IIC_Send_Byte(reg&0XFF);   	//发送低8位地址
	CT_IIC_Wait_Ack();  
	for(i=0;i<len;i++)
	{	   
    	CT_IIC_Send_Byte(buf[i]);  	//发数据
		ret=CT_IIC_Wait_Ack();
		if(ret)break;  
	}
  CT_IIC_Stop();					//产生一个停止条件	    
	return ret; 
}
//从FT6336读出一次数据
//reg:起始寄存器地址
//buf:数据缓缓存区
//len:读数据长度			  
void FT6336_RD_Reg(uint16_t reg,uint8_t *buf,uint8_t len)
{
	uint8_t i; 
 	CT_IIC_Start();	
 	CT_IIC_Send_Byte(FT_CMD_WR);   	//发送写命令 
	CT_IIC_Wait_Ack();
 	CT_IIC_Send_Byte(reg);   	
	CT_IIC_Wait_Ack();  
 	CT_IIC_Start();  	 	   
	CT_IIC_Send_Byte(FT_CMD_RD);   	//发送读命令		   
	CT_IIC_Wait_Ack();	   
	for(i=0;i<len;i++)
	{	   
    	buf[i]=CT_IIC_Read_Byte(i==(len-1)?0:1); //发数据	  
	} 
  CT_IIC_Stop();//产生一个停止条件     
} 
//初始化FT6336触摸屏
uint8_t FT6336_Init(void)
{
	uint8_t temp[2];
	
	CT_IIC_GPIO_Init();      	//初始化电容屏的I2C总线  
	FT_RST_0();				//复位
	HAL_Delay(20);
 	FT_RST_1();				//释放复位		    
	HAL_Delay(300);  	
	
	tp_dev.touchtype = 1;
	FT6336_RD_Reg(FT_ID_G_FOCALTECH_ID,&temp[0],1);
	if(temp[0]!=0x11)
	{
			return 1;
	}

	return 0;
}


 
const uint16_t FT6336_TPX_TBL[2]={FT_TP1_REG,FT_TP2_REG};

uint8_t FT6336_Scan(void)
{
    uint8_t buf[4];
    uint8_t i=0;
    uint8_t res=0;
    uint8_t temp;
    uint8_t mode;
		uint16_t change[2];
		uint16_t tempsta;
    static uint8_t t=0;
    t++;
    if((t%10)==0||t<10)
    {
        FT6336_RD_Reg(FT_REG_NUM_FINGER,&mode,1);
				if((mode & 0X80) && ((mode & 0XF) <= CT_USE_TOUCH))
        {
            i = 0;
            FT6336_RD_Reg(FT_REG_NUM_FINGER,&mode,1);             /* 清标志 */
        }
        if((mode & 0XF)&&((mode & 0xF) <= CT_USE_TOUCH))
        {
            temp= 0XFF << (mode & 0XF);
						tempsta = tp_dev.sta;
            tp_dev.sta= (~temp) | TP_PRES_DOWN | TP_CATH_PRES; 
						tp_dev.x[CT_USE_TOUCH - 1] = tp_dev.x[0];           
            tp_dev.y[CT_USE_TOUCH - 1] = tp_dev.y[0];
					
            for(i = 0; i < CT_MAX_TOUCH; i++)
            {	
							
							if(tp_dev.sta & (1 << i))   
							{
								FT6336_RD_Reg(FT6336_TPX_TBL[i],buf,4);
								
								change[0] = 320 - (((uint16_t)(buf[0]&0X0F)<<8)+buf[1]);
								
								change[1] = ((uint16_t)(buf[2])<<8) + buf[3]; 
								
								if(change[0] <= 320 && change[1] <= 480 && change[0] > 0 && change[1] > 0 )
								{
									tp_dev.y[i]=change[0];
									tp_dev.x[i]=change[1];
									//printf("X:%d , Y:%d\r\n",change[1],change[0]);									
								}
								memset(buf,0,4);
							}            
            } 
            res=1;
						if (tp_dev.x[0] > 480 || tp_dev.y[0] > 320)
						{
							if ((mode & 0XF) > 1)                                       /* 有其他点有数据,则复第二个触点的数据到第一个触点. */
                {
                    tp_dev.x[0] = tp_dev.x[1];
                    tp_dev.y[0] = tp_dev.y[1];
                    t = 0;                                                  /* 触发一次,则会最少连续监测10次,从而提高命中率 */
                }
                else                                                        /* 非法数据,则忽略此次数据(还原原来的) */
                {
                    tp_dev.x[0] = tp_dev.x[CT_USE_TOUCH - 1];
                    tp_dev.y[0] = tp_dev.y[CT_USE_TOUCH - 1];
                    mode = 0X80;
                    tp_dev.sta = tempsta;                                   /* 恢复tp_dev.sta */
                }
						}
            else
							t=0;        
        }
    }
    if((mode & 0X8F) == 0X80)                                              /* 无触摸点按下 */
    { 
        if(tp_dev.sta & TP_PRES_DOWN)    //之前是被按下的
        {
            tp_dev.sta &= ~TP_PRES_DOWN;      //标记按键松开
        }
				else                        //之前就没有被按下
        { 
            tp_dev.x[0] = 0xffff;
            tp_dev.y[0] = 0xffff;
            tp_dev.sta &= 0XE0;    //清除点有效标记    
        }     
    } 
    if(t>240)t=10;//重新从10开始计数
		
    return res;
}

