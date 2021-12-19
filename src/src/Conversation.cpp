#include "Main.h";
#include <thread>

Conversation::Conversation()
{
}

bool Conversation::isPlaying()
{
	return _isPlaying;
}

bool Conversation::isEnded()
{
	return _isEnded;
}

void Conversation::addLine(IPlayable* line)
{
	lines.insert(lines.end(), line);
}

void Conversation::addLine(Ped speaker, char* speechLineName)
{
	ConversationLine* line = new ConversationLine(speaker, speechLineName);
	addLine(line);
}

void Conversation::addDelay(int millisecs)
{
	addLine(new Delay(millisecs));
}

void Conversation::addAction(Ped performer, Object* sequence, int numberOfTasks)
{
	addLine(new ConversationAction(performer, sequence, numberOfTasks));
}

void Conversation::play()
{
	IPlayable* currLine;
	IPlayable* prevLine = NULL;
	vector<IPlayable*>::iterator lineItr = lines.begin();

	_isPlaying = true;
	_isEnded = false;

	while (lineItr != lines.end())
	{
		currLine = (*lineItr);

		while (currLine->isPlaying())
		{
			WAIT(100);
		}
		currLine->playSync();
		prevLine = currLine;

		lineItr++;
	}

	_isPlaying = false;
	_isEnded = true;
}