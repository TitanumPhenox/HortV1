//
// Created by tyler on 11/4/2022.
//

#include "../include/auton_voids.h"
#include "main.h"
#include "autons.hpp"
#include "shotboy.h"
#include "intake.h"
extern int catapult1_port;
extern int take_port;
extern int roll_port;


void set_breaks(){
    pros::c::motor_set_brake_mode(1,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(2,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(3,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(4,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(5,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(6,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(7,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(8,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(9,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(10,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(11,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(12,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(13,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(14,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(15,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(16,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(17,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(18,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(19,MOTOR_BRAKE_HOLD);


}
void set_all_drive_brakes(){
    pros::c::motor_set_brake_mode(catapult1_port,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(take_port,MOTOR_BRAKE_HOLD);
    pros::c::motor_set_brake_mode(roll_port, MOTOR_BRAKE_HOLD);
}


void tear_drive_position(){
    l_motor.tare_position();
    l2_motor.tare_position();
    r_motor.tare_position();
    r2_motor.tare_position();
}

void move_drive_absolute(int position, int voltage){
    l_motor.move_absolute(position,-voltage);
    l2_motor.move_absolute(position,-voltage);
    r_motor.move_absolute(position,-voltage);
    r2_motor.move_absolute(position,-voltage);
}

void zero_pos_drive(int position){
    l_motor.set_zero_position(position);
    l2_motor.set_zero_position(position);
    r_motor.set_zero_position(position);
    r2_motor.set_zero_position(position);
}

void imu_turn_left(int angle1, int angle2){
while (gyro.get_heading() < angle1 || gyro.get_heading() > angle2) {
set_motors_left(10000);
}
set_all_drive_brakes();
pros::delay(10);
}
void imu_turn_right(int angle1, int angle2){
    while (gyro.get_heading() < angle1 || gyro.get_heading() > angle2) {
        set_motors_right(10000);
    }
    set_all_drive_brakes();
    pros::delay(10);
}
void drive_motors(int power, int delay){
    set_motors_drive(power);
    pros::delay(delay);
    set_motors_drive(0);
    pros::delay(10);

}
void catapult_shoot(int power, int delay){
    set_catapult(power);
    pros::delay(delay);
    set_catapult(0);
    pros::delay(10);
}
void intake_go(int power, int delay){
    set_take(power);
    pros::delay(delay);
    set_take(0);
    pros::delay(10);
}