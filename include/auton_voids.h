//
// Created by tyler on 11/4/2022.
//

#include "main.h"
#pragma once

void tear_drive_position();
void move_drive_absolute(int position, int voltage);
void zero_pos_drive(int position);
void set_breaks();
void set_all_drive_brakes();
void imu_turn_left(int angle1, int angle2);
void imu_turn_right(int angle1, int angle2);
void drive_motors(int power, int delay);
void catapult_shoot(int power, int delay);
void intake_go(int power, int delay);
