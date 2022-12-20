//
// Created by tyler on 10/26/2022.
//

#include "../include/shotboy.h"
#include "main.h"
int catapult1_port = 14;
int catapult2_port =3;

pros::Motor catapult1(catapult1_port, MOTOR_GEARSET_36, true, MOTOR_ENCODER_DEGREES);
pros::Motor catapult2(catapult2_port, MOTOR_GEARSET_36,  true, MOTOR_ENCODER_DEGREES);
int  get_catapult1()     { return catapult1.get_position(); }
void set_catapult(int input)  { catapult1 = -input; catapult2 = input;}
void cancel_catapult_motors(){
    set_catapult(0);
    pros::delay(10);
}



void catapult_control() {
    if (master.get_digital(DIGITAL_R2)) {
        set_catapult(-200);
        pros::delay(830);
        cancel_catapult_motors();
        pros::delay(10);


    } else if (master.get_digital(DIGITAL_R1)) {
        set_catapult(200);
        pros::delay(632);
        cancel_catapult_motors();
        pros::delay(10);
    }

}
void catapult_control_manual(){
    if (master.get_digital(DIGITAL_R1)){
        set_catapult(200);
        pros::delay(10);
    }

    else if (master.get_digital(DIGITAL_R2)){
        set_catapult(-200);
        pros::delay(10);

    }
    else {
        cancel_catapult_motors();
        pros::delay(10);
    }
}



