#pragma config(Sensor, in4,    lightSensor,    sensorReflection)
#pragma config(Sensor, dgtl1,  sonarSensor,    sensorSONAR_cm)
#pragma config(Sensor, dgtl8,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl10, rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop)

//


task emergencyStop()
{
	while(true)
	{
		if(vexRT[Btn7U]==1)
		{
			StopAllTasks();
		}
	}
}


const float BASEDIST = 486.12; // amount of degrees that wheel motors need to spin to travel 0.5m
void drive(float dist,bool bf)
{
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


void turn(float degrees, bool leftOrRight) {
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	degrees = degrees * 3.9;
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
	StartTask(emergencyStop);
	bool left = false;
	bool right = true;
	while(true)
	{
			if(SensorValue(lightSensor) > 300)
			{
			motor[rightMotor] = 0;
			motor[leftMotor]  = 0;
			}

			else if(SensorValue(sonarSensor) > 20  || SensorValue(sonarSensor) == -1)
			{
			drive(BASEDIST, false);
			writeDebugStreamLine("inside drive");
			wait1Msec(100);
			}

			else if ((SensorValue(sonarSensor) < 20))
			{
			turn(45, left);
			writeDebugStreamLine("inside turn");
			wait1Msec(100);
			}
	}
}
