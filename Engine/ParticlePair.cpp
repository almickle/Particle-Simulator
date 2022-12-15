#include "ParticlePair.h"
#include "ParticleSystem.h"


void ParticlePair::Calculate()
{
	float d = PtclaAddr().GetPosition().Subtract(PtclbAddr().GetPosition()).Mag();
	float pe = coulombsK * PtclaAddr().GetCharge() * PtclbAddr().GetCharge() / d;
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