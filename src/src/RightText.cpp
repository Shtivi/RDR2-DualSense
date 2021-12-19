#include "Main.h"

char rightText[200] = { 0 };
int rightTextDuration;

void clearRightText()
{
    rightText[0] = 0;
}

void setRightText(const char* text, int duration)
{
    int i = 0;
    while (i < 200 && text[i])
    {
        rightText[i] = text[i];
        i++;
    }

    rightTextDuration = duration;
}

DurationsArgs rightTextArgs1;
UITextArgs rightTextArgs2;

const char* createVarString(const char* text) 
{
    const char* result;
    result = MISC::VAR_STRING(10, "LITERAL_STRING", text);
    int attempts = 500;
    while (strcmp(text, result) != 0 && attempts > 0)
    {
        log(attempts);
        attempts--;
        result = MISC::VAR_STRING(10, "LITERAL_STRING", text);
    }
    log(attempts);
    log(result);
    return result;
}

void printRightText()
{
    if (rightText[0])
    {
        rightTextArgs1.duration = rightTextDuration;
        rightTextArgs2.unk = 0;
        rightTextArgs2.text = MISC::VAR_STRING(10, "LITERAL_STRING", rightText);

        UIFEED::_SHOW_SIMPLE_RIGHT_TEXT((Any*)&rightTextArgs1, (Any*)&rightTextArgs2, 1);
        clearRightText();
    }
}