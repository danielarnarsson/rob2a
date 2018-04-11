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

void stop(int time){
	motor[rightMotor] = 0;		  // Motor on port2 is run at full (127) power forward
	motor[leftMotor]  = 0;		  // Motor on port3 is run at full (127) power forward
	wait1Msec(time);
}


const float BASEDIST = 486.12; // amount of degrees that wheel motors need to spin to travel 0.5m
void drive(int dist,bool bf){
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	int backward_forward = (bf) ? (1):(-1);
	while(dist > abs(SensorValue[rightEncoder])){
		if(SensorValue[rightEncoder] == SensorValue[leftEncoder]) // If rightEncoder has counted the same amount as leftEncoder:
		{
			// Move Forward
			motor[rightMotor] = 50*backward_forward;		    // Right Motor is run at power level 80
			motor[leftMotor]  = 50*backward_forward;		    // Left Motor is run at power level 80
		}
		else if(abs(SensorValue[rightEncoder]) > abs(SensorValue[leftEncoder]))	// If rightEncoder has counted more encoder counts
		{
			// Turn slightly right
			motor[rightMotor] = 35*backward_forward;		    // Right Motor is run at power level 60
			motor[leftMotor]  = 50*backward_forward;		    // Left Motor is run at power level 80
		}
		else	// Only runs if leftEncoder has counted more encoder counts
		{
			// Turn slightly left
			motor[rightMotor] = 50*backward_forward;		    // Right Motor is run at power level 80
			motor[leftMotor]  = 35*backward_forward;		    // Left Motor is run at power level 60
		}
	}
}

void resetEncoders(){
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	}


void turn(float degrees, bool leftOrRight) {
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	if (leftOrRight == false) { //after we have added a thing to correct how the robot turns, the if statement should go away but the degrees variable (degrees = degrees * 3.7) should stay.
		degrees = degrees * 3.9;
	}
	else if (leftOrRight == true) {
		degrees = degrees * 3.9;
	}
	while (degrees > abs(SensorValue[rightEncoder]) && degrees > abs(SensorValue[leftEncoder])) {
		if (leftOrRight == false) { //left
			motor[rightMotor] = 50;
			motor[leftMotor]  = -50;
			}
		else if (leftOrRight == true) { //right
			motor[rightMotor] = -50;
			motor[leftMotor]  = 50;
			}
		}
	}


task main()
{
	bool left = false;
	bool right = true;
	drive(BASEDIST, true);
	turn(90, left);
	drive(BASEDIST, true);
	for (int i = 0; i < 2; i++) {
		turn(90, right);
		drive(BASEDIST, true);
	}

}



// diameter = 10.16
// circumference = 10.16 * pi = 31.92 cm
// 0.5/0.3192 = 1.5664
// 1.5664 * 360 = 563.9 degrees
// 563.9/360 * 31.92 = 50 cm
// 50/58.5 * 563.9 = 486.12 degrees



//distance_traveled_left = (sensorValue[leftEncoder]/ 360) * 31.92
//distance_traveled_right = (sensorValue[rightEncoder]/ 360) * 31.92
//distance_traveled_right needs to be equal to distance_traveled_left to
//be sure that it travels straight.
