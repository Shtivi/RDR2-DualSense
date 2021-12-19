#pragma once

void playMusic(const char* musicName);
void stopMusic(const char* musicName);
const char* getKeyboardInput(const char* title, const char* subtitle, const char* placeholder, int maxInputLength);
int* getEventData(int eventIndex, int eventSize, int section = 0);