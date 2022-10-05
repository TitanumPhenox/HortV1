//
// Created by tyler on 10/4/2022.
//

#include "../include/Intake.h"
#inclide "main.h"


pros::Motor take(1, MOTOR_GEARSET_8, false, MOTOR_ENCODER_DEGREES);

void set_take(int input)  { take = input; }

void manual_take{
        if (master.get_digital(DIGITAL_L1)) {
            set_take(127);
        } else if (master.get_digital(DIGITAL_L2)) {
            set_take(-127);
        } else {
            set_take(0);
        }
}