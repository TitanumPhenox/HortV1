//
// Created by tyler on 10/31/2022.
//
#include "main.h"
#include "../include/pneumatics.h"

#define PNEUMATICS_PORT 'A'

pros::ADIDigitalOut pneumatic1 (PNEUMATICS_PORT);

void pneumatic_press(){
    if (master.get_digital(DIGITAL_RIGHT)){
        pneumatic1.set_value(false);

    }


    else {
        pros::delay(DELAY_TIME);

    }
}
void pneumatic_drop() {
    pneumatic1.set_value(false);
    pros::delay(DELAY_TIME);


}
void pneumatic_values(int input){
    pneumatic1.set_value(input);
}

