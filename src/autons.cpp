#include "main.h"
#include "shotboy.h"
#include "Intake.h"
#include "pneumatics.h"
#include "auton_voids.h"

extern int max_intake_speed;
const int DRIVE_SPEED = 110;
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;

///
// Constants
///

// Reset all constants to default
void
reset_constants() {
  reset_slew_min_power();
  reset_slew_distance();
  reset_fw_drive_constants();
  reset_bw_drive_constants();
  reset_turn_constants();
  reset_turn_i_constants();
  reset_swing_constants();
}

void roller_change_blue() {
    set_motors_drive(10000);//goes forward
    pros::delay(250);
    set_motors_drive(0);
    pros::delay(10);
    tear_drive_position();
    while (r_motor.get_position() <90 || r_motor.get_position() > 95){
        r_motor.move(10000);
        r2_motor.move(10000);
        l_motor.move(-10000);
        l2_motor.move(-10000);
        pros::delay(10);
    }
    set_motors_drive(0);
    pros::delay(10);
    set_motors_drive(10000);//goes forward after turn
    pros::delay(250);
    set_motors_drive(0);
    pros::delay(10);
    tear_drive_position();
    while (l_motor.get_position() <-90 || l_motor.get_position() >-85){
        l_motor.move(10000);
        l2_motor.move(10000);
        r_motor.move(-10000);
        r2_motor.move(-10000);
        pros::delay(10);

    }
    set_motors_drive(0);
    pros::delay(10);
    set_motors_drive(-10000);//goes forward
    pros::delay(150);
    set_motors_drive(0);
    pros::delay(10);
    pros::delay(500);
    set_motors_drive(10000);
    pros::delay(100);
    set_motors_drive(0);
    pros::delay(10);

}

void roller_change_red() {
    set_motors_drive(10000);//goes forward
    pros::delay(100);
    set_motors_drive(0);
    pros::delay(10);
    set_motors_right(10000);
    pros::delay(250*2);
    set_motors_drive(0);
    pros::delay(10);
    set_motors_drive(10000);//goes forward
    pros::delay(250*2.7);
    set_motors_drive(0);
    pros::delay(10);
    set_motors_right(-10000);
    pros::delay(250*2);
    set_motors_drive(0);
    pros::delay(10);
    set_motors_drive(-10000);//goes forward
    pros::delay(250*1.1);
    set_motors_drive(0);
    pros::delay(10);
    set_motors_drive(10000);
    pros::delay(100);
    set_motors_drive(0);
    pros::delay(10);
}

void blue_on_roller(){
    set_motors_drive(10000);
    pros::delay(560);
    set_motors_drive(0);
    pros::delay(10);
    while (gyro.get_heading() < 315 || gyro.get_heading() > 330) {
        set_motors_left(10000);
    }
    set_motors_drive(0);
    pros::delay(10);
    set_motors_drive(-10000);
    pros::delay(750);
    set_motors_drive(0);
    pros::delay(10);
    while (gyro.get_heading() < 333 || gyro.get_heading() > 353) {
        set_motors_right(10000);
    }
    set_motors_drive(0);
    pros::delay(10);
    set_motors_drive(-6500);
    pros::delay(320);
    set_motors_drive(0);
    pros::delay(10);
    set_motors_drive(5500);
    pros::delay(200);
    set_motors_drive(0);
    pros::delay(10);
    while (gyro.get_heading() < 75 || gyro.get_heading() > 88) {
        set_motors_right(10000);
    }
    set_motors_drive(0);
    pros::delay(10);
    set_motors_drive(-10000);
    pros::delay(500);
    set_motors_drive(0);
    pros::delay(10);
    set_catapult(200);
    pros::delay(500);
    set_catapult(0);
    pros::delay(10);

}


void red_on_roller(){
    set_motors_drive(-10000);
    pros::delay(100);
    set_motors_drive(0);
    set_motors_drive(10000);
    pros::delay(200);
    set_motors_drive(0);
    pros::delay(10);

}

void second_roller(){
    set_motors_drive(-10000);
    pros::delay(250);
    set_motors_right(-10000);

}

void test_absolute_drive(){
    drive_motors(1000,50);
    imu_turn_right(30,50);
    catapult_shoot(150,100);
    intake_go(max_intake_speed,100);

}





