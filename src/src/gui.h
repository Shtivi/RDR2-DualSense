#pragma once
enum SubMenus { 
	NOMENU,
	mainmenu,
	test,
	sub,
	Weapons, 
	gunshop,
	vehoptions,
	weather,
	vehspawner,
	settings,
	exitgta,
	settingstheme,
	Credits,
	themeloader,
	settingstitlerect,
	settingsscroller,
	settingsoptiontext,
	font,
	plist,
	pmenu,
};
extern enum SubMenus;

typedef struct VECTOR2 {
	float x, y;
};
typedef struct VECTOR2_2 {
	float w, h;
};
typedef struct RGBAF {
	int r, g, b, a, f;
};
typedef struct RGBA {
	int r, g, b, a;
};
typedef struct RGB {
	int r, g, b;
};

namespace Sponner// setup for debugging
{
	extern char* ObjectString;
	extern bool LoadingObject;
	extern int spawnedprops;
}
namespace Menu {
	namespace Drawing {
		void Text(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center);
		void Title(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center);
		void Rect(RGBA rgba, VECTOR2 position, VECTOR2_2 size);
		void Spriter(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);
	}
	namespace Settings {
		extern bool selectPressed;
		extern bool leftPressed;
		extern bool rightPressed;
		extern bool center;
		extern bool controllerinput;

		extern int maxVisOptions;
		extern int currentOption;
		extern int optionCount;

		extern SubMenus currentMenu;
		extern int menuLevel;
		extern int optionsArray[1000];
		extern SubMenus menusArray[1000];

		extern float menuX;
		extern RGBAF count;
		extern RGBAF titleText;
		extern RGBA titleRect;
		extern RGBAF breakText;
		extern RGBAF optionText;
		extern RGBA selectedText;
		extern RGBAF arrow;
		extern RGBAF integre;
		extern RGBA optionRect;
		extern RGBA scroller;
		extern RGBA line;
		extern RGBA primary;
		extern RGBA secondary;

		extern int keyPressDelay;
		extern int keyPressPreviousTick;
		extern int keyPressDelay2;
		extern int keyPressPreviousTick2;
		extern int keyPressDelay3;
		extern int keyPressPreviousTick3;
		extern int openKey;
		extern int backKey;
		extern int upKey;
		extern int downKey;
		extern int leftKey;
		extern int rightKey;
		extern int selectKey;
		extern int arrowupKey;
		extern int arrowdownKey;
		extern int arrowleftKey;
		extern int arrowrightKey;
		extern int enterKey;
		extern int deleteKey;
		extern int openpress;
		extern int downpress;
		extern int uppress;
		extern int backpress;
		extern int click;
		extern int leftpress;
		extern int rightpress;
		//menu shit
		extern float GlareX;
		extern float GlareY;
		extern float Glarewidth;
		extern float Glareheight;
		extern float menuX;
		extern float menuY;
		extern float menuW;
		extern float menuH;
		extern float menuR;

	}
	namespace MenuLevelHandler {
		void MoveMenu(SubMenus menu);
		void BackMenu();
	}
	namespace Checks {
		void Controlls();
	}
	namespace Tools {
		char* StringToChar(std::string string);
	}
	namespace Files {
		void WriteStringToIni(std::string string, std::string file, std::string app, std::string key);
		std::string ReadStringFromIni(std::string file, std::string app, std::string key);
		void WriteIntToIni(int intValue, std::string file, std::string app, std::string key);
		int ReadIntFromIni(std::string file, std::string app, std::string key);
		void WriteFloatToIni(float floatValue, std::string file, std::string app, std::string key);
		float ReadFloatFromIni(std::string file, std::string app, std::string key);
		void WriteBoolToIni(bool b00l, std::string file, std::string app, std::string key);
		bool ReadBoolFromIni(std::string file, std::string app, std::string key);
	}
	void Title(const char* title);
	void info(const char* title);
	void Speedometer(char* text);
	void fps(char* text);
	void AddSmallTitle(char* text);
	void AddSmallInfo(char* text, short line);
	void AddSmallTitle2(char* text);
	void AddSmallInfo2(char* text, short line);
	void AddSmallTitle3(char* text);
	void AddSmallInfo3(char* text, short line);
	bool Break(const char* option);
	bool Option(const char* option);
	bool SpawnOption(char* option, char* carname);
	bool OptionProp(char* Prop_Name);
	bool MenuOption(const char* option, SubMenus newSub);
	void PlayerOption(int i);
	bool MenuOption(const char* option, SubMenus newSub, std::function<void()> function);
	bool Toggle(const char* option, bool& b00l);
	//bool Toggle(const char* option, bool& b00l, std::function<void()> function);
	bool Int(const char* option, int& _int, int min, int max);
	bool Int(const char* option, int& _int, int min, int max, int step);
	//bool Int(const char* option, int& _int, int min, int max, std::function<void()> function);
	//bool Int(const char* option, int& _int, int min, int max, int step, std::function<void()> function);
	bool Float(const char* option, float& _float, int min, int max);
	bool Float(const char* option, float& _float, int min, int max, int step);
	//bool Float(const char* option, float& _float, int min, int max, std::function<void()> function);
	//bool Float(const char* option, float& _float, int min, int max, int step, std::function<void()> function);
	bool IntVector(const char* option, std::vector<int> Vector, int& position);
//	bool IntVector(const char* option, std::vector<int> Vector, int& position, std::function<void()> function);
	bool FloatVector(const char* option, std::vector<float> Vector, int& position);
	//bool FloatVector(const char* option, std::vector<float> Vector, int& position, std::function<void()> function);
	bool StringVector(const char* option, std::vector<std::string> Vector, int& position);
//	bool StringVector(const char* option, std::vector<std::string> Vector, int& position, std::function<void()> function);
	bool StringVector(const char* option, std::vector<char*> Vector, int& position);
	//bool StringVector(const char* option, std::vector<char*> Vector, int& position, std::function<void()> function);
	bool Teleport(const char* option, Vector3 coords);
	bool Teleport(const char* option, Vector3 coords, std::function<void()> function);
	void End();
}






void Option(char* option);





/*case plist:
			{
				Menu::Title("Player List");
				for (int i = 0; i < 32; ++i) {
					if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
						Menu::MenuOption(PLAYER::GET_PLAYER_NAME(i), pmenu) ? RDR2selectedPlayer = i : NULL; // OG forloop
					}
				}
				Menu::End();
			}
			break;

			case pmenu:
			{
				Menu::Title(PLAYER::GET_PLAYER_NAME(RDR2selectedPlayer));
				Menu::End();
			}
			break;*/