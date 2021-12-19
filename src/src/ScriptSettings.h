#pragma once

typedef std::map<std::string, string> SettingsMap;

class ScriptSettings
{
private:
	static SettingsMap* settings;

public:
	static void load(const char* filename, SettingsMap* defaults);
	static string get(const char* key);
	static int getInt(const char* key);
	static bool getBool(const char* key);
	static float getFloat(const char* key);

private:
	static void handleLine(string* line);
};