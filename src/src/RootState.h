#pragma once

#include "CompanionState.h"

class RootState
{
public:
	Ped candidateDog = NULL;
	Ped companionDog = NULL;
	Prompt* accompanyPrompt = NULL;
	Prompt* stayPrompt = NULL;
	Prompt* feedPrompt = NULL;
	Prompt* praisePrompt = NULL;
	Prompt* dismissPrompt = NULL;
	Prompt* followPrompt = NULL;
	Prompt* renamePrompt = NULL;
	Prompt* attackPrompt = NULL;
	Prompt* retrieveDogPrompt = NULL;
	ComapnionCoresUI* coresUI = NULL;
	DogCompanionInterface* companionApi = NULL;
	AsyncCompanionTask* currentTask;
	Blip companionBlip;
	float previousCompanionHealth;
	Stopwatch calmTimer;
	Stopwatch statsTimer;
	bool wasInsideInterior;
	bool isWithinWhistlingRange;
	bool didPlayerHadControlLastFrame;
};