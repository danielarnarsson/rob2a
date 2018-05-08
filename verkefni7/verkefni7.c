#include "./tasks/tasks.c"

StartTask(emergencyStop);

task main()
{
runningTask=NULL;
while(True)
{
	if(vexRT[Btn8D] == 1)
	{
	StopTask(runningTask);
	runningTask = verkefni2hluti1;
	StartTask(runningTask);
	}
	else if(vexRT[Btn8L] == 1)
	{
	StopTask(runningTask);
	runningTask=verkefni2hluti2;
	StartTask(runningTask);
	}
	else if(vexRT[Btn8U] == 1)
	{
	StopTask(runningTask);
	runningTask=verkefni2hluti3;
	StartTask(runningTask);
	}
	else if(vexRT[Btn8R] == 1)
	{
	StopTask(runningTask);
	runningTask=verkefni3hluti1;
	StartTask(runningTask);
	}
	else if(vexRT[Btn7D])
	{
	runningTask=verkefni4;
	StartTask(runningTask);
	}
	wait1Msec(300);
}


}
