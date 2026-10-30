/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "main.h"
#include "tim.h"
#include "bikesys.h"
#include "fatfs.h"
#include "gps.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

extern bikeSys bike;
extern GPRMC_Data data;
static void open_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_LONG_PRESSED:
    {
			  bike.currentScr = 1;
        ui_load_scr_animation(&guider_ui, &guider_ui.show, guider_ui.show_del, &guider_ui.open_del, setup_scr_show, LV_SCR_LOAD_ANIM_OVER_TOP, 200, 200, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_open (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->open_btn_1, open_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void show_start_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if(lv_obj_has_state(guider_ui.show_start, LV_STATE_CHECKED) == LV_STATE_CHECKED)
				{
            lv_label_set_text(guider_ui.show_start_label,LV_SYMBOL_PAUSE);
						bike.RUN_Flag = 1;
						//bike.TEMP_Flag = 1;
				}
        else
				{
            lv_label_set_text(guider_ui.show_start_label,LV_SYMBOL_PLAY);
						bike.RUN_Flag = 0;
					  //bike.TEMP_Flag = 3;
				}
    }
    default:
        break;
    }
}

char tempData[100];
char filename[40];
char path[50];
UINT datalong;
FRESULT rres;
static void show_end_event_handler (lv_event_t *e)
{
		FIL fil;
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_LONG_PRESSED:
    {
				bike.RUN_Flag = 0;
        ui_load_scr_animation(&guider_ui, &guider_ui.menu, guider_ui.menu_del, &guider_ui.show_del, setup_scr_menu, LV_SCR_LOAD_ANIM_OVER_TOP, 200, 200, false, false);
			  sprintf(tempData,"TIME: %d:%d:%d",bike.runHour,bike.runMin,bike.runSecond/2);
			  lv_label_set_text(guider_ui.menu_runtime, tempData);
				memset(tempData,0,100);
			
				sprintf(tempData,"MAX Speed: %.1f Km/h",bike.maxSpeed);
			  lv_label_set_text(guider_ui.menu_maxspeed, tempData);
				memset(tempData,0,100);
			
				sprintf(tempData,"AVG Speed: %.1f Km/h",bike.avgSpeed);
			  lv_label_set_text(guider_ui.menu_avgspeed, tempData);
				memset(tempData,0,100);
			
			  sprintf(tempData,"ALL DISTANCE: %.1f Km",bike.allKm);
			  lv_label_set_text(guider_ui.menu_allkm, tempData);
				memset(tempData,0,100);
				
				sprintf(filename,"11-%d-%d.txt",data.hours,data.minutes);
				printf("name:%s\r\n",filename);
				sprintf(path, "data/%s", filename);
				printf("path:%s\r\n",path);
			  sprintf(tempData,"Riding time: %d:%d:%d\r\nRiding distance: %.1fKm\r\nMax Speed: %.1fKm/h\r\nAvg Speed: %.1f",bike.runHour,bike.runMin,bike.runSecond/2,bike.allKm,bike.maxSpeed,bike.avgSpeed);
				printf("tempData:%s\r\n",tempData);
				
				rres = f_open(&fil, path, FA_WRITE | FA_CREATE_ALWAYS);
				if(rres != FR_OK){
					printf("file open fial %d\r\n",rres);
				}else{
					f_write(&fil, tempData, strlen(tempData), &datalong);
					printf("Have write %d byte!\r\n",datalong);
					f_close(&fil);
				}
				lv_label_set_text(guider_ui.show_start_label,LV_SYMBOL_PLAY);
				bike.runHour = 0;
				bike.runMin = 0;
			  bike.runSecond = 0;
				bike.maxSpeed = 0;
				bike.avgSpeed = 0;
				bike.allKm = 0;
				lv_obj_clear_state(guider_ui.show_start, LV_STATE_PRESSED);
				sprintf(tempData,"%d:%d:%d",bike.runHour,bike.runMin,bike.runSecond/2);
				lv_label_set_text(guider_ui.show_runTime, tempData);
				memset(tempData,0,20);
				///////
        break;
    }
    default:
        break;
    }
}

static void show_menu_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.menu, guider_ui.menu_del, &guider_ui.show_del, setup_scr_menu, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 100, false, false);
        break;
    }
    default:
        break;
    }
}

void events_init_show (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->show_start, show_start_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->show_end, show_end_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->show_menu, show_menu_event_handler, LV_EVENT_ALL, ui);
}

static void menu_light_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
		lv_obj_t * slider = lv_event_get_target(e); // 获取触发事件的滑动条对象
    int16_t value = lv_slider_get_value(slider); // 获取当前值
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
				if(bike.LIGHT_Flag == 0)
				{
					htim1.Instance->CCR2 = value * 8 + 200;
				}
        //lv_label_set_text(guider_ui.menu_label_1, "acewac");
        break;
    }
    default:
        break;
    }
}

static void menu_back_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.show, guider_ui.show_del, &guider_ui.menu_del, setup_scr_show, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, true, false);
        break;
    }
    default:
        break;
    }
}

static void menu_ligh_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? true : false;
        //lv_label_set_text(guider_ui.menu_label_1, "asdasf");
				bike.LIGHT_Flag = !bike.LIGHT_Flag;
        break;
    }
    default:
        break;
    }
}

static void menu_stop_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? true : false;
        //lv_label_set_text(guider_ui.menu_label_1, "AutoStop");
			  bike.AUTO_STOP_Flag = !bike.AUTO_STOP_Flag;
        break;
    }
    default:
        break;
    }
}

static void menu_vdata_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? true : false;
        //lv_label_set_text(guider_ui.menu_label_1, "autodata");
				if(bike.AUTO_DATA_Flag)bike.AUTO_DATA_Flag = 0;
				else bike.AUTO_DATA_Flag = 1;
        break;
    }
    default:
        break;
    }
}

void events_init_menu (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->menu_light, menu_light_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu_back, menu_back_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu_ligh, menu_ligh_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu_stop, menu_stop_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu_vdata, menu_vdata_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
