#include "main.h"
#include "intake.h"
#include "shotboy.h"
#include "pneumatics.h"
#include "auton_voids.h"
/**
 * Disables all tasks.
 *
 * This runs during disabled and initialize to turn off all user created tasks.
 */
void disable_all_tasks() {
	drive_pid.suspend();
}

void
tare_sensors() {
    tare_gyro();
}



/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void
on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		imu_calibrate();
	} else(!imu_calibrate()); {
        pros::lcd::set_text(7, "IMU failed to calibrate!");
	}
}

const int num_of_pages = 9;
int current_page = 0;

void
auto_select(bool is_auton) {
	for (int i = 0; i<7;i++)
		pros::lcd::clear_line(i);

	pros::lcd::set_text(0, "Page "+std::to_string(current_page+1));

	switch (current_page) {
		case 0: // Auto 1
			pros::lcd::set_text(2, "Red roller auton");
			pros::lcd::set_text(3, "spin roller to red");
			pros::lcd::set_text(4, "");
			if (is_auton) red_on_roller(); //solo_awp();
			break;
		case 1: // Auto 2
			pros::lcd::set_text(2, "roller change for blue (touching)");
			if (is_auton) blue_on_roller(); //auto_3();
			break;
		case 2: // Auto 3
			pros::lcd::set_text(2, "roller change for red");
			if (is_auton) roller_change_red();
			break;
        case 3: // Auto 3
            pros::lcd::set_text(2, "testing");
            if (is_auton) test_absolute_drive();
            break;

		default:
			break;
	}
}
void
page_up() {
	if(current_page==num_of_pages-1)
		current_page=0;
	else
		current_page++;
	auto_select(false);
}
void
page_down() {
	if(current_page==0)
		current_page=num_of_pages-1;
	else
		current_page--;
	auto_select(false);
}



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void
initialize() {
	print_ez_template();
	pros::delay(500);

	disable_all_tasks();

	pros::lcd::initialize();
	auto_select(false);
	pros::lcd::register_btn0_cb(page_down);
	pros::lcd::register_btn2_cb(page_up);
	if(!imu_calibrate()) {
		pros::lcd::set_text(7, "IMU failed to calibrate!");
	}

	chassis_motor_init();
	tare_sensors();
    pneumatic_values(true);
    pros::delay(10);

}



/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void
disabled() {
	disable_all_tasks();
}



/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void
competition_initialize() {
	disable_all_tasks();
}



/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void
autonomous() {
    tare_gyro();
    //reset_drive_sensor();
    set_drive_brake(MOTOR_BRAKE_HOLD); // This is preference to what you like to drive on
    set_all_drive_brakes();

    auto_select(true);
}



/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void
opcontrol() {
    set_all_drive_brakes();


    while (true) {
        arcadeDrive();
        pneumatic_press();
        manual_take();
        catapult_control_manual();
		pros::delay(DELAY_TIME);

	}
}
