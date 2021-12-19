#pragma once

class DevTools
{
private:
	static bool active;
	
public:
	static bool isActive();
	static void toggle();
	static void enable();
	static void disable();
	static void update();
};