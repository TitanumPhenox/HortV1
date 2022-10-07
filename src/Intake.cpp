//
// Created by tyler on 10/4/2022.
//

#include "../include/Intake.h"
#include "main.h"


pros::Motor take1(20, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
//pros::Motor take2(19, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);

void set_take(int input)  {
    take1 = input;
   // take2 = input;
}

void manual_take(){
        if (master.get_digital(DIGITAL_L1)) {
            set_take(127);
        } else if (master.get_digital(DIGITAL_L2)) {
            set_take(-127);
        } else {
            set_take(0);
        }
}