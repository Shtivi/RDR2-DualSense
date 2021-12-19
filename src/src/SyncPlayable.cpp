#include "Main.h";

SyncPlayable::SyncPlayable()
{
	_isPlaying = false;
}

void SyncPlayable::playSync()
{
	_isPlaying = true;
	play();
	_isPlaying = false;
}

bool SyncPlayable::isPlaying()
{
	return _isPlaying;
}