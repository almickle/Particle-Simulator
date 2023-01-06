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
	const float coulombsK = 1.44f;
	const float elasticK = 0.0005f;
private:
	float distance;
	float distSq;
	float coulombic;
	float elastic;
	float potentialEnergy;
	float covalentForce = 0.0f;
private:
	bool colliding = false;
public:
	void Calculate();
	void ComputeElasticForce();
public:
	float GetPotentialEnergy();
	float GetCoulombic();
	float GetCovalentForce();
	float GetElasticForce();
public:
	void ResolveCollision();
	Vec2 RetractPositions();
	void AdjustVelocities();
	void ProjectPositions();
public:
	Particle& PtclaAddr();
	Particle& PtclbAddr();
public:
	bool GetColliding();
	float GetDistance();
};

