#include "Main.h"

bool SetModel(char* Model, char* option)
{
	Option(option);
	if (Menu::Settings::currentOption == Menu::Settings::optionCount)
	{
		if (Menu::Settings::selectPressed)
		{
			if (STREAMING::IS_MODEL_IN_CDIMAGE(key(Model)))
			{
				if (STREAMING::IS_MODEL_VALID(key(Model)))
				{
					STREAMING::REQUEST_MODEL(key(Model), true);
					if (STREAMING::HAS_MODEL_LOADED(key(Model)))
					{
						PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), key(Model), true);
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(key(Model));
						return true;
					}
					else return false;
				}
			}
			return true;
		}
	}
	return false;
}

void models()
{

	SetModel("A_C_ALLIGATOR_01", "alligator");
	SetModel("A_C_ALLIGATOR_02", "alligator 2");
	SetModel("A_C_ALLIGATOR_03", "alligator 3");
	SetModel("A_C_ARMADILLO_01", "armadillo");

}