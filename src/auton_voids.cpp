//
// Created by tyler on 11/4/2022.
//

#include "../include/auton_voids.h"
#include "main.h"
#include "autons.hpp"


void tear_drive_position(){
    l_motor.tare_position();
    l2_motor.tare_position();
    r_motor.tare_position();
    r2_motor.tare_position();
}

void move_drive_absolute(int position, int voltage){
    l_motor.move_absolute(position,-voltage);
    l2_motor.move_absolute(position,-voltage);
    r_motor.move_absolute(position,-voltage);
    r2_motor.move_absolute(position,-voltage);
}

void zero_pos_drive(int position){
    l_motor.set_zero_position(position);
    l2_motor.set_zero_position(position);
    r_motor.set_zero_position(position);
    r2_motor.set_zero_position(position);
}