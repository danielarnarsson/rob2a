#pragma config(Sensor, in1,    rightLineFollower, sensorLineFollower)
#pragma config(Sensor, in2,    centreLineFollower, sensorLineFollower)
#pragma config(Sensor, in3,    leftLineFollower, sensorLineFollower)
#pragma config(Sensor, in4,    lightSensor,    sensorReflection)
#pragma config(Sensor, in5,    Potentiometer,  sensorPotentiometer)
#pragma config(Sensor, dgtl1,  sonarSensor,    sensorSONAR_cm)
#pragma config(Sensor, dgtl4,  touchSensor,    sensorTouch)
#pragma config(Sensor, dgtl8,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl10, rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex393, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex269, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorVex269, openLoop)
#include "./functions/robotfunctions.c"
#include "./tasks/projects.c"
#include "./functions/selectProject.c"

/* This assignment combines all our previous assignments into one.
it assignins each project to a specific button on the  VEX controller,
For example when you press 8D, the task "verkefni2hluti1" will run and
will a function will stop all other running project tasks. */


task main()
{
	StartTask(emergencyStop);
	while(true)
	{
		if(vexRT[Btn8D] == 1)
		{
		selectProject(21);
		}

		else if(vexRT[Btn8L] == 1)
		{
		selectProject(22);
		}

		else if(vexRT[Btn8U] == 1)
		{
		selectProject(23);
		}

		else if(vexRT[Btn8R] == 1)
		{
		selectProject(31);
		}

		else if(vexRT[Btn7D] == 1)
		{
		selectProject(4);
		}
		wait1Msec(15);
	}
}
