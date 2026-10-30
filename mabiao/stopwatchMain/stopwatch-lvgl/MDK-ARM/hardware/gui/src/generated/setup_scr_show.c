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



void setup_scr_show(lv_ui *ui)
{
    //Write codes show
    ui->show = lv_obj_create(NULL);
    lv_obj_set_size(ui->show, 480, 320);
    lv_obj_set_scrollbar_mode(ui->show, LV_SCROLLBAR_MODE_OFF);

    //Write style for show, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->show, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->show, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->show, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_mspeed
    ui->show_mspeed = lv_obj_create(ui->show);
    lv_obj_set_pos(ui->show_mspeed, 0, 26);
    lv_obj_set_size(ui->show_mspeed, 480, 105);
    lv_obj_set_scrollbar_mode(ui->show_mspeed, LV_SCROLLBAR_MODE_OFF);

    //Write style for show_mspeed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_mspeed, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->show_mspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->show_mspeed, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->show_mspeed, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_mspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_mspeed, 188, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->show_mspeed, lv_color_hex(0x252828), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->show_mspeed, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_mspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_mspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_mspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_mspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_mspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_speed
    ui->show_speed = lv_label_create(ui->show_mspeed);
    lv_label_set_text(ui->show_speed, "0");
    lv_label_set_long_mode(ui->show_speed, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_speed, 180, 14);
    lv_obj_set_size(ui->show_speed, 119, 45);

    //Write style for show_speed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_speed, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_speed, &lv_font_montserratMedium_45, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_speed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_speed, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_spe
    ui->show_spe = lv_label_create(ui->show_mspeed);
    lv_label_set_text(ui->show_spe, "Km/h");
    lv_label_set_long_mode(ui->show_spe, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_spe, 212, 62);
    lv_obj_set_size(ui->show_spe, 55, 21);

    //Write style for show_spe, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_spe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_spe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_spe, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_spe, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_spe, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_spe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_spe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_spe, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_spe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_spe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_spe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_spe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_spe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_spe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_ange
    ui->show_ange = lv_label_create(ui->show_mspeed);
    lv_label_set_text(ui->show_ange, "0°");
    lv_label_set_long_mode(ui->show_ange, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_ange, 70, 57);
    lv_obj_set_size(ui->show_ange, 31, 16);

    //Write style for show_ange, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_ange, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_ange, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_ange, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_ange, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_ange, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_ange, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_ange, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_ange, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_ange, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_ange, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_ange, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_ange, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_ange, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_ange, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_line_2
    ui->show_line_2 = lv_line_create(ui->show_mspeed);
    static lv_point_t show_line_2[] = {{50, 50},{0, 50},};
    lv_line_set_points(ui->show_line_2, show_line_2, 2);
    lv_obj_set_pos(ui->show_line_2, 15, 25);
    lv_obj_set_size(ui->show_line_2, 50, 50);

    //Write style for show_line_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->show_line_2, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->show_line_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->show_line_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->show_line_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_angle
    ui->show_angle = lv_line_create(ui->show_mspeed);
    static lv_point_t show_angle[] = {{50, 28},{0, 45},};
    lv_line_set_points(ui->show_angle, show_angle, 2);
    lv_obj_set_pos(ui->show_angle, 15, 30);
    lv_obj_set_size(ui->show_angle, 50, 70);

    //Write style for show_angle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->show_angle, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->show_angle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->show_angle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->show_angle, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_north
    ui->show_north = lv_label_create(ui->show_mspeed);
    lv_label_set_text(ui->show_north, "N");
    lv_label_set_long_mode(ui->show_north, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_north, 405, 4);
    lv_obj_set_size(ui->show_north, 31, 16);

    //Write style for show_north, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_north, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_north, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_north, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_north, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_north, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_north, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_north, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_north, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_north, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_north, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_north, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_north, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_north, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_north, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_south
    ui->show_south = lv_label_create(ui->show_mspeed);
    lv_label_set_text(ui->show_south, "S");
    lv_label_set_long_mode(ui->show_south, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_south, 405, 80);
    lv_obj_set_size(ui->show_south, 31, 16);

    //Write style for show_south, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_south, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_south, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_south, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_south, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_south, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_south, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_south, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_south, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_south, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_south, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_south, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_south, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_south, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_south, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_western
    ui->show_western = lv_label_create(ui->show_mspeed);
    lv_label_set_text(ui->show_western, "W");
    lv_label_set_long_mode(ui->show_western, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_western, 367, 45);
    lv_obj_set_size(ui->show_western, 31, 16);

    //Write style for show_western, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_western, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_western, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_western, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_western, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_western, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_western, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_western, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_western, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_western, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_western, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_western, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_western, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_western, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_western, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_east
    ui->show_east = lv_label_create(ui->show_mspeed);
    lv_label_set_text(ui->show_east, "E");
    lv_label_set_long_mode(ui->show_east, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_east, 452, 44);
    lv_obj_set_size(ui->show_east, 20, 17);

    //Write style for show_east, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_east, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_east, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_east, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_east, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_label_13
    ui->show_label_13 = lv_label_create(ui->show_mspeed);
    lv_label_set_text(ui->show_label_13, "124°");
    lv_label_set_long_mode(ui->show_label_13, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_label_13, 398, 45);
    lv_obj_set_size(ui->show_label_13, 49, 16);

    //Write style for show_label_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_label_13, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_label_13, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_label_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_label_13, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_start
    ui->show_start = lv_btn_create(ui->show);
    lv_obj_add_flag(ui->show_start, LV_OBJ_FLAG_CHECKABLE);
    ui->show_start_label = lv_label_create(ui->show_start);
    lv_label_set_text(ui->show_start_label, " " LV_SYMBOL_PLAY " ");
    lv_label_set_long_mode(ui->show_start_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->show_start_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->show_start, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->show_start_label, LV_PCT(100));
    lv_obj_set_pos(ui->show_start, 215, 275);
    lv_obj_set_size(ui->show_start, 65, 40);

    //Write style for show_start, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->show_start, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->show_start, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->show_start, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->show_start, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_start, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_start, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_start, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_start, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_start, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_start, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for show_start, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->show_start, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->show_start, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->show_start, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->show_start, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->show_start, 5, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->show_start, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->show_start, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->show_start, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->show_start, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for show_start, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->show_start, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->show_start, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->show_start, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->show_start, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->show_start, 5, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->show_start, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->show_start, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->show_start, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->show_start, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes show_gps
    ui->show_gps = lv_label_create(ui->show);
    lv_label_set_text(ui->show_gps, "" LV_SYMBOL_GPS " ");
    lv_label_set_long_mode(ui->show_gps, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_gps, 6, 4);
    lv_obj_set_size(ui->show_gps, 26, 18);

    //Write style for show_gps, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_gps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_gps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_gps, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_gps, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_gps, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_gps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_gps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_gps, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_gps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_gps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_gps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_gps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_gps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_gps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_sdcard
    ui->show_sdcard = lv_label_create(ui->show);
    lv_label_set_text(ui->show_sdcard, "" LV_SYMBOL_SD_CARD " ");
    lv_label_set_long_mode(ui->show_sdcard, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_sdcard, 36, 4);
    lv_obj_set_size(ui->show_sdcard, 14, 18);

    //Write style for show_sdcard, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_sdcard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_sdcard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_sdcard, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_sdcard, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_sdcard, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_sdcard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_sdcard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_sdcard, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_sdcard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_sdcard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_sdcard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_sdcard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_sdcard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_sdcard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_battery
    ui->show_battery = lv_label_create(ui->show);
    lv_label_set_text(ui->show_battery, "" LV_SYMBOL_BATTERY_3 " ");
    lv_label_set_long_mode(ui->show_battery, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_battery, 440, 4);
    lv_obj_set_size(ui->show_battery, 26, 18);

    //Write style for show_battery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_battery, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_battery, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_battery, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_battery, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_time
    ui->show_time = lv_label_create(ui->show);
    lv_label_set_text(ui->show_time, "12:35");
    lv_label_set_long_mode(ui->show_time, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_time, 380, 5);
    lv_obj_set_size(ui->show_time, 60, 15);

    //Write style for show_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_time, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_logo
    ui->show_logo = lv_label_create(ui->show);
    lv_label_set_text(ui->show_logo, "STOPWATCH");
    lv_label_set_long_mode(ui->show_logo, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_logo, 183, 8);
    lv_obj_set_size(ui->show_logo, 114, 20);

    //Write style for show_logo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_logo, lv_color_hex(0x283123), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_logo, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_logo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_logo, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_end
    ui->show_end = lv_btn_create(ui->show);
    ui->show_end_label = lv_label_create(ui->show_end);
    lv_label_set_text(ui->show_end_label, " " LV_SYMBOL_STOP " ");
    lv_label_set_long_mode(ui->show_end_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->show_end_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->show_end, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->show_end_label, LV_PCT(100));
    lv_obj_set_pos(ui->show_end, 50, 275);
    lv_obj_set_size(ui->show_end, 65, 40);

    //Write style for show_end, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->show_end, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->show_end, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->show_end, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->show_end, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_end, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_end, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_end, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_end, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_end, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_end, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for show_end, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->show_end, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->show_end, lv_color_hex(0xff7b24), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->show_end, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->show_end, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->show_end, 5, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->show_end, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->show_end, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->show_end, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->show_end, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for show_end, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->show_end, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->show_end, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->show_end, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->show_end, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->show_end, 5, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->show_end, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->show_end, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->show_end, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->show_end, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes show_menu
    ui->show_menu = lv_btn_create(ui->show);
    ui->show_menu_label = lv_label_create(ui->show_menu);
    lv_label_set_text(ui->show_menu_label, " " LV_SYMBOL_BARS " ");
    lv_label_set_long_mode(ui->show_menu_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->show_menu_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->show_menu, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->show_menu_label, LV_PCT(100));
    lv_obj_set_pos(ui->show_menu, 380, 275);
    lv_obj_set_size(ui->show_menu, 65, 40);

    //Write style for show_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->show_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->show_menu, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->show_menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->show_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_menu, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_menu, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_menu, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_menu, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for show_menu, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->show_menu, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->show_menu, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->show_menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->show_menu, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->show_menu, 5, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->show_menu, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->show_menu, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->show_menu, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->show_menu, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write codes show_cont_1
    ui->show_cont_1 = lv_obj_create(ui->show);
    lv_obj_set_pos(ui->show_cont_1, 0, 140);
    lv_obj_set_size(ui->show_cont_1, 480, 130);
    lv_obj_set_scrollbar_mode(ui->show_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for show_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_cont_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->show_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->show_cont_1, lv_color_hex(0x181818), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->show_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_cont_1, 177, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->show_cont_1, lv_color_hex(0x240000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->show_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_allKm
    ui->show_allKm = lv_label_create(ui->show_cont_1);
    lv_label_set_text(ui->show_allKm, "0.0Km");
    lv_label_set_long_mode(ui->show_allKm, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_allKm, 10, 16);
    lv_obj_set_size(ui->show_allKm, 70, 17);

    //Write style for show_allKm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_allKm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_allKm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_allKm, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_allKm, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_allKm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_allKm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_allKm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_allKm, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_allKm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_allKm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_allKm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_allKm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_allKm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_allKm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_allkm
    ui->show_allkm = lv_label_create(ui->show_cont_1);
    lv_label_set_text(ui->show_allkm, "ALL\n");
    lv_label_set_long_mode(ui->show_allkm, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_allkm, 18, 36);
    lv_obj_set_size(ui->show_allkm, 46, 17);

    //Write style for show_allkm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_allkm, lv_color_hex(0x6a6a6a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_allkm, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_allkm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_allkm, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_label_2
    ui->show_label_2 = lv_label_create(ui->show_cont_1);
    lv_label_set_text(ui->show_label_2, "ALT\n");
    lv_label_set_long_mode(ui->show_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_label_2, 220, 36);
    lv_obj_set_size(ui->show_label_2, 33, 17);

    //Write style for show_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_label_2, lv_color_hex(0x6a6a6a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_label_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_pressure
    ui->show_pressure = lv_label_create(ui->show_cont_1);
    lv_label_set_text(ui->show_pressure, "0M");
    lv_label_set_long_mode(ui->show_pressure, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_pressure, 203, 15);
    lv_obj_set_size(ui->show_pressure, 70, 17);

    //Write style for show_pressure, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_pressure, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_pressure, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_pressure, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_pressure, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_label_3
    ui->show_label_3 = lv_label_create(ui->show_cont_1);
    lv_label_set_text(ui->show_label_3, "0R/m");
    lv_label_set_long_mode(ui->show_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_label_3, 387, 15);
    lv_obj_set_size(ui->show_label_3, 88, 17);

    //Write style for show_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_label_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_avgSpeed
    ui->show_avgSpeed = lv_label_create(ui->show_cont_1);
    lv_label_set_text(ui->show_avgSpeed, "0.0Km/h");
    lv_label_set_long_mode(ui->show_avgSpeed, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_avgSpeed, 3, 82);
    lv_obj_set_size(ui->show_avgSpeed, 87, 17);

    //Write style for show_avgSpeed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_avgSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_avgSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_avgSpeed, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_avgSpeed, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_avgSpeed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_avgSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_avgSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_avgSpeed, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_avgSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_avgSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_avgSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_avgSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_avgSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_avgSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_label_5
    ui->show_label_5 = lv_label_create(ui->show_cont_1);
    lv_label_set_text(ui->show_label_5, "TP\n");
    lv_label_set_long_mode(ui->show_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_label_5, 409, 36);
    lv_obj_set_size(ui->show_label_5, 46, 17);

    //Write style for show_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_label_5, lv_color_hex(0x6a6a6a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_label_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_label_6
    ui->show_label_6 = lv_label_create(ui->show_cont_1);
    lv_label_set_text(ui->show_label_6, "AVG");
    lv_label_set_long_mode(ui->show_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_label_6, 18, 102);
    lv_obj_set_size(ui->show_label_6, 46, 17);

    //Write style for show_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_label_6, lv_color_hex(0x6a6a6a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_label_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_label_10
    ui->show_label_10 = lv_label_create(ui->show_cont_1);
    lv_label_set_text(ui->show_label_10, "MAX\n");
    lv_label_set_long_mode(ui->show_label_10, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_label_10, 214, 102);
    lv_obj_set_size(ui->show_label_10, 46, 17);

    //Write style for show_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_label_10, lv_color_hex(0x6a6a6a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_label_10, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_label_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_maxSpeed
    ui->show_maxSpeed = lv_label_create(ui->show_cont_1);
    lv_label_set_text(ui->show_maxSpeed, "0.0Km/h\n");
    lv_label_set_long_mode(ui->show_maxSpeed, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_maxSpeed, 191, 82);
    lv_obj_set_size(ui->show_maxSpeed, 99, 17);

    //Write style for show_maxSpeed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_maxSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_maxSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_maxSpeed, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_maxSpeed, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_maxSpeed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_maxSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_maxSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_maxSpeed, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_maxSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_maxSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_maxSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_maxSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_maxSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_maxSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_label_12
    ui->show_label_12 = lv_label_create(ui->show_cont_1);
    lv_label_set_text(ui->show_label_12, "TIME");
    lv_label_set_long_mode(ui->show_label_12, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_label_12, 412, 102);
    lv_obj_set_size(ui->show_label_12, 46, 17);

    //Write style for show_label_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_label_12, lv_color_hex(0x6a6a6a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_label_12, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_label_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_runTime
    ui->show_runTime = lv_label_create(ui->show_cont_1);
    lv_label_set_text(ui->show_runTime, "0:0:0");
    lv_label_set_long_mode(ui->show_runTime, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->show_runTime, 397, 82);
    lv_obj_set_size(ui->show_runTime, 70, 17);

    //Write style for show_runTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->show_runTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_runTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->show_runTime, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->show_runTime, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->show_runTime, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->show_runTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->show_runTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->show_runTime, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->show_runTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->show_runTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->show_runTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->show_runTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->show_runTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->show_runTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_turnRight
    ui->show_turnRight = lv_img_create(ui->show);
    lv_obj_add_flag(ui->show_turnRight, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->show_turnRight, &_yl_alpha_55x22);
    lv_img_set_pivot(ui->show_turnRight, 0,0);
    lv_img_set_angle(ui->show_turnRight, 0);
    lv_obj_set_pos(ui->show_turnRight, 329, 3);
    lv_obj_set_size(ui->show_turnRight, 55, 22);

    //Write style for show_turnRight, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->show_turnRight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->show_turnRight, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_turnRight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->show_turnRight, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes show_turnLeft
    ui->show_turnLeft = lv_img_create(ui->show);
    lv_obj_add_flag(ui->show_turnLeft, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->show_turnLeft, &_yl_alpha_55x22);
    lv_img_set_pivot(ui->show_turnLeft, 0,0);
    lv_img_set_angle(ui->show_turnLeft, 1800);
    lv_obj_set_pos(ui->show_turnLeft, 147, 25);
    lv_obj_set_size(ui->show_turnLeft, 55, 22);

    //Write style for show_turnLeft, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->show_turnLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->show_turnLeft, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->show_turnLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->show_turnLeft, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of show.


    //Update current screen layout.
    lv_obj_update_layout(ui->show);

    //Init events for screen.
    events_init_show(ui);
}
