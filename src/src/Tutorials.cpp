#include "Main.h"

void Tutorials::trigger(const char* tutorialName)
{
	if (!DataFiles::TutorialFlags->getBool(tutorialName) || rndInt(0, 5) > 3)
	{
		showHelpText(DataFiles::Lang->get(string("tutorial.").append(tutorialName).c_str()), 8000);
		log(string("tutorial seen: ").append(tutorialName));
		DataFiles::TutorialFlags->set(tutorialName, 1);
		DataFiles::TutorialFlags->save();
	}
}
