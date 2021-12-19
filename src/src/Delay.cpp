#include "Main.h";

Delay::Delay(int millis)
{
	if (millis < 0)
	{
		this->millisecs = 0;
	}
	else
	{
		this->millisecs = millis;
	}

	_isPlaying = false;
}

void Delay::play()
{
	playSync();
}

void Delay::playSync()
{
	_isPlaying = true;
	WAIT(millisecs);
	_isPlaying = false;
}

bool Delay::isPlaying()
{
	return _isPlaying;
}