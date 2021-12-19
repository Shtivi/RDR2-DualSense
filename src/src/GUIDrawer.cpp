#include "Main.h";

void drawText(char* text, float x, float y, int r, int g, int b, int a, bool centered, float sx, float sy, const char* font)
{
	UIDEBUG::_BG_SET_TEXT_COLOR(r, g, b, a);
	UIDEBUG::_BG_SET_TEXT_SCALE(sx, sy);
	HUD::SET_TEXT_CENTRE(centered);

	stringstream tmplate;
	tmplate << "<FONT FACE='" << font <<"' COLOR='#ffffff'>" << text << "</FONT>";
	const char* InsertTemplate = MISC::VAR_STRING(10, "LITERAL_STRING", _strdup(tmplate.str().c_str()));
	UIDEBUG::_BG_DISPLAY_TEXT(MISC::VAR_STRING(42, "COLOR_STRING", 0, InsertTemplate), x, y);
}

void drawSprite(char* category, char* sprite, float x, float y, float scalex, float scaley, float rotation, int r, int g, int b, int a)
{
	float fX = x + scalex / 2;
	float fY = y + scaley / 2;
	if (!TXD::HAS_STREAMED_TEXTURE_DICT_LOADED(category))
	{
		TXD::REQUEST_STREAMED_TEXTURE_DICT(category, 0);
	}

	GRAPHICS::DRAW_SPRITE(category, sprite, fX, fY, scalex, scaley, rotation, r, g, b, a, 1);
	//TXD::SET_STREAMED_TEXTURE_DICT_AS_NO_LONGER_NEEDED(category);
}

void drawRect(float x, float y, float width, float height, int r, int g, int b, int a)
{
	float fX = x + width / 2;
	float fY = y + height / 2;
	GRAPHICS::DRAW_RECT(fX, fY, width, height, r, g, b, a, true, 0);
}

//void drawTitle(const char* text)
//{
//	drawText((char*)text, menuX + 0.13f, 0.076f + 0.02, 255, 255, 255, 255, true, 0.5f, 0.5f, "$title");
//	drawSprite("generic_textures", "list_item_h_line_narrow", menuX + 0.01, 0.131f + 0.041f, MENU_WIDTH * 0.9, 0.002f, 0, 255, 255, 255, MENU_ALPHA);
//}
//
//void drawHeader(const char* text)
//{
//	drawText((char*)text, menuX + 0.13f, 0.096f + 0.04f, 255, 255, 255, 255, true, 0.4f, 0.4f, "$title");
//}