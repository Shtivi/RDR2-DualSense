#include "Main.h"

BaseDataFile::BaseDataFile(const char* filename)
{
	this->filename = filename;
	this->hasChanges = false;
}

const char* BaseDataFile::getFilename()
{
	return filename;
}


bool BaseDataFile::load()
{
	ifstream file;
	string input;
	int count = 0;

	log(string("loading data file: ").append(filename));
	file.open(filename);;
	if (!file.is_open())
	{
		log("unable to load from data file, please make sure it exists.");
		return false;
	}

	log(string("data file found: ").append(filename));
	while (!file.eof())
	{
		std::getline(file, input);
		if (!handleLineInput(&input))
		{
			log(string("data file '").append(filename).append("' is corruped at line: ").append(to_string(count)));
			return false;
		}

		count++;
	}

	file.close();
	log(string("data file '").append(filename).append("' loaded, lines red: ").append(to_string(count)));
	return true;
}

bool BaseDataFile::save(bool force)
{
	if (!hasChanges && !force)
	{
		return true;
	}

	log(string("saving ").append(filename).c_str());
	if (!writeData())
	{
		log(string("save failed in file: ").append(filename).c_str());
		return false;
	}

	hasChanges = false;
	log(string("file saved: ").append(filename));
	return true;
}

bool BaseDataFile::isTouched()
{
	return hasChanges;
}