#pragma once

class PedBehavior 
{
private:
	Ped _pedHandle;
	bool _isActive;
	bool _persistBlip;

public:
	PedBehavior(Ped ped, bool persistBlip = false);
	
	Ped ped();
	virtual bool isActive();
	virtual void start();
	virtual void update();
	virtual void stop();
	virtual bool isAlive();
	virtual bool isThreatenedByPlayer(int seeingRange = 40, int hearingRange = 40);
	virtual void setPersistBlip(bool persistBlip);
	virtual bool getPersistBlip();
	virtual void addEnemyBlip();
	virtual void removeBlip();
	virtual void fight(Ped enemy);
	virtual void flee(Ped from);
};