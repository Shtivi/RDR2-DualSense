#pragma once

class Stopwatch
{
private:
	time_t startTime;
	bool hasStarted;

public:
	static double getElapsedSeconds(tm  from, tm to);
	static double getElapsedSeconds(time_t  from, time_t to);

	Stopwatch();
	Stopwatch(tm startTime);
	Stopwatch(time_t startTime);
	void start();
	void start(tm startTime);
	void start(time_t startTime);
	void stop();
	bool isStarted();
	double getElapsedSeconds();
	double getElapsedHours();

protected:
	virtual time_t getCurrentTime();
};

class GameStopwatch : public Stopwatch
{
public:
	GameStopwatch();
	GameStopwatch(tm startTime);
	double getElapsedSecondsRealTime();

protected:
	time_t getCurrentTime();
};