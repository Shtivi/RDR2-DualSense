#include "Main.h";
#include <iostream>
#include <fstream>
#include <string>

const char* const LOG_FILE = "BountiesExpansion/Log.log";

ofstream file;

void initializeLogger()
{
	//file.open(LOG_FILE, std::ios_base::out);
	//file.close();
}

void log(const char* msg)
{
	time_t nowTimestamp = std::time(0);
	tm* now = localtime(&nowTimestamp);
	stringstream txt;

	file.open(LOG_FILE, std::ios_base::app);
	if (file.is_open())
	{
		txt << "[" << now->tm_mday << "/" << now->tm_mon << "/" << now->tm_year + 1900 << " "
			<< now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << "] " << msg;
		file << txt.str().c_str() << "\n";
		file.close();
	}
}

void log(Vector3 pos)
{
	std::stringstream output;
	output << pos.x << ", " << pos.y << ", " << pos.z;
	log(output.str().c_str());
}

void log(std::string msg)
{
	log(msg.c_str());
}