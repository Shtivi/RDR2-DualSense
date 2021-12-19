//#include "Main.h"
////void (const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center)
////{
////
////	UI::SET_TEXT_CENTRE(center);
////	UI::SET_TEXT_COLOUR(rgbaf.r, rgbaf.g, rgbaf.b, rgbaf.a);
////	UI::SET_TEXT_FONT(rgbaf.f);
////	UI::SET_TEXT_SCALE(size.w, size.h);
////	UI::SET_TEXT_DROPSHADOW(1, 0, 0, 0, 0);
////	UI::SET_TEXT_EDGE(1, 0, 0, 0, 0);
////	UI::SET_TEXT_OUTLINE();
////	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
////	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text);
////	UI::END_TEXT_COMMAND_DISPLAY_TEXT(position.x, position.y);
////}
//void Menu::Drawing::Text(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center){
//	//x /= globals::resolution.right; y /= globals::resolution.bottom;
//	UI::SET_TEXT_SCALE(size.w, size.h);
//	UI::_SET_TEXT_COLOR(rgbaf.r, rgbaf.g, rgbaf.b, rgbaf.a);
//	UI::SET_TEXT_CENTRE(center);
//	UI::SET_TEXT_DROPSHADOW(1, 0, 0, 0, 0);
//	auto str = UI::_CREATE_VAR_STRING(10, "LITERAL_STRING", text);
//	UI::_DRAW_TEXT(str, position.x, position.y);
//}
//
//
//void Menu::Drawing::Spriter(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
//{
//	if (!TEXTURE::HAS_STREAMED_TEXTURE_DICT_LOADED((char*)Streamedtexture.c_str()))
//	{
//		TEXTURE::REQUEST_STREAMED_TEXTURE_DICT((char*)Streamedtexture.c_str(), false);
//	}
//	else
//	{
//		GRAPHICS::DRAW_SPRITE((char*)Streamedtexture.c_str(), (char*)textureName.c_str(), x, y, width, height, rotation, r, g, b, a, NULL);
//	}
//}
//
//void Menu::Drawing::Rect(RGBA rgba, VECTOR2 position, VECTOR2_2 size)
//{
//	GRAPHICS::DRAW_RECT(position.x, position.y, size.w, size.h, rgba.r, rgba.g, rgba.b, rgba.a, NULL, NULL);
//}
//
//float gGlareDir;
//float conv360(float base, float min, float max)
//{
//	float fVar0;
//	if (min == max) return min;
//	fVar0 = max - min;
//	base -= SYSTEM::ROUND(base - min / fVar0) * fVar0;
//	if (base < min) base += fVar0;
//	return base;
//}
//
//
//float Menu::Settings::menuX = 0.17f;
//bool Menu::Settings::selectPressed = false;
//bool Menu::Settings::leftPressed = false;
//bool Menu::Settings::rightPressed = false;
//bool firstopen = true;
//int Menu::Settings::maxVisOptions = 16;
//int Menu::Settings::currentOption = 0;
//int Menu::Settings::optionCount = 0;
//SubMenus Menu::Settings::currentMenu;
//int Menu::Settings::menuLevel = 0;
//int Menu::Settings::optionsArray[1000];
//SubMenus Menu::Settings::menusArray[1000];
//
//RGBAF Menu::Settings::count{ 255, 255, 255, 255, 6 };
//RGBAF Menu::Settings::titleText{ 255, 255, 255, 255, 7 };
//RGBA Menu::Settings::titleRect = { 0, 0, 0, 255 };//{ 0, 0, 0, 255 };
//RGBAF Menu::Settings::optionText{ 255, 255, 255, 255, 6 };
//RGBAF Menu::Settings::breakText{ 255, 255, 255, 255, 1 };
//RGBAF Menu::Settings::arrow{ 255, 255, 255, 255, 3 };                          // Mod Menu Colors 
//RGBA Menu::Settings::optionRect{ 0, 0, 0, 110 };
////RGBA Menu::Settings::titleEnd{ 0, 0, 0, 255 };
//RGBA Menu::Settings::scroller{ 0, 0, 0, 255 };
//RGBAF Menu::Settings::integre{ 255, 255, 255, 255, 2 };
//RGBA Menu::Settings::line{ 255, 255, 255, 255 };
//RGBA Menu::Settings::primary{ 255, 0, 0 };
//RGBA Menu::Settings::secondary{ 0, 255, 0 };
//void Menu::Title(const char* title)
//{
//	Drawing::Text(title, Settings::titleText, { Settings::menuX, 0.095f }, { 0.85f, 0.85f }, true);
//	Drawing::Rect(Settings::titleRect, { Settings::menuX, 0.1175f }, { 0.21f, 0.085f });
//
//	// Disable Settings
//	//UI::HIDE_HELP_TEXT_THIS_FRAME();
//	CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
//	//UI::HIDE_HUD_COMPONENT_THIS_FRAME(10);
//	//UI::HIDE_HUD_COMPONENT_THIS_FRAME(6);
//	//UI::HIDE_HUD_COMPONENT_THIS_FRAME(7);
//	//UI::HIDE_HUD_COMPONENT_THIS_FRAME(9);
//	//UI::HIDE_HUD_COMPONENT_THIS_FRAME(8);
//	//Settings::DISABLE_CONTROL_ACTION(2, INPUT_NEXT_CAMERA, true);
//	//Settings::DISABLE_CONTROL_ACTION(2, INPUT_CHARACTER_WHEEL, true);
//	//Settings::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_LIGHT, true);
//	//Settings::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_HEAVY, true);
//	//Settings::DISABLE_CONTROL_ACTION(2, INPUT_MULTIPLAYER_INFO, true);
//	//Settings::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
//	//Settings::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_ALTERNATE, true);
//	//Settings::DISABLE_CONTROL_ACTION(2, INPUT_VEH_CIN_CAM, true);
//	//Settings::DISABLE_CONTROL_ACTION(2, INPUT_MAP_POI, true);
//	//Settings::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
//	//Settings::DISABLE_CONTROL_ACTION(2, INPUT_VEH_RADIO_WHEEL, true);
//	//Settings::DISABLE_CONTROL_ACTION(2, INPUT_VEH_HEADLIGHT, true);
//}
//bool Menu::SpawnOption(char* option, char* carname)
//{
//	Menu::Settings::optionCount++;
//	bool onThis = Menu::Settings::currentOption == Menu::Settings::optionCount ? true : false;
//	if (Menu::Settings::currentOption <= 16 && Menu::Settings::optionCount <= 16)
//	{
//		Menu::Drawing::Text(option, Menu::Settings::optionText, { Menu::Settings::menuX - 0.100f, (Menu::Settings::optionCount) * 0.035f + 0.125f }, { 0.45f, 0.45f }, false);
//		Menu::Drawing::Rect(Menu::Settings::optionRect, { Menu::Settings::menuX, (Menu::Settings::optionCount) * 0.035f + 0.1415f }, { 0.21f, 0.035f });
//		onThis ? Menu::Drawing::Rect(Menu::Settings::scroller, { Menu::Settings::menuX, (Menu::Settings::optionCount) * 0.035f + 0.1415f }, { 0.21f, 0.035f }) : NULL;
//	}
//	else if (Menu::Settings::optionCount > (Menu::Settings::currentOption - 16) && Menu::Settings::optionCount <= Menu::Settings::currentOption)
//	{
//		Menu::Drawing::Text(option, Menu::Settings::optionText, { Menu::Settings::menuX - 0.100f, (Menu::Settings::optionCount - (Menu::Settings::currentOption - 16)) * 0.035f + 0.125f }, { 0.45f, 0.45f }, false);
//		Menu::Drawing::Rect(Menu::Settings::optionRect, { Menu::Settings::menuX,  (Menu::Settings::optionCount - (Menu::Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.21f, 0.035f });
//		onThis ? Menu::Drawing::Rect(Menu::Settings::scroller, { Menu::Settings::menuX,  (Menu::Settings::optionCount - (Menu::Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.21f, 0.035f }) : NULL;
//	}
//	static Vehicle Veh;
//	static int timer;
//	if (carname == "DELETE") {
//		ENTITY::DELETE_ENTITY(&Veh);
//		goto skipTick;
//	}
//	Hash hash = GAMEPLAY::GET_HASH_KEY(carname);
//	Ped Player = PLAYER::PLAYER_PED_ID();
//	float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
//	if (Menu::Settings::currentOption == Menu::Settings::optionCount)
//	{
//		if (STREAMING::IS_MODEL_VALID(hash))
//		{
//			if (ENTITY::GET_ENTITY_MODEL(Veh) == hash) {
//				float heading = ENTITY::GET_ENTITY_HEADING(Veh);
//
//				Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Player, 0, 7.0f, 0.5f);
//				ENTITY::SET_ENTITY_COORDS(Veh, Coords.x, Coords.y, Coords.z, false, false, false, false);
//
//				ENTITY::SET_ENTITY_HEADING(Veh, heading >= 360.f ? 0 : heading + 0.5f);
//				ENTITY::SET_ENTITY_COLLISION(Veh, false, false);
//				// VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(Veh);
//
//				goto skipTick;
//			}
//			else
//			{
//				ENTITY::DELETE_ENTITY(&Veh);
//			}
//
//			//if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) SpawnVeh2(carname);
//			STREAMING::REQUEST_MODEL(hash, true);
//			if (!STREAMING::HAS_MODEL_LOADED(hash)) goto skipTick;
//
//			Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Player, 0, 4.0f, 0.5f);
//
//
//			Veh = VEHICLE::CREATE_VEHICLE(hash, Coords.x, Coords.y, Coords.z, heading, true, true, true, true);
//			// VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(Veh);
//			ENTITY::SET_ENTITY_COLLISION(Veh, false, false);
//			ENTITY::SET_ENTITY_ALPHA(Veh, 200, 0);
//			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
//		skipTick:;
//
//		}
//		if (Menu::Settings::selectPressed)
//		{
//
//			SpawnVeh2(carname);
//			return true;
//		}
//	}
//	return false;
//}
//void Option(char* option)
//{
//	Menu::Settings::optionCount++;
//	bool onThis = Menu::Settings::currentOption == Menu::Settings::optionCount ? true : false;
//	if (Menu::Settings::currentOption <= 16 && Menu::Settings::optionCount <= 16)
//	{
//		Menu::Drawing::Text(option, Menu::Settings::optionText, { Menu::Settings::menuX - 0.100f, (Menu::Settings::optionCount) * 0.035f + 0.125f }, { 0.45f, 0.45f }, false);
//		Menu::Drawing::Rect(Menu::Settings::optionRect, { Menu::Settings::menuX, (Menu::Settings::optionCount) * 0.035f + 0.1415f }, { 0.21f, 0.035f });
//		onThis ? Menu::Drawing::Rect(Menu::Settings::scroller, { Menu::Settings::menuX, (Menu::Settings::optionCount) * 0.035f + 0.1415f }, { 0.21f, 0.035f }) : NULL;
//	}
//	else if (Menu::Settings::optionCount > (Menu::Settings::currentOption - 16) && Menu::Settings::optionCount <= Menu::Settings::currentOption)
//	{
//		Menu::Drawing::Text(option, Menu::Settings::optionText, { Menu::Settings::menuX - 0.100f, (Menu::Settings::optionCount - (Menu::Settings::currentOption - 16)) * 0.035f + 0.125f }, { 0.45f, 0.45f }, false);
//		Menu::Drawing::Rect(Menu::Settings::optionRect, { Menu::Settings::menuX,  (Menu::Settings::optionCount - (Menu::Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.21f, 0.035f });
//		onThis ? Menu::Drawing::Rect(Menu::Settings::scroller, { Menu::Settings::menuX,  (Menu::Settings::optionCount - (Menu::Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.21f, 0.035f }) : NULL;
//	}
//}
//bool Menu::Option(const char* option)
//{
//	Settings::optionCount++;
//	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
//	if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
//	{
//		Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.100f, (Settings::optionCount) * 0.035f + 0.125f }, { 0.45f, 0.45f }, false);
//		Drawing::Rect(Settings::optionRect, { Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.21f, 0.035f });
//		onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.21f, 0.035f }) : NULL;
//	}
//	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
//	{
//		Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.100f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.125f }, { 0.45f, 0.45f }, false);
//		Drawing::Rect(Settings::optionRect, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.21f, 0.035f });
//		onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.21f, 0.035f }) : NULL;
//	}
//	if (Settings::currentOption == Settings::optionCount)
//	{
//		if (Settings::selectPressed)
//		{
//			return true;
//		}
//	}
//	return false;
//}
//bool Menu::Break(const char* option)
//{
//	Settings::optionCount++;
//	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
//	if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
//	{
//		Drawing::Text(option, Settings::breakText, { Settings::menuX, (Settings::optionCount) * 0.035f + 0.125f }, { 0.45f, 0.45f }, true);
//		Drawing::Rect(Settings::optionRect, { Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.21f, 0.035f });
//	}
//	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
//	{
//		Drawing::Text(option, Settings::breakText, { Settings::menuX, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.125f }, { 0.45f, 0.45f }, true);
//		Drawing::Rect(Settings::optionRect, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.21f, 0.035f });
//	}
//	return false;
//}
//bool Menu::MenuOption(const char* option, SubMenus newSub)
//{
//	Option(option);
//	RGBAF arrow2{ 255, 0, 0, 255, 3 };
//	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
//	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
//		Drawing::Text(">", onThis ? arrow2 : Settings::arrow, { Settings::menuX + 0.099f, Settings::optionCount * 0.035f + 0.128f }, { 0.25f, 0.25f }, true);
//	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
//		Drawing::Text(">", onThis ? arrow2 : Settings::arrow, { Settings::menuX + 0.099f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.12f }, { 0.25f, 0.25f }, true);
//
//	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
//		MenuLevelHandler::MoveMenu(newSub);
//		return true;
//	}
//	return false;
//}
//
//void Menu::PlayerOption(int i) {
//	if (Menu::Option(PLAYER::GET_PLAYER_NAME(i))) {
//		RDR2selectedPlayer = i;
//		MenuLevelHandler::MoveMenu(pmenu);
//	}
//}
//
//bool Menu::Toggle(const char* option, bool& b00l)
//{
//	Option(option);
//	if (b00l)
//	{
//		if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
//			Drawing::Text(b00l ? "~g~ON" : "~r~OFF", Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.128f }, { 0.40f, 0.40f }, true); // 0.35 // 0.125 // 0.45
//		else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
//			Drawing::Text(b00l ? "~g~ON" : "~r~OFF", Settings::optionText, { Settings::menuX + 0.069f, Settings::optionCount * 0.035f + 0.128f }, { 0.40f, 0.40f }, true);
//	}
//	else
//	{
//		if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
//			Drawing::Text(b00l ? "~g~ON" : "~r~OFF", Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.128f }, { 0.40f, 0.40f }, true);
//		else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
//			Drawing::Text(b00l ? "~g~ON" : "~r~OFF", Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.128f }, { 0.40f, 0.40f }, true);
//	}
//	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
//		b00l ^= 1;
//		return true;
//	}
//	return false;
//}
//bool Menu::Int(const char* option, int& _int, int min, int max)
//{
//	Option(option);
//
//	if (Settings::optionCount == Settings::currentOption) {
//		if (Settings::leftPressed) {
//			_int < max ? _int++ : _int = min;
//		}
//		if (Settings::rightPressed) {
//			_int >= min ? _int-- : _int = max;
//		}
//	}
//
//	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
//		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.128f }, { 0.32f, 0.32f }, true);
//	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
//		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.12f }, { 0.32f, 0.32f }, true);
//
//	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
//	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
//	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
//	return false;
//}
//bool Menu::Int(const char* option, int& _int, int min, int max, int step)
//{
//	Option(option);
//
//	if (Settings::optionCount == Settings::currentOption) {
//		if (Settings::leftPressed) {
//			_int < max ? _int += step : _int = min;
//		}
//		if (Settings::rightPressed) {
//			_int >= min ? _int -= step : _int = max;
//		}
//	}
//
//	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
//		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.125f }, { 0.32f, 0.32f }, true);
//	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
//		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.12f }, { 0.32f, 0.32f }, true);
//
//	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
//	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
//	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
//	return false;
//}
//#pragma warning(disable: 4244)
//bool Menu::Float(const char* option, float& _float, int min, int max)
//{
//	Option(option);
//
//	if (Settings::optionCount == Settings::currentOption) {
//		if (Settings::leftPressed) {
//			_float <= min ? _float = max : _float -= 0000.1000f;
//		}
//		if (Settings::rightPressed) {
//			_float >= max ? _float = min : _float += 0000.1000f;
//		}
//		_float < min ? _float = max : _float > max ? _float = min : NULL;
//	}
//
//	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
//		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.128f }, { 0.32f, 0.32f }, true);
//	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
//		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.12f }, { 0.32f, 0.32f }, true);
//
//	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
//	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
//	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
//	return false;
//}
//bool Menu::Float(const char* option, float& _float, int min, int max, int step)
//{
//	Option(option);
//
//	if (Settings::optionCount == Settings::currentOption) {
//		if (Settings::leftPressed) {
//			_float <= min ? _float = max : _float -= 0.1f;
//		}
//		if (Settings::rightPressed) {
//			_float >= max ? _float = min : _float += 0.1f;
//		}
//		_float < min ? _float = max : _float > max ? _float = min : NULL;
//	}
//
//	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
//		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.128f }, { 0.32f, 0.32f }, true);
//	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
//		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.12f }, { 0.32f, 0.32f }, true);
//
//	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
//	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
//	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
//	return false;
//}
//#pragma warning(default: 4244)
//#pragma warning(disable: 4267)
//bool Menu::IntVector(const char* option, std::vector<int> Vector, int& position)
//{
//	Option(option);
//
//	if (Settings::optionCount == Settings::currentOption) {
//		int max = Vector.size() - 1;
//		int min = 0;
//		if (Settings::leftPressed) {
//			position >= 1 ? position-- : position = max;
//		}
//		if (Settings::rightPressed) {
//			position < max ? position++ : position = min;
//		}
//	}
//
//	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
//		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
//	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
//		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.12f }, { 0.5f, 0.5f }, true);
//
//	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
//	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
//	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
//	return false;
//}
//bool Menu::FloatVector(const char* option, std::vector<float> Vector, int& position)
//{
//	Option(option);
//
//	if (Settings::optionCount == Settings::currentOption) {
//		size_t max = Vector.size() - 1;
//		int min = 0;
//		if (Settings::leftPressed) {
//			position >= 1 ? position-- : position = max;
//		}
//		if (Settings::rightPressed) {
//			position < max ? position++ : position = min;
//		}
//	}
//
//	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
//		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
//	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
//		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.12f }, { 0.5f, 0.5f }, true);
//
//	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
//	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
//	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
//	return false;
//}
//bool Menu::StringVector(const char* option, std::vector<std::string> Vector, int& position)
//{
//	Option(option);
//
//	if (Settings::optionCount == Settings::currentOption) {
//		size_t max = Vector.size() - 1;
//		int min = 0;
//		if (Settings::leftPressed) {
//			position >= 1 ? position-- : position = max;
//		}
//		if (Settings::rightPressed) {
//			position < max ? position++ : position = min;
//		}
//	}
//
//	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
//		Drawing::Text(Tools::StringToChar((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
//	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
//		Drawing::Text(Tools::StringToChar((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.12f }, { 0.5f, 0.5f }, true);
//
//	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
//	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
//	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
//	return false;
//}
//bool Menu::StringVector(const char* option, std::vector<char*> Vector, int& position)
//{
//	Option(option);
//
//	if (Settings::optionCount == Settings::currentOption) {
//		size_t max = Vector.size() - 1;
//		int min = 0;
//		if (Settings::leftPressed) {
//			position >= 1 ? position-- : position = max;
//		}
//		if (Settings::rightPressed) {
//			position < max ? position++ : position = min;
//		}
//	}
//
//	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
//		Drawing::Text(((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
//	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
//		Drawing::Text(((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.12f }, { 0.5f, 0.5f }, true);
//
//	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
//	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
//	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
//	return false;
//}
//#pragma warning(default: 4267)
//bool Menu::Teleport(const char* option, Vector3 coords)
//{
//	Option(option);
//
//	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
//		Entity handle = PLAYER::PLAYER_PED_ID();
//		PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : PLAYER::PLAYER_PED_ID();
//		ENTITY::SET_ENTITY_COORDS(handle, coords.x, coords.y, coords.z, false, false, false, false);
//		return true;
//	}
//	return false;
//}
//bool Menu::Teleport(const char* option, Vector3 coords, std::function<void()> function)
//{
//	Teleport(option, coords);
//
//	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
//		function();
//		return true;
//	}
//	return false;
//}
//void Menu::info(const char* info)
//{
//	if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
//	{
//		if (bool onThis = true) { Drawing::Text(info, Settings::optionText, { Settings::menuX - 0.100f, 17 * 0.035f + 0.1600f }, { 0.25f, 0.25f }, false); }
//	}
//	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
//	{
//		if (bool onThis = true) { Drawing::Text(info, Settings::optionText, { Settings::menuX - 0.100f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1300f }, { 0.25f, 0.25f }, false); }
//	}
//}
//void Menu::End()
//{
//	int opcount = Settings::optionCount;
//	int currop = Settings::currentOption;
//	if (opcount >= 16) {
//		Drawing::Text(Tools::StringToChar(std::to_string(currop) + " / " + std::to_string(opcount)), Settings::count, { Settings::menuX + 0.078f, 17 * 0.035f + 0.125f }, { 0.35f, 0.35f }, true);
//		Drawing::Rect(Settings::optionRect, { Settings::menuX, 17 * 0.035f + 0.1415f }, { 0.21f, 0.035f });
//		Drawing::Rect(Settings::line, { Settings::menuX, 17 * 0.035f + 0.1235f }, { 0.21f, 0.002f });
//		//Drawing::Spriter("commonmenu", "shop_arrows_upanddown", Settings::menuX, ((16 + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 180, Settings::line.r, Settings::line.g, Settings::line.b, Settings::line.a);
//	}
//	else if (opcount > 0) {
//		Drawing::Text(Tools::StringToChar(std::to_string(currop) + " / " + std::to_string(opcount)), Settings::count, { Settings::menuX + 0.078f, (Settings::optionCount + 1) * 0.035f + 0.125f }, { 0.35f, 0.35f }, true);
//		Drawing::Rect(Settings::optionRect, { Settings::menuX, (Settings::optionCount + 1) * 0.035f + 0.1415f }, { 0.21f, 0.035f });
//		Drawing::Rect(Settings::line, { Settings::menuX, (Settings::optionCount + 1) * 0.035f + 0.1235f }, { 0.21f, 0.002f });
//		//Drawing::Spriter("commonmenu", "shop_arrows_upanddown", Settings::menuX, ((Settings::optionCount + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 180, Settings::line.r, Settings::line.g, Settings::line.b, Settings::line.a);
//	}
//}
//
////int IconNotification(char* text, char* text2, char* Subject)
////{
////	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
////	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
////	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG("CHAR_GANGAPP", "CHAR_GANGAPP", false, 7, text2, Subject, 1.0, "___Menu");
////	return UI::_DRAW_NOTIFICATION(1, 1);
////}
////void PlaySoundFrontend_default(char* sound_name)
////{
////	AUDIO::PLAY_SOUND_FRONTEND(-1, sound_name, "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
////}
////void PlaySoundFrontend_default2(char* sound_name)
////{
////	AUDIO::PLAY_SOUND_FRONTEND(-1, sound_name, "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS", 0);
////}
//
//int Menu::Settings::keyPressDelay = 200;
//int Menu::Settings::keyPressPreviousTick = GetTickCount();
//int Menu::Settings::keyPressDelay2 = 100;
//int Menu::Settings::keyPressPreviousTick2 = GetTickCount();
//int Menu::Settings::keyPressDelay3 = 140;
//int Menu::Settings::keyPressPreviousTick3 = GetTickCount();
//int Menu::Settings::openKey = VK_MULTIPLY;
//int Menu::Settings::backKey = VK_NUMPAD0;
//int Menu::Settings::upKey = VK_NUMPAD8;
//int Menu::Settings::downKey = VK_NUMPAD2;
//int Menu::Settings::leftKey = VK_NUMPAD4;
//int Menu::Settings::rightKey = VK_NUMPAD6;
//int Menu::Settings::selectKey = VK_NUMPAD5;
//int Menu::Settings::arrowupKey = VK_UP;
//int Menu::Settings::arrowdownKey = VK_DOWN;
//int Menu::Settings::arrowleftKey = VK_LEFT;
//int Menu::Settings::arrowrightKey = VK_RIGHT;
//int Menu::Settings::enterKey = VK_RETURN;
//int Menu::Settings::deleteKey = VK_BACK;
//
//#pragma endregion
//
//bool Menu::Settings::controllerinput = true;
//void Menu::Checks::Controlls()
//{
//	Settings::selectPressed = false;
//	Settings::leftPressed = false;
//	Settings::rightPressed = false;
//	if (GetTickCount() - Settings::keyPressPreviousTick > Settings::keyPressDelay) {
//		if (GetTickCount() - Settings::keyPressPreviousTick2 > Settings::keyPressDelay2) {
//			if (GetTickCount() - Settings::keyPressPreviousTick3 > Settings::keyPressDelay3) {
//				if (IsKeyPressed(VK_F5)) {
//					Settings::menuLevel == 0 ? MenuLevelHandler::MoveMenu(SubMenus::mainmenu) : Settings::menuLevel == 1 ? MenuLevelHandler::BackMenu() : NULL;
//					Settings::keyPressPreviousTick = GetTickCount();
//				}
//				else if (IsKeyPressed(VK_NUMPAD0)) {
//					Settings::menuLevel > 0 ? MenuLevelHandler::BackMenu() : NULL;
//					if (Settings::menuLevel > 0)
//					//	PlaySoundFrontend_default("BACK");
//
//					Settings::keyPressPreviousTick = GetTickCount();
//				}
//				else if (IsKeyPressed(VK_NUMPAD8)) {
//					Settings::currentOption > 1 ? Settings::currentOption-- : Settings::currentOption = Settings::optionCount;
//					if (Settings::menuLevel > 0)
//					//	PlaySoundFrontend_default("NAV_UP_DOWN");
//
//					Settings::keyPressPreviousTick2 = GetTickCount();
//				}
//				else if (IsKeyPressed(VK_NUMPAD2)) {
//					Settings::currentOption < Settings::optionCount ? Settings::currentOption++ : Settings::currentOption = 1;
//					if (Settings::menuLevel > 0)
//						//PlaySoundFrontend_default("NAV_UP_DOWN");
//
//					Settings::keyPressPreviousTick2 = GetTickCount();
//				}
//				else if (IsKeyPressed(VK_NUMPAD6)) {
//					Settings::leftPressed = true;
//					if (Settings::menuLevel > 0)
//					//	PlaySoundFrontend_default("NAV_UP_DOWN");
//
//					Settings::keyPressPreviousTick3 = GetTickCount();
//				}
//				else if (IsKeyPressed(VK_NUMPAD4)) {
//					Settings::rightPressed = true;
//					if (Settings::menuLevel > 0)
//						//PlaySoundFrontend_default("NAV_UP_DOWN");
//
//					Settings::keyPressPreviousTick3 = GetTickCount();
//				}
//				else if (IsKeyPressed(VK_NUMPAD5)) {
//					Settings::selectPressed = true;
//					if (Settings::menuLevel > 0)
//					//	PlaySoundFrontend_default("SELECT");
//
//					Settings::keyPressPreviousTick = GetTickCount();
//				}
//			}
//		}
//	}
//	Settings::optionCount = 0;
//}
//#pragma warning(default : 4018)
//void Menu::MenuLevelHandler::MoveMenu(SubMenus menu)
//{
//	Settings::menusArray[Settings::menuLevel] = Settings::currentMenu;
//	Settings::optionsArray[Settings::menuLevel] = Settings::currentOption;
//	Settings::menuLevel++;
//	Settings::currentMenu = menu;
//	Settings::currentOption = 1;
//}
//
//void Menu::MenuLevelHandler::BackMenu()
//{
//	Settings::menuLevel--;
//	Settings::currentMenu = Settings::menusArray[Settings::menuLevel];
//	Settings::currentOption = Settings::optionsArray[Settings::menuLevel];
//}
//
//char* Menu::Tools::StringToChar(std::string string)
//{
//	return _strdup(string.c_str());
//}
//
//void Menu::Files::WriteStringToIni(std::string string, std::string file, std::string app, std::string key)
//{
//	WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), file.c_str());
//}
//
//std::string Menu::Files::ReadStringFromIni(std::string file, std::string app, std::string key)
//{
//	char buf[100];
//	GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, file.c_str());
//	return (std::string)buf;
//}
//
//void Menu::Files::WriteIntToIni(int intValue, std::string file, std::string app, std::string key)
//{
//	WriteStringToIni(std::to_string(intValue), file, app, key);
//}
//
//int Menu::Files::ReadIntFromIni(std::string file, std::string app, std::string key)
//{
//	return std::stoi(ReadStringFromIni(file, app, key));
//}
//
//void Menu::Files::WriteFloatToIni(float floatValue, std::string file, std::string app, std::string key)
//{
//	WriteStringToIni((std::to_string(floatValue)), file, app, key);
//}
//
//float Menu::Files::ReadFloatFromIni(std::string file, std::string app, std::string key)
//{
//	return std::stof(ReadStringFromIni(file, app, key));
//}
//
//void Menu::Files::WriteBoolToIni(bool b00l, std::string file, std::string app, std::string key)
//{
//	WriteStringToIni(b00l ? "true" : "false", file, app, key);
//}
//
//bool Menu::Files::ReadBoolFromIni(std::string file, std::string app, std::string key)
//{
//	return ReadStringFromIni(file, app, key) == "true" ? true : false;
//}
//
//void Menu::Speedometer(char* text)
//{
//	Drawing::Text(text, Settings::titleText, { 0.84f, 0.8800f }, { 0.70f, 0.70f }, false);
//}
//void Menu::fps(char* text)
//{
//	Drawing::Text(text, Settings::optionText, { 0.84f, 0.050f }, { 0.70f, 0.70f }, false);
//}
//void Menu::AddSmallTitle(char* text)
//{
//	if (Menu::Settings::menuX < 0.78f)
//	{
//		Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
//		Drawing::Spriter("CommonMenu", "", Settings::menuX + 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
//	}
//	else
//	{
//		Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
//		Drawing::Spriter("CommonMenu", "", Settings::menuX - 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
//	}
//}
//void Menu::AddSmallInfo(char* text, short line)
//{
//	if (Menu::Settings::menuX < 0.78f)
//	{
//		if (line == 1) {
//			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, ((16 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 16 * 0.035f + -0.193f });
//		}
//		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
//	}
//	else
//	{
//		if (line == 1) {
//			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, ((16 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 16 * 0.035f + -0.193f });
//		}
//		Drawing::Text(text, Settings::count, { Settings::menuX - 0.228f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
//	}
//}
//void Menu::AddSmallTitle2(char* text)
//{
//	if (Menu::Settings::menuX < 0.78f)
//	{
//		Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
//		Drawing::Spriter("CommonMenu", "", Settings::menuX + 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
//	}
//	else
//	{
//		Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
//		Drawing::Spriter("CommonMenu", "", Settings::menuX - 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
//	}
//}
//
//void Menu::AddSmallInfo2(char* text, short line)
//{
//	if (Menu::Settings::menuX < 0.78f)
//	{
//		if (line == 1) {
//			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
//		}
//		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
//	}
//	else
//	{
//		if (line == 1) {
//			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
//		}
//		Drawing::Text(text, Settings::count, { Settings::menuX - 0.228f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
//	}
//}
//
//void Menu::AddSmallTitle3(char* text)
//{
//	if (Menu::Settings::menuX < 0.78f)
//	{
//		Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
//		Drawing::Spriter("CommonMenu", "", Settings::menuX + 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
//	}
//	else
//	{
//		Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
//		Drawing::Spriter("CommonMenu", "", Settings::menuX - 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
//	}
//}
//
//void Menu::AddSmallInfo3(char* text, short line)
//{
//	if (Menu::Settings::menuX < 0.78f)
//	{
//		if (line == 1) {
//			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, ((11 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 11 * 0.035f + -0.193f });
//		}
//		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
//	}
//	else
//	{
//		if (line == 1) {
//			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, ((11 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 11 * 0.035f + -0.193f });
//		}
//		Drawing::Text(text, Settings::count, { Settings::menuX - 0.228f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
//	}
//}