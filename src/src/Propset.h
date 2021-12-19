#pragma once

class Propset
{
public:
	int handle;

	Propset(int handle = 0);

	static Propset spawn(Vector3 location, const char* model);

};