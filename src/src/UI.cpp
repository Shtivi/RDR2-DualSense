#include "Main.h"

struct AdvancedNotificationArgs
{
	alignas(8) int unk;
	alignas(8) const char* title;
	alignas(8) const char* subtitle;
	alignas(8) int unk2;
	alignas(8) Hash iconDict;
	alignas(8) Hash icon;
};

void showAdvancedNotification(const char* title, const char* subtitle, const char* iconsDict, const char* icon, int duration)
{
	setToastArgs(title, subtitle, iconsDict, icon, duration);
}

void showAdvancedNotification(const char* title, const char* subtitle, Hash iconsDict, Hash icon, int duration)
{
	DurationsArgs* args1 = new DurationsArgs();
	args1->duration = duration;

	AdvancedNotificationArgs* args2 = new AdvancedNotificationArgs();
	args2->title = MISC::VAR_STRING(10, "LITERAL_STRING", title);
	args2->subtitle = MISC::VAR_STRING(10, "LITERAL_STRING", subtitle);
	args2->iconDict = iconsDict;
	args2->icon = icon;
	UIFEED::_SHOW_ADVANCED_NOTIFICATION((Any*)args1, (Any*)args2, 1, 1);
}

void showRightText(const char* text, int duration)
{
	setRightText(text, duration);
}


void showHelpText(const char* text, int duration)
{
	setHelpText(text, duration);
}

void updateUI()
{
	printHelpText();
	printRightText();
	showToast();
}

float getAspectRatio()
{
	return 16 / 9;
}