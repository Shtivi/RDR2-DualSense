#pragma once

using namespace std;

class DictDataFile : public BaseDataFile
{
private:
	map<string, string> cache;
	map<string, vector<const char*>*> lists;

public:
	DictDataFile(const char* filename);

	const char* get(const char* key);
	int getInt(const char* key);
	float getFloat(const char* key);
	bool getBool(const char* key);
	Vector3 getVector3(const char* key);
	vector<const char*>* getList(const char* key);
	void set(const char* key, string value);
	void set(const char* key, const char* value);
	void set(const char* key, int value);
	void set(const char* key, bool value);
	void set(const char* key, float value);
	void set(const char* key, Vector3 coords);
	void set(const char* key, vector<const char*>* list);

protected:
	bool handleLineInput(string* line);
	bool writeData();
};