#pragma once

#include "GUIDrawer.h"

struct RGB
{
	int r;
	int g;
	int b;
};

struct DurationsArgs {
	alignas(16) int duration;
};

struct UITextArgs
{
	alignas(8) int unk;
	alignas(8) const char* text;
};

void showAdvancedNotification(const char* title, const char* subtitle, const char* iconsDist, const char* icon, int duration = 5000);
void showAdvancedNotification(const char* title, const char* subtitle, Hash iconsDist, Hash icon, int duration = 5000);
void showRightText(const char* text, int duration = 5000);
void showHelpText(const char* text, int duration = 5000);
void setHelpText(const char* text, int duration = 10000);
void printHelpText();
void setRightText(const char* text, int duration = 4000);
void printRightText();
void setToastArgs(const char* title, const char* subtitle, const char* iconsDict, const char* icon, int duration = 5000);
void showToast();
void showMoneyNotification(int amountCents, int duration = 1000);
void updateUI();
float getAspectRatio();
