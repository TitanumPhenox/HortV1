//
// Created by tyler on 10/4/2022.
//

#include "../include/Intake.h"
#include "main.h"


pros::Motor take1(3, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);
//pros::Motor take2(3, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);

void set_take1(int input)  {
    take1 = input;
}


void manual_take(){
        if (master.get_digital(DIGITAL_L1)) {
            set_take1(200);
            pros::delay(10);
        } else if (master.get_digital(DIGITAL_L2)) {
            set_take1(200);
            pros::delay(10);
        } else {
            set_take1(0);
            pros::delay(DELAY_TIME);
        }
}