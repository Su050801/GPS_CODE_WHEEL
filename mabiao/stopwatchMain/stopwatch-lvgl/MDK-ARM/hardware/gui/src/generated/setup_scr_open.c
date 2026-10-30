/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_open(lv_ui *ui)
{
    //Write codes open
    ui->open = lv_obj_create(NULL);
    lv_obj_set_size(ui->open, 480, 320);
    lv_obj_set_scrollbar_mode(ui->open, LV_SCROLLBAR_MODE_OFF);

    //Write style for open, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->open, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->open, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->open, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes open_open_bar
    ui->open_open_bar = lv_bar_create(ui->open);
    lv_obj_set_style_anim_time(ui->open_open_bar, 700, 0);
    lv_bar_set_mode(ui->open_open_bar, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->open_open_bar, 0, 100);
    lv_bar_set_value(ui->open_open_bar, 100, LV_ANIM_ON);
    lv_obj_set_pos(ui->open_open_bar, 116, 106);
    lv_obj_set_size(ui->open_open_bar, 243, 72);

    //Write style for open_open_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->open_open_bar, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->open_open_bar, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->open_open_bar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->open_open_bar, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->open_open_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->open_open_bar, &_stopwatch_243x72, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->open_open_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->open_open_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for open_open_bar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->open_open_bar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->open_open_bar, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->open_open_bar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->open_open_bar, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->open_open_bar, &_stopwatch_243x72, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->open_open_bar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->open_open_bar, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes open_open_bar1
    ui->open_open_bar1 = lv_bar_create(ui->open);
    lv_obj_set_style_anim_time(ui->open_open_bar1, 700, 0);
    lv_bar_set_mode(ui->open_open_bar1, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->open_open_bar1, 0, 100);
    lv_bar_set_value(ui->open_open_bar1, 0, LV_ANIM_OFF);
    lv_obj_set_pos(ui->open_open_bar1, 137, 197);
    lv_obj_set_size(ui->open_open_bar1, 200, 6);

    //Write style for open_open_bar1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->open_open_bar1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->open_open_bar1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->open_open_bar1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->open_open_bar1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->open_open_bar1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for open_open_bar1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->open_open_bar1, 235, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->open_open_bar1, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->open_open_bar1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->open_open_bar1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes open_btn_1
    ui->open_btn_1 = lv_btn_create(ui->open);
    ui->open_btn_1_label = lv_label_create(ui->open_btn_1);
    lv_label_set_text(ui->open_btn_1_label, "GO");
    lv_label_set_long_mode(ui->open_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->open_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->open_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->open_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->open_btn_1, 200, 240);
    lv_obj_set_size(ui->open_btn_1, 80, 50);

    //Write style for open_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->open_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->open_btn_1, lv_color_hex(0x5b8fe2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->open_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->open_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->open_btn_1, 18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->open_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->open_btn_1, lv_color_hex(0xe2f7fa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->open_btn_1, &lv_font_montserratMedium_45, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->open_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->open_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for open_btn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->open_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->open_btn_1, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->open_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->open_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->open_btn_1, 20, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->open_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->open_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->open_btn_1, &lv_font_montserratMedium_45, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->open_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //The custom code of open.


    //Update current screen layout.
    lv_obj_update_layout(ui->open);

    //Init events for screen.
    events_init_open(ui);
}
