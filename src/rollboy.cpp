//
// Created by tyler on 11/1/2022.
//
#include "main.h"
#include "../include/rollboy.h"


pros::Motor rollboy(20, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);

void roll_son(int input)  {
    rollboy = input;
}
void stop_the_rollie_boy(){
    roll_son(0);
}

void rollboy_manuel(){
    if(master.get_digital(DIGITAL_UP))
    {
        roll_son(200);
    }
    else {
        stop_the_rollie_boy();

    }

}
