#include "gps.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void parse_gprmc(char *sentence, GPRMC_Data *data) 
{	
	char *rest = (char *)malloc(strlen(sentence) + 1); 
	if (rest == NULL) {
			return;
	}
	strcpy(rest, sentence); 
	char *token;
	int field = 0;
	memset(data, 0, sizeof(GPRMC_Data));
	
	token = strtok(rest, ",");
	while (token != NULL) {
			switch (field) 
				{
					case 0: // 消息类型 (已验证是GPRMC)
							break;
					case 1: // UTC时间
							strncpy(data->utc_time, token, sizeof(data->utc_time)-1);
							if(strlen(token) >= 6) {  // 确保有hhmmss部分
                    char time_str[7];
                    strncpy(time_str, token, 6); // 提取hhmmss
                    time_str[6] = '\0';
                    
                    // 转换为整数
                    char hms[3][3]; // 存储小时、分钟、秒的字符串
                    memcpy(hms[0], time_str, 2); hms[0][2] = '\0';   // 小时
                    memcpy(hms[1], time_str+2, 2); hms[1][2] = '\0'; // 分钟
                    memcpy(hms[2], time_str+4, 2); hms[2][2] = '\0'; // 秒
                    
                    data->hours = atoi(hms[0]) + 8;
                    data->minutes = atoi(hms[1]);
                    
										if(data->hours >= 24)
											data->hours -= 24;
                }
							break;
					case 2: // 状态
							data->status = token[0];
							break;
					case 3: // 纬度
							data->latitude = atof(token);
							break;
					case 4: // 纬度方向
							data->lat_dir = token[0];
							break;
					case 5: // 经度
							data->longitude = atof(token);
							break;
					case 6: // 经度方向
							data->lon_dir = token[0];
							break;
					case 7: // 地面速度
							data->speed = atof(token);
							data->speed = data->speed * 1.852f;
							break;
					case 8: // 地面航向
							data->course = atof(token);
							break;
					case 9: // UTC日期
							strncpy(data->date, token, sizeof(data->date)-1);
							break;
					case 10: // 磁偏角 (可选)
							if (strlen(token) > 0) data->mag_var = atof(token);
							break;
					case 11: // 磁偏角方向 (可选)
							if (strlen(token) > 0) data->var_dir = token[0];
							break;
			}
			token = strtok(NULL, ",");
			field++;
	}
	
	free(rest); // 释放临时副本
}

//void parse_gprmc(char *sentence, GPRMC_Data *data) 
//{	
//	char *rest = (char *)malloc(strlen(sentence) + 1); // 分配内存
//	if (rest == NULL) {
//			return;
//	}
//	strcpy(rest, sentence); // 复制字符串

//	char *token;
//	int field = 0;
//	
//	// 初始化数据结构
//	memset(data, 0, sizeof(GPRMC_Data));
//	
//	token = strtok(rest, ",");
//	while (token != NULL) {
//			switch (field) 
//				{
//					case 0: // 消息类型 (已验证是GPRMC)
//							break;
//					case 1: // UTC时间
//							strncpy(data->utc_time, token, sizeof(data->utc_time)-1);
//							break;
//					case 2: // 状态
//							data->status = token[0];
//							break;
//					case 3: // 纬度
//							data->latitude = atof(token);
//							break;
//					case 4: // 纬度方向
//							data->lat_dir = token[0];
//							break;
//					case 5: // 经度
//							data->longitude = atof(token);
//							break;
//					case 6: // 经度方向
//							data->lon_dir = token[0];
//							break;
//					case 7: // 地面速度
//							data->speed = atof(token);
//							break;
//					case 8: // 地面航向
//							data->course = atof(token);
//							break;
//					case 9: // UTC日期
//							strncpy(data->date, token, sizeof(data->date)-1);
//							break;
//					case 10: // 磁偏角 (可选)
//							if (strlen(token) > 0) data->mag_var = atof(token);
//							break;
//					case 11: // 磁偏角方向 (可选)
//							if (strlen(token) > 0) data->var_dir = token[0];
//							break;
//			}
//			token = strtok(NULL, ",");
//			field++;
//	}
//	
//	free(rest); // 释放临时副本
//}

