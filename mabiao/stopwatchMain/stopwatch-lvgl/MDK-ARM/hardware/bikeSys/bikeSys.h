#ifndef __BIKESYS_H
#define __BIKESYS_H

#include "stdbool.h"
#include "main.h"

typedef struct
{
	bool GPS_Flag;
	bool BLUE_Flag;
	bool RUN_Flag;
//	char TEMP_Flag;
	bool LIGHT_Flag;
	bool AUTO_STOP_Flag;
	char AUTO_DATA_Flag;
	uint8_t auto_stopTime;
	char altitude[7];
	float temperature, alt;
	
	float pitch, roll, yaw;
	
	char runTime[20];
	uint8_t runSecond;
	uint8_t runMin;
	uint8_t runHour;
	
	float allKm;
	char allLong[7];
	
	char speeD[7];
	char realtime[10];
	
	float avgSpeed;
	char avgspeed[9];
	
	float maxSpeed;
	char maxspeed[9];
	
	float tp;
	char TP[9];
	
	uint16_t direction;
	char Direction[7];
	
	uint8_t skp;
	uint8_t ctlFlag;
	uint8_t turnFlag;
	uint8_t turnState;
	uint8_t currentScr;
	
}bikeSys;

#endif



