#ifndef __GPS_H
#define __GPS_H

typedef struct {
    char utc_time[11];      // UTC时间 (HHMMSS.sss)
		int hours;
		int minutes;
	  float seconds;
    char status;            // 状态 (A=有效, V=无效)
    double latitude;        // 纬度 (DDMM.MMMM)
    char lat_dir;           // 纬度方向 (N/S)
    double longitude;       // 经度 (DDDMM.MMMM)
    char lon_dir;           // 经度方向 (E/W)
    float speed;            // 地面速度 (节)
    float course;           // 地面航向 (度)
    char date[7];           // UTC日期 (DDMMYY)
    float mag_var;          // 磁偏角 (可选)
    char var_dir;           // 磁偏角方向 (可选)
//    char mode;              // 模式指示 (A=自主, D=差分, E=估算, N=无效)
} GPRMC_Data;

//typedef struct {
//    char utc_time[11];      // UTC时间 (HHMMSS.sss)
//    char status;            // 状态 (A=有效, V=无效)
//    double latitude;        // 纬度 (DDMM.MMMM)
//    char lat_dir;           // 纬度方向 (N/S)
//    double longitude;       // 经度 (DDDMM.MMMM)
//    char lon_dir;           // 经度方向 (E/W)
//    float speed;            // 地面速度 (节)
//    float course;           // 地面航向 (度)
//    char date[7];           // UTC日期 (DDMMYY)
//    float mag_var;          // 磁偏角 (可选)
//    char var_dir;           // 磁偏角方向 (可选)
////    char mode;              // 模式指示 (A=自主, D=差分, E=估算, N=无效)
//} GPRMC_Data;

void parse_gprmc(char *sentence, GPRMC_Data *data);

#endif



