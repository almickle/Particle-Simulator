#include "ParticlePair.h"
#include "ParticleSystem.h"


void ParticlePair::Calculate()
{
	Particle& ptcla = PtclaAddr();
	Particle& ptclb = PtclbAddr();

	float d = ptcla.GetPosition().Subtract(ptclb.GetPosition()).Mag();
	if (d < (ptcla.GetRadius() + ptclb.GetRadius()))
	{
		d = ptcla.GetRadius() + ptclb.GetRadius();
		colliding = true;
	}
	else {
		colliding = false;
	}

	float pe = coulombsK * ptcla.GetCharge() * ptclb.GetCharge() / d;
	float f = pe / d;

	distance = d;
	potentialEnergy = pe;
	coulombic = f;
}

float ParticlePair::GetCoulombic()
{
	return coulombic;
}
float ParticlePair::GetPotentialEnergy()
{
	return potentialEnergy;
}

Particle& ParticlePair::PtclaAddr()
{
	return *ptcls[0];
}
Particle& ParticlePair::PtclbAddr()
{
	return *ptcls[1];
}

bool ParticlePair::GetColliding()
{
	return colliding;
}
float ParticlePair::GetDistance()
{
	return distance;
}