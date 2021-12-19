#include "Main.h"

const char* DataFiles::DataFilesPath = "";


const char* DataFiles::getDataFilePath(const char* filename)
{
	return (new string(string(DataFilesPath).append("/").append(filename).c_str()))->c_str();
}

bool DataFiles::load()
{
	return true;
}