#pragma once

class NamesGenerator
{
private:
	static map<Hash, const char*> decodeMap;

public:
	static void init();
	static pair<Hash, Hash> generateName(int ethnicity, int gender);
	static const char* retrieve(Hash nameIndex);
	static const char* retrieve(Hash firstname, Hash surname);

private:
	static void cacheList(vector<const char*> list);
};