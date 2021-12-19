#include "Main.h"


void showSubtitle(const char* text)
{
    UILOG::_UILOG_SET_CACHED_OBJECTIVE(MISC::VAR_STRING(10, "LITERAL_STRING", text));
    UILOG::_UILOG_PRINT_CACHED_OBJECTIVE();
    UILOG::_UILOG_CLEAR_CACHED_OBJECTIVE();
}

void showSubtitle(string text)
{
    showSubtitle(text.c_str());
}

void showSubtitle(int n)
{
    showSubtitle(to_string(n));
}

void showSubtitle(float f)
{
    showSubtitle(to_string(f));
}

void showSubtitle(bool b)
{
    showSubtitle(to_string(b));
}

void showSubtitle(Hash hash)
{
    showSubtitle(to_string((int)hash));
}