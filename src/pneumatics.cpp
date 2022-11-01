//
// Created by tyler on 10/31/2022.
//
#include "main.h"
#include "../include/pneumatics.h"

#define PNEUMATICS_PORT 'A'

pros::ADIDigitalOut pneumatic1 (PNEUMATICS_PORT);

void pneumatic_press(){
    if (master.get_digital(DIGITAL_A)){
        pneumatic1.set_value(true);

    }
    else{
        pros::delay(DELAY_TIME);

    }
}
void pneumatic_drop(){
    pneumatic1.set_value(true);
    pros::delay(DELAY_TIME);


}
