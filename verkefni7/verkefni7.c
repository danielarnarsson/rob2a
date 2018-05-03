task verkefni1()
{
//code
//code
}

task verkefni2()
{
//code
//code
}

task verkefni3()
{
//code
//code
}

task verkefni4()
{
//code
//code
}

task main()
{
runningTask=NULL;
while(True)
{
	if(button is pressed)
	{
	StopTask(runningTask);
	runningTask = verkefni1;
	StartTask(verkefni1);
	}
	else if(other button is pressed)
	{
	StopTask(runningTask);
	runningTask=verkefni2;
	StartTask(verkefn2);
	}
	wait1Msec(300);
}


}
