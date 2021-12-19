#pragma once

class PlacesFactory
{
private:
	int placesCount;
	map<MapAreas, vector<Place*>> cache;

public:
	PlacesFactory();
	vector<Place*> getByArea(MapAreas area);

private:
	int nextId();
	void fillTumbleweed();
	void fillArmadillo();
	void fillBlackwater();
	void fillStrawberry();
	void fillValentine();
	void fillRhodes();
	void fillStDenis();
	void fillAnnesburg();
};