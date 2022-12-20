//
// Created by tyler on 10/4/2022.
//

#include "../include/Intake.h"
#include "main.h"
int take_port = 18;

pros::Motor take1(take_port, MOTOR_GEARSET_6, false, MOTOR_ENCODER_DEGREES);
//pros::Motor take2(3, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);

void set_take(int input)  {
    take1 = input;
}


void manual_take(){
        if (master.get_digital(DIGITAL_L1)) {
            set_take(400);
            pros::delay(10);
        } else if (master.get_digital(DIGITAL_L2)) {
            set_take(-400);
            pros::delay(10);
        } else {
            set_take(0);
            pros::delay(DELAY_TIME);
        }
}
