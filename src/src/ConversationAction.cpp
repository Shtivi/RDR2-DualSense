#include "Main.h";

ConversationAction::ConversationAction(Ped performer, Object* taskSequence, int numberOfTasks) : IPlayable()
{
	this->performer = performer;
	this->sequence = taskSequence;
	this->numberOfTasks = numberOfTasks;
}

Ped ConversationAction::getPerformer()
{
	return performer;
}

void ConversationAction::play()
{
	TASK::TASK_PERFORM_SEQUENCE(performer, *sequence);
}

bool ConversationAction::isPlaying()
{
	int progress = TASK::GET_SEQUENCE_PROGRESS(performer);
	return progress != -1 && progress < numberOfTasks;
}

void ConversationAction::playSync()
{
	play();
	WAIT(400);
	while (isPlaying())
	{
		WAIT(50);
	}
}