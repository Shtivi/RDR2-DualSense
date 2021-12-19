#include "Main.h"

void playMusic(const char* musicName)
{
	while (!AUDIO::PREPARE_MUSIC_EVENT((char*)musicName))
	{
		WAIT(10);
	}
	AUDIO::TRIGGER_MUSIC_EVENT((char*)musicName);
}

void stopMusic(const char* musicName)
{
	AUDIO::CANCEL_MUSIC_EVENT((char*)musicName);
}

const char* getKeyboardInput(const char* title, const char* subtitle, const char* placeholder, int maxInputLength)
{
	MISC::DISPLAY_ONSCREEN_KEYBOARD(
		1,
		(char*)MISC::VAR_STRING(10, "LITERAL_STRING", title), 
		(char*)MISC::VAR_STRING(10, "LITERAL_STRING", subtitle), 
		(char*)placeholder, 
		"", 
		"", 
		"", 
		maxInputLength);
	
	int result = 0;
	while (!result)
	{
		result = MISC::UPDATE_ONSCREEN_KEYBOARD();
		WAIT(0);
	}

	if (result != 1)
	{
		return NULL;
	}

	return MISC::GET_ONSCREEN_KEYBOARD_RESULT();
}

int* getEventData(int eventIndex, int eventSize, int section)
{
	int* arr = new int[eventSize];

	if (!SCRIPTS::GET_EVENT_DATA(section, eventIndex, (Any*)arr, eventSize))
	{
		log("unexpected error: event has no data.");
		return NULL;
	}

	return arr;
}