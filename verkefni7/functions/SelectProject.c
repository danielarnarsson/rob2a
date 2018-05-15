void selectProject(int runningTask)
{
	if (runningTask != 21)
	{
		StopTask(verkefni2hluti1);
	}

	if (runningTask != 22)
	{
		StopTask(verkefni2hluti2);
	}

	if (runningTask != 23)
	{
		StopTask(verkefni2hluti3);
	}

	if (runningTask != 31)
	{
		StopTask(verkefni3hluti1);
	}

	if (runningTask != 4)
	{
		StopTask(verkefni4);
	}

	if (runningTask == 21) {
		StartTask(verkefni2hluti1);
	}

	if (runningTask == 22) {
		StartTask(verkefni2hluti2);
	}

	if (runningTask == 23) {
		StartTask(verkefni2hluti3);
	}

	if (runningTask == 31) {
		StartTask(verkefni3hluti1);
	}

	if (runningTask == 4) {
		StartTask(verkefni4);
	}
}
