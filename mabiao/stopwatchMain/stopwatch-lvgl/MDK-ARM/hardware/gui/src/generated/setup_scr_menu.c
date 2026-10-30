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



void setup_scr_menu(lv_ui *ui)
{
    //Write codes menu
    ui->menu = lv_obj_create(NULL);
    lv_obj_set_size(ui->menu, 480, 320);
    lv_obj_set_scrollbar_mode(ui->menu, LV_SCROLLBAR_MODE_OFF);

    //Write style for menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menu, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_light
    ui->menu_light = lv_slider_create(ui->menu);
    lv_slider_set_range(ui->menu_light, 0, 100);
    lv_slider_set_mode(ui->menu_light, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->menu_light, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->menu_light, 7, 26);
    lv_obj_set_size(ui->menu_light, 465, 6);

    //Write style for menu_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menu_light, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menu_light, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menu_light, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_light, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->menu_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for menu_light, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menu_light, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menu_light, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menu_light, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_light, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for menu_light, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menu_light, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menu_light, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menu_light, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_light, 8, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes menu_back
    ui->menu_back = lv_btn_create(ui->menu);
    ui->menu_back_label = lv_label_create(ui->menu_back);
    lv_label_set_text(ui->menu_back_label, "BACK");
    lv_label_set_long_mode(ui->menu_back_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->menu_back_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->menu_back, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->menu_back_label, LV_PCT(100));
    lv_obj_set_pos(ui->menu_back, 395, 264);
    lv_obj_set_size(ui->menu_back, 78, 49);

    //Write style for menu_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menu_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menu_back, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menu_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->menu_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_back, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_back, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for menu_back, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->menu_back, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->menu_back, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->menu_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->menu_back, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->menu_back, 5, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->menu_back, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->menu_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->menu_back, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->menu_back, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write codes menu_ligh
    ui->menu_ligh = lv_switch_create(ui->menu);
    lv_obj_set_pos(ui->menu_ligh, 144, 72);
    lv_obj_set_size(ui->menu_ligh, 80, 35);

    //Write style for menu_ligh, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menu_ligh, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menu_ligh, lv_color_hex(0x00e4b5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menu_ligh, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->menu_ligh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_ligh, 21, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_ligh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for menu_ligh, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->menu_ligh, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->menu_ligh, lv_color_hex(0x1e87df), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->menu_ligh, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->menu_ligh, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for menu_ligh, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menu_ligh, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menu_ligh, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menu_ligh, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->menu_ligh, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_ligh, 20, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes menu_autoligt
    ui->menu_autoligt = lv_label_create(ui->menu);
    lv_label_set_text(ui->menu_autoligt, "AutoLight:");
    lv_label_set_long_mode(ui->menu_autoligt, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->menu_autoligt, 14, 80);
    lv_obj_set_size(ui->menu_autoligt, 103, 18);

    //Write style for menu_autoligt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menu_autoligt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_autoligt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_autoligt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_autoligt, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_autoligt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menu_autoligt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menu_autoligt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_autoligt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menu_autoligt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menu_autoligt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menu_autoligt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menu_autoligt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menu_autoligt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_autoligt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_line_1
    ui->menu_line_1 = lv_line_create(ui->menu);
    static lv_point_t menu_line_1[] = {{0, 0},{480, 0},};
    lv_line_set_points(ui->menu_line_1, menu_line_1, 2);
    lv_obj_set_pos(ui->menu_line_1, 6, 54);
    lv_obj_set_size(ui->menu_line_1, 466, 1);

    //Write style for menu_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->menu_line_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->menu_line_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->menu_line_1, 160, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->menu_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_label_1
    ui->menu_label_1 = lv_label_create(ui->menu);
    lv_label_set_text(ui->menu_label_1, "other:");
    lv_label_set_long_mode(ui->menu_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->menu_label_1, 20, 237);
    lv_obj_set_size(ui->menu_label_1, 103, 18);

    //Write style for menu_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_autostop
    ui->menu_autostop = lv_label_create(ui->menu);
    lv_label_set_text(ui->menu_autostop, "AutoStop:");
    lv_label_set_long_mode(ui->menu_autostop, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->menu_autostop, 14, 140);
    lv_obj_set_size(ui->menu_autostop, 102, 20);

    //Write style for menu_autostop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menu_autostop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_autostop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_autostop, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_autostop, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_autostop, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menu_autostop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menu_autostop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_autostop, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menu_autostop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menu_autostop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menu_autostop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menu_autostop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menu_autostop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_autostop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_stop
    ui->menu_stop = lv_switch_create(ui->menu);
    lv_obj_set_pos(ui->menu_stop, 144, 131);
    lv_obj_set_size(ui->menu_stop, 80, 35);

    //Write style for menu_stop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menu_stop, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menu_stop, lv_color_hex(0x00e4b5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menu_stop, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->menu_stop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_stop, 21, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_stop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for menu_stop, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->menu_stop, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->menu_stop, lv_color_hex(0x1e87df), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->menu_stop, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->menu_stop, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for menu_stop, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menu_stop, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menu_stop, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menu_stop, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->menu_stop, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_stop, 20, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes menu_label_2
    ui->menu_label_2 = lv_label_create(ui->menu);
    lv_label_set_text(ui->menu_label_2, "STOPWATCH");
    lv_label_set_long_mode(ui->menu_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->menu_label_2, 20, 264);
    lv_obj_set_size(ui->menu_label_2, 310, 44);

    //Write style for menu_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menu_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_label_2, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_label_2, &lv_font_montserratMedium_45, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_label_2, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menu_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menu_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menu_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menu_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menu_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menu_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menu_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_cont_1
    ui->menu_cont_1 = lv_obj_create(ui->menu);
    lv_obj_set_pos(ui->menu_cont_1, 254, 86);
    lv_obj_set_size(ui->menu_cont_1, 215, 166);
    lv_obj_set_scrollbar_mode(ui->menu_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for menu_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menu_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->menu_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->menu_cont_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->menu_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menu_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menu_cont_1, lv_color_hex(0x211e1e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menu_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menu_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menu_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menu_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menu_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_maxspeed
    ui->menu_maxspeed = lv_label_create(ui->menu_cont_1);
    lv_label_set_text(ui->menu_maxspeed, "MAX Speed:");
    lv_label_set_long_mode(ui->menu_maxspeed, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->menu_maxspeed, 7, 52);
    lv_obj_set_size(ui->menu_maxspeed, 198, 15);

    //Write style for menu_maxspeed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menu_maxspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_maxspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_maxspeed, lv_color_hex(0xf55555), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_maxspeed, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_maxspeed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menu_maxspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menu_maxspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_maxspeed, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menu_maxspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menu_maxspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menu_maxspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menu_maxspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menu_maxspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_maxspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_avgspeed
    ui->menu_avgspeed = lv_label_create(ui->menu_cont_1);
    lv_label_set_text(ui->menu_avgspeed, "AVG Speed:");
    lv_label_set_long_mode(ui->menu_avgspeed, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->menu_avgspeed, 7, 94);
    lv_obj_set_size(ui->menu_avgspeed, 198, 15);

    //Write style for menu_avgspeed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menu_avgspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_avgspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_avgspeed, lv_color_hex(0x55c9ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_avgspeed, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_avgspeed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menu_avgspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menu_avgspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_avgspeed, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menu_avgspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menu_avgspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menu_avgspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menu_avgspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menu_avgspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_avgspeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_runtime
    ui->menu_runtime = lv_label_create(ui->menu_cont_1);
    lv_label_set_text(ui->menu_runtime, "TIME:");
    lv_label_set_long_mode(ui->menu_runtime, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->menu_runtime, 7, 13);
    lv_obj_set_size(ui->menu_runtime, 198, 15);

    //Write style for menu_runtime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menu_runtime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_runtime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_runtime, lv_color_hex(0x00ff2b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_runtime, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_runtime, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menu_runtime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menu_runtime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_runtime, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menu_runtime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menu_runtime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menu_runtime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menu_runtime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menu_runtime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_runtime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_allkm
    ui->menu_allkm = lv_label_create(ui->menu_cont_1);
    lv_label_set_text(ui->menu_allkm, "ALL DISTANCE:");
    lv_label_set_long_mode(ui->menu_allkm, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->menu_allkm, 7, 135);
    lv_obj_set_size(ui->menu_allkm, 198, 15);

    //Write style for menu_allkm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menu_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_allkm, lv_color_hex(0xd71bee), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_allkm, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_allkm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menu_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menu_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_allkm, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menu_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menu_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menu_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menu_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menu_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_allkm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_label_3
    ui->menu_label_3 = lv_label_create(ui->menu);
    lv_label_set_text(ui->menu_label_3, "AutoData:");
    lv_label_set_long_mode(ui->menu_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->menu_label_3, 14, 195);
    lv_obj_set_size(ui->menu_label_3, 102, 20);

    //Write style for menu_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menu_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_label_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menu_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menu_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menu_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menu_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menu_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menu_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menu_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_vdata
    ui->menu_vdata = lv_switch_create(ui->menu);
    lv_obj_set_pos(ui->menu_vdata, 144, 187);
    lv_obj_set_size(ui->menu_vdata, 80, 35);

    //Write style for menu_vdata, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menu_vdata, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menu_vdata, lv_color_hex(0x00e4b5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menu_vdata, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->menu_vdata, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_vdata, 21, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_vdata, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for menu_vdata, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->menu_vdata, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->menu_vdata, lv_color_hex(0x1e87df), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->menu_vdata, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->menu_vdata, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for menu_vdata, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menu_vdata, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menu_vdata, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menu_vdata, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->menu_vdata, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_vdata, 20, LV_PART_KNOB|LV_STATE_DEFAULT);

    //The custom code of menu.


    //Update current screen layout.
    lv_obj_update_layout(ui->menu);

    //Init events for screen.
    events_init_menu(ui);
}
