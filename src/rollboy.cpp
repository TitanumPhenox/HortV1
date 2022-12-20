//
// Created by tyler on 11/1/2022.
//
#include "main.h"
#include "../include/rollboy.h"
int roll_port = 7;

pros::Motor rollboy(roll_port , MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);

void roll_son(int voltage)  {
    rollboy = voltage;
}
void stop_the_rollie_boy(){
    roll_son(0);
}

void rollboy_manuel(){
    if(master.get_digital(DIGITAL_A))
    {
        roll_son(-200);
    }
    else
    {
        stop_the_rollie_boy();

    }

}
