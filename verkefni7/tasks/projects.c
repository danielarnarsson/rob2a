task verkefni2hluti1() //correct
{
	const int BASETIME = 850;
	for (int i = 1; i<5;i++)
	{
		drive1(BASETIME*i,true);
		stop(1500);
		drive1(BASETIME*i,false);
		stop(1500);
	}

}

task verkefni2hluti2 { //correct
	const float BASEDIST = 486.12; // amount of degrees that wheel motors need to spin to travel 0.5m
	for (int i = 1; i<5;i++){
		resetEncoders();
		drive2(BASEDIST*i,true);
		stop(1000);
		resetEncoders();
		drive2(BASEDIST*i,false);
		stop(1000);
	}
}

task verkefni2hluti3() //correct
{
	const float BASEDIST = 486.12; // amount of degrees that wheel motors need to spin to travel 0.5m
	bool left = false;
	bool right = true;
	drive2(BASEDIST, true);
	turn(90, left);
	drive2(BASEDIST, true);
	for (int i = 0; i < 2; i++) {
		turn(90, right);
		drive2(BASEDIST, true);
	}
}

task verkefni3hluti1() //correct
{
	int power = 127;
	while(1 == 1)
	{
		if ((abs(vexRT[Ch2]) + abs(vexRT[Ch1])) > 0) {
			motor[leftMotor]  = (vexRT[Ch2] + vexRT[Ch1])/2;  // (y + x)/2
			motor[rightMotor] = (vexRT[Ch2] - vexRT[Ch1])/2;  // (y - x)/2
		}
// Raise, lower or do not move arm
		if(vexRT[Btn5U] == 1)       	//If button 5U is pressed...
		{
			motor[armMotor] = -power;    	//...raise the arm.
		}
		else if(vexRT[Btn5D] == 1)  	//Else, if button 5D is pressed...
		{
			motor[armMotor] = power;   	//...lower the arm.
		}
		else                      		//Else (neither button is pressed)...
		{
			motor[armMotor] = 0;      	//...stop the arm.
		}

// Open, close or do not more claw
		if(vexRT[Btn6U] == 1)       	//If Button 6U is pressed...
		{
			motor[clawMotor] = power;  		//...close the gripper.
		}
		else if(vexRT[Btn6D] == 1)  	//Else, if button 6D is pressed...
		{
			motor[clawMotor] = -power; 		//...open the gripper.
		}
		else                      		//Else (neither button is pressed)...
		{
			motor[clawMotor] = 0;    		//...stop the gripper.
		}
	}
}

task emergencyStop() //from verkefni3 hluti2
{
	while(true)
	{
		if(vexRT[Btn7U]==1)
		{
			StopAllTasks();
		}
	}
}

task verkefni4()
{
	const float BASEDIST = 486.12; // amount of degrees that wheel motors need to spin to travel 0.5m
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
			drive2(BASEDIST, false);
			wait1Msec(100);
			}

			else if ((SensorValue(sonarSensor) < 20))
			{
			turn(45, left);
			wait1Msec(100);
			}
	}
}
