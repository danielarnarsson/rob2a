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
#automated movement with no joystick
task main()
{
    int normalSpeed;
    int slowSpeed;
    normalSpeed = 63;
    slowSpeed = 50;

    wait1Mspec(2000);

    SensorValue[rightEncoder] = 0;
    SensorValue[leftEncoder] = 0;
    //First Forward Movement
    while(SensorValue[leftEncoder] < 1260)
    {
        if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
        {
            motor[rightMotor] = normalSpeed;
            motor[leftMotor] = slowSpeed;
        }
        if(SensorValue[rightEncoder] > SensorValue[leftEncoder])
        {
            motor[rightMotor] = slowSpeed;
            motor[leftMotor] = normalSpeed;
        }
        if(SensorValue[leftEncoder] == SensorValue[rightEncoder])
        {
            motor[rightMotor] = normalSpeed;
            motor[leftMotor] = normalSpeed;
        }
    }

    SensorValue[rightEncoder] = 0;
    SensorValue[leftEncoder] = 0;
    //left Turn
    while(SensorValue[leftEncoder] < 720)
    {
        motor[rightMotor] = 63;
        motor[leftMotor] = -63;
    }

    SensorValue[rightEncoder] = 0;
    SensorValue[leftEncoder] = 0;
    //Second Forward Movement
    while(SensorValue[leftEncoder] < 1080)
    {
        if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
        {
            motor[rightMotor] = normalSpeed;
            motor[leftMotor] = slowSpeed;
        }
        if(SensorValue[rightEncoder] > SensorValue[leftEncoder])
        {
            motor[rightMotor] = slowSpeed;
            motor[leftMotor] = normalSpeed;
        }
        if(SensorValue[leftEncoder] == SensorValue[rightEncoder])
        {
            motor[rightMotor] = normalSpeed;
            motor[leftMotor] = normalSpeed;
        }
    }

    SensorValue[rightEncoder] = 0;
    SensorValue[leftEncoder] = 0;
    //Right Turn
    while(SensorValue[leftEncoder] < 720)
    {
        motor[rightMotor] = -63;
        motor[leftMotor] = 63;
    }


    SensorValue[rightEncoder] = 0;
    SensorValue[leftEncoder] = 0;
    //Third Forward Movement
    while(SensorValue[leftEncoder] < 800)
    {
        if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
        {
            motor[rightMotor] = normalSpeed;
            motor[leftMotor] = slowSpeed;
        }
        if(SensorValue[rightEncoder] > SensorValue[leftEncoder])
        {
            motor[rightMotor] = slowSpeed;
            motor[leftMotor] = normalSpeed;
        }
        if(SensorValue[leftEncoder] == SensorValue[rightEncoder])
        {
            motor[rightMotor] = normalSpeed;
            motor[leftMotor] = normalSpeed;
        }
    }

    SensorValue[rightEncoder] = 0;
    SensorValue[leftEncoder] = 0;
    //Right Turn
    while(SensorValue[leftEncoder] < 720)
    {
        motor[rightMotor] = -63;
        motor[leftMotor] = 63;
    }

    SensorValue[rightEncoder] = 0;
    SensorValue[leftEncoder] = 0;
    //Fourth Forward Movement
    while(SensorValue[leftEncoder] < 600)
    {
        if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
        {
            motor[rightMotor] = normalSpeed;
            motor[leftMotor] = slowSpeed;
        }
        if(SensorValue[rightEncoder] > SensorValue[leftEncoder])
        {
            motor[rightMotor] = slowSpeed;
            motor[leftMotor] = normalSpeed;
        }
        if(SensorValue[leftEncoder] == SensorValue[rightEncoder])
        {
            motor[rightMotor] = normalSpeed;
            motor[leftMotor] = normalSpeed;
        }
    }
}
