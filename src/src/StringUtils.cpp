#pragma once

#include "Main.h"

vector<string> split(const string& s, char delim) {
	vector<string> result;
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}

Vector3 parseVector3(string vector3String)
{
	vector<string> xyz = split(vector3String, ',');
	return toVector3(stoi(xyz[0]), stoi(xyz[1]), stoi(xyz[2]));
}

const char* to_string(Vector3 pos)
{
	stringstream str;
	str << pos.x << "," << pos.y << "," << pos.z;
	return str.str().c_str();
}

bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}