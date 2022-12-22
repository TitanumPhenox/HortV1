#include "main.h"
#include "shotboy.h"
#include "Intake.h"
#include "pneumatics.h"
#include "rollboy.h"
#include "auton_voids.h"

extern int max_intake_speed;
const int DRIVE_SPEED = 110;
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;


///
// TiP Autons
///

// Solo AWP
void
solo_awp() {
  // Drive towards mogo on plat, bring tilter out to launch ring into goal
  set_drive_pid(drive, 18, 80, true);
  wait_until(12);
  set_tilter_position(170, 50);
  wait_drive();

  // Swing turn out of the goal
  set_drive_pid(r_swing, 90, SWING_SPEED);
  wait_drive();

  // Drive into the field a little
  set_drive_pid(drive, -4, DRIVE_SPEED);
  wait_drive();

  // Swing to face second mogo
  set_drive_pid(r_swing, 178, SWING_SPEED);
  wait_drive();

  // Drive towards the mogo and intake it
  set_drive_pid(drive, -101, DRIVE_SPEED, true);
  tilter_in(true);
  wait_until(-24);
  mogo_out(true);
  set_max_speed(60);
  wait_drive();
  mogo_in(true);

  // Swing turn for nicer starting position in driver
  set_drive_pid(r_swing, 225, TURN_SPEED);
  tilter_out(true);
  wait_drive();
}








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

// Functions to change constants
/*
void
one_mogo_constants() {
  set_slew_min_power(80, 80);
  set_slew_distance(7, 7);
  set_fw_drive_constants(0.45, 5);
  set_bw_drive_constants(0.375, 4);
  set_turn_constants(5, 0.003, 35);
  set_turn_i_constants(15, 30);
  set_swing_constants(12, 35);
}

void
two_mogo_constants() {
  set_slew_min_power(80, 80);
  set_slew_distance(7, 7);
  set_fw_drive_constants(0.45, 5);
  set_bw_drive_constants(0.375, 4);
  set_turn_constants(5, 0.003, 35);
  set_turn_i_constants(15, 30);
  set_swing_constants(12, 35);
}
*/



// All drive movements use the "set_drive_pid" function
// the first parameter is the type of motion (drive, turn, r_swing, l_swing)
// below are example codes using each type


///
// Drive Example
///
void
auto_1() {
  // The second parameter is target inches
  // The third parameter is max speed the robot will drive at
  // The fourth parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches


  set_drive_pid(drive, 24, DRIVE_SPEED, true);
  wait_drive();

  set_drive_pid(drive, -12, DRIVE_SPEED);
  wait_drive();

  set_drive_pid(drive, -12, DRIVE_SPEED);
  wait_drive();
}



///
// Turn Example
///
void
auto_2() {
  // The second parameter is target degrees
  // The third parameter is max speed the robot will drive at


  set_drive_pid(turn, 90, TURN_SPEED);
  wait_drive();

  set_drive_pid(turn, 45, TURN_SPEED);
  wait_drive();

  set_drive_pid(turn, 0, TURN_SPEED);
  wait_drive();
}




///
// Combining Turn + Drive
///
void
auto_3() {
  set_drive_pid(drive, 24, DRIVE_SPEED, true);
  wait_drive();

  set_drive_pid(turn, 45, TURN_SPEED);
  wait_drive();

  set_drive_pid(turn, -45, TURN_SPEED);
  wait_drive();

  set_drive_pid(turn, 0, TURN_SPEED);
  wait_drive();

  set_drive_pid(drive, -24, DRIVE_SPEED, true);
  wait_drive();
}



///
// Wait Until
///
void
auto_4() {
  // wait_until will wait until the robot gets to a desired position


  // When the robot gets to 12 inches, the intakes will spin until the robot has traveled 24 inches
  set_drive_pid(drive, 24, DRIVE_SPEED, true);
  wait_until(12);
  //set_intake(127); // Commented because no intake function in this code
  wait_drive();
  //set_intake(0); // Commented because no intake function in this code

  set_drive_pid(turn, 45, TURN_SPEED);
  wait_drive();

  set_drive_pid(turn, -45, TURN_SPEED);
  wait_drive();

  set_drive_pid(turn, 0, TURN_SPEED);
  wait_drive();

  // When the robot gets to -12 inches, the intakes will spin until the robot has traveled -24 inches
  set_drive_pid(drive, -24, DRIVE_SPEED, true);
  wait_until(-12);
  //set_intake(127); // Commented because no intake function in this code
  wait_drive();
  //set_intake(0); // Commented because no intake function in this code
}



///
// Swing Example
///
void
auto_5() {
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive

  set_drive_pid(l_swing, 45, SWING_SPEED);
  wait_drive();

  set_drive_pid(drive, 24, DRIVE_SPEED, true);
  wait_until(12);

  set_drive_pid(r_swing, 0, SWING_SPEED);
  wait_drive();
}



void
test_auton() {
  set_drive_pid(drive, 24, DRIVE_SPEED, true);
  wait_until(8);
  mogo_out(true);
  pros::delay(200);

  set_drive_pid(turn, 45, TURN_SPEED);
  wait_drive();

  set_drive_pid(r_swing, -45, TURN_SPEED);
  wait_drive();

  set_drive_pid(turn, 0, TURN_SPEED);
  wait_drive();

  set_drive_pid(drive, -24, DRIVE_SPEED, true);
  wait_until(-8);
  mogo_in(true);
  wait_drive();
}



void
auto_6() {

}



void
auto_7() {

}



void
auto_8() {

}



void
auto_9() {

}



void
auto_10() {
l_motor.move(1000);
l2_motor.move(1000);
pros::delay(30000);
pneumatic_drop();

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
    roll_son(200);
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
    roll_son(200);
    pros::delay(210);
    roll_son(0);
    pros::delay(100);
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
    roll_son(200);
    pros::delay(200);
    roll_son(0);
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
    pros::delay(10);
    roll_son(200);
    pros::delay(200);
    roll_son(0);
    pros::delay(10);
    set_motors_drive(10000);
    pros::delay(200);
    set_motors_drive(0);
    pros::delay(10);

}

void second_roller(){
    set_motors_drive(-10000);
    roll_son(-200);
    pros::delay(250);
    set_motors_right(-10000);

}

void test_absolute_drive(){
    drive_motors(1000,50);
    imu_turn_right(30,50);
    catapult_shoot(150,100);
    intake_go(max_intake_speed,100);

}





