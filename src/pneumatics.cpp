//
// Created by tyler on 10/31/2022.
//
#include "main.h"
#include "pneumatics.h"

#define PNEUMATICS_PORT 'A'

pros::ADIDigitalOut piston (PNEUMATICS_PORT);

void pneumatic_press(){
    if (master.get_digital(DIGITAL_A)){
        piston.set_value(true);

    }
    else{
        pros::delay(DELAY_TIME);

    }
}
