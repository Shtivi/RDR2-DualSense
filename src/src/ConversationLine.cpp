#include "Main.h";

ConversationLine::ConversationLine(Ped speaker, char* speechLine)
{
	this->_isPlaying = false;
	this->speaker = speaker;
	this->speechLineName = speechLine;
}

bool ConversationLine::isPlaying()
{
	return (AUDIO::IS_ANY_SPEECH_PLAYING(speaker));
}

void ConversationLine::play()
{
	before();
	playAmbientSpeech(speaker, speechLineName);
	after();
}

void ConversationLine::playSync()
{
	before();
	playAmbientSpeech(speaker, speechLineName);
	while (isPlaying())
	{
		WAIT(100);
	}
	after();
}

Ped ConversationLine::getSpeaker()
{
	return speaker;
}

void ConversationLine::before()
{
}

void ConversationLine::after()
{
}