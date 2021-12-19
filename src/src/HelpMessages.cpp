#include "Main.h";

char helpText[500] = { 0 };
int helpTextDuration;

void clearHelpText()
{
    for (int i = 0; i < 150; i++)
    {
        helpText[i] = 0;
    }
}

void setHelpText(const char* text, int duration)
{
    int i = 0;
    while (i < 500 && text[i])
    {
        helpText[i] = text[i];
        i++;
    }

    helpTextDuration = duration;
}

DurationsArgs helpTextArgs1;
UITextArgs helpTextArgs2;

void printHelpText()
{
    if (helpText[0])
    {
        helpTextArgs1.duration = helpTextDuration;
        helpTextArgs2.unk = 0;
        helpTextArgs2.text = MISC::VAR_STRING(10, "LITERAL_STRING", helpText);

        UIFEED::_SHOW_TOOLTIP((Any*)&helpTextArgs1, (Any*)&helpTextArgs2, 1);
        clearHelpText();
    }
}