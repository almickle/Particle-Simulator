#pragma once
#include "Particle.h"

class ParticlePair
{
public:
	ParticlePair(Particle* ptcla, Particle* ptclb)
	{
		ptcls[0] = ptcla;
		ptcls[1] = ptclb;
		Calculate();
	}
private:
	Particle* ptcls[2];
private:
	const float coulombsK = 8.98755f;
private:
	float distance;
	float distSq;
	float coulombic;
	float potentialEnergy;
public:
	void Calculate();
public:
	float GetPotentialEnergy();
	float GetCoulombic();
public:
	Particle& PtclaAddr();
	Particle& PtclbAddr();
};

