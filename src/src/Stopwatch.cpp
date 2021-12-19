#include "Main.h";

double Stopwatch::getElapsedSeconds(tm from, tm to)
{
	return getElapsedSeconds(mktime(&from), mktime(&to));
}

double Stopwatch::getElapsedSeconds(time_t from, time_t to)
{
	return to - from;
}

Stopwatch::Stopwatch()
{
	hasStarted = false;
}

Stopwatch::Stopwatch(tm time)
{
	start(time);
}

Stopwatch::Stopwatch(time_t time)
{
	start(time);
}

void Stopwatch::start()
{
	start(getCurrentTime());
}

void Stopwatch::start(tm startTime)
{
	start(mktime(&startTime));
}

void Stopwatch::start(time_t startTime)
{
	this->startTime = startTime;
	hasStarted = true;
}

void Stopwatch::stop()
{
	hasStarted = false;
}

bool Stopwatch::isStarted()
{
	return hasStarted;
}

time_t Stopwatch::getCurrentTime()
{
	return time(0);
}

double Stopwatch::getElapsedSeconds()
{
	if (!hasStarted)
	{
		return -1;
	}
	return Stopwatch::getElapsedSeconds(this->startTime, getCurrentTime());
}

double Stopwatch::getElapsedHours()
{
	if (!hasStarted)
	{
		return -1;
	}
	return (this->getElapsedSeconds() / (60 * 60));
}