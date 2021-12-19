#include "Main.h";

GameStopwatch::GameStopwatch()
	: Stopwatch()
{
}

GameStopwatch::GameStopwatch(tm time)
	: Stopwatch(time)
{
}

time_t GameStopwatch::getCurrentTime()
{
	time_t time = CLOCK::_GET_SECONDS_SINCE_BASE_YEAR();
	return time;
}

double GameStopwatch::getElapsedSecondsRealTime()
{
	double elapsedGameSecs = getElapsedSeconds();
	
	if (elapsedGameSecs == -1)
	{
		return -1;
	}

	return elapsedGameSecs / 25;
}