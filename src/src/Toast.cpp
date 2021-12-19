#include "Main.h"

struct ToastDurationArgs
{
	alignas(8) int duration;
	alignas(8) int unk0 = 0;
	alignas(8) int unk1 = 0;
	alignas(8) int unk2 = 0;
};

struct ToastArgs
{
	alignas(8) int unk = 0;
	alignas(8) const char* title;
	alignas(8) const char* subtitle;
	alignas(8) int unk2 = 0;
	alignas(8) Hash iconDict;
	alignas(8) Hash icon;
	alignas(8) int unk3 = 0;
	alignas(8) int unk4 = 0;
};

char toastIconsDict[100] = { 0 };
char toastIcon[100] = { 0 };
char toastTitle[100] = { 0 };
char toastSubtitle[100] = { 0 };

ToastDurationArgs toastArgs1;
ToastArgs toastArgs2;

void clearToast()
{
	for (int i = 0; i < 100; i++)
	{
		toastIconsDict[i] = 0;
		toastIcon[i] = 0;
		toastTitle[i] = 0;
		toastSubtitle[i] = 0;
	}
}

void setToastArgs(const char* title, const char* subtitle, const char* iconsDict, const char* icon, int duration)
{
	toastArgs1.duration = duration;
	strcpy(toastTitle, title);
	strcpy(toastSubtitle, subtitle);
	strcpy(toastIconsDict, iconsDict);
	strcpy(toastIcon, icon);
}

void showToast()
{
	if (toastTitle[0])
	{
		int i = 0;
		while (!TXD::HAS_STREAMED_TEXTURE_DICT_LOADED((char*)toastIconsDict) && i < 20)
		{
			TXD::REQUEST_STREAMED_TEXTURE_DICT((char*)toastIconsDict, 0);
			i++;
			WAIT(100);
		}

		toastArgs2.icon = MISC::GET_HASH_KEY(toastIcon);
		toastArgs2.iconDict = MISC::GET_HASH_KEY(toastIconsDict);
		toastArgs2.title = MISC::VAR_STRING(10, "LITERAL_STRING", toastTitle);
		toastArgs2.subtitle = MISC::VAR_STRING(10, "LITERAL_STRING", toastSubtitle);

		UIFEED::_SHOW_ADVANCED_NOTIFICATION((Any*)&toastArgs1, (Any*)&toastArgs2, 1, 1);
		clearToast();
	}
}