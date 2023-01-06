#pragma once
#include "Particle.h"

class Bond
{
public:
	Bond(Particle* atom1, Particle* atom2, int in_type) {
		atoms[0] = atom1;
		atoms[1] = atom2;
		type = in_type;
		type < 1 ? length = 12.0f : type > 1 ? length = 3.0f : length = 6.0f;
	}
private:
	Particle* atoms[2];
private:
	int type;
private:
	float force = 0.0f;
	float length = 0.0f;
	float distanceSq = 0.0f;
	bool intact = true;
private:
	float CalculateDistanceSq();
	void MaintainBondLength();
public:
	void Compute();
public:
	Particle& GetEntityA();
	Particle& GetEntityB();
};

