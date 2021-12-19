#pragma once

class RiderAI : public PedBehavior 
{
public:
	RiderAI(Ped ped, bool persistBlip = false);

	bool canShoot();
	void ride(int speed = 3, int drivingStyle = 786603);
	void warn(Ped suspect);
	void threaten(Ped enemy);
	void threatenEscalated(Ped suspect);
	virtual void fight(Ped enemy);
};