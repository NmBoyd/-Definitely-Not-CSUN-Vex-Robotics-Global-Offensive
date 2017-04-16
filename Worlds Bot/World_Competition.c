#pragma config(UART_Usage, UART1, uartUserControl, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartUserControl, baudRate19200, IOPins, None, None)
#pragma config(Motor,  port1,           claw1,         tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           ld1,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           ld2,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           ld3,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           lift1,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift2,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           rd1,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           rd2,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rd3,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          claw2,         tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"
#include "UART.h"

//Include Johnny Functions
#include <worldsBotManual.h>
//Auton Choice
// 0 - Left Square: 3 stars fence, cube, 3 far zone stars search and score
// 1 - Left Square: Cube, 3 center stars fence, search and score
// 2 - Right Square: 3 stars fence, cube, 3 far zone stars search and score
// 3 - Right Square: Cube, 3 center stars fence, search and score
//#define AUTON_CHOICE 2

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;
	bDisplayCompetitionStatusOnLcd = false;
	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
	//startTask(SensorReader);
	//startTask(chooseAuton);
	configureSerial();
}

task autonomous(){

	//startTask(chooseAuton);

	//Determine which autonomous to run
/*
	if(AUTON_CHOICE == 0){
		//smartLeftAuton1();
		skillRun();

	}
	else if(AUTON_CHOICE == 1)
		smartLeftAuton2();
	else if(AUTON_CHOICE == 2)
		smartRightAuton1();\
	else if(AUTON_CHOICE == 3)
		smartRightAuton2();
	else{
		//smartLeftAuton1();
		skillRun();
	}*/

	while(true)
	{
		for(int i = 0; i < 10; i++)
		{
			motor[i] = motorPowers[i];
		}
	}
}

task usercontrol(){

	//Enable lift and driver control
	startTask(drive);
	startTask(lift);
	startTask(claw);


}
