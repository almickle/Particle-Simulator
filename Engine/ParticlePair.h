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
private:
	bool colliding = false;
public:
	void Calculate();
public:
	float GetPotentialEnergy();
	float GetCoulombic();
public:
	void ResolveCollision();
public:
	Particle& PtclaAddr();
	Particle& PtclbAddr();
public:
	bool GetColliding();
	float GetDistance();
};

