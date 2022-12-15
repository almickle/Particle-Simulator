#pragma once
#include "Particle.h"
#include "ParticlePair.h"
#include <vector>

using std::vector;

class ParticleSystem
{
public:
	ParticleSystem(vector<Particle*> in_particles)
	{
		particles = in_particles;
		AssignParticlePairs();
	}
private:
	vector<Particle*> particles;
	vector<ParticlePair*> particlepairs;
private:
	float TotalKE;
	float TotalPE;
	float TotalEnergy;
private:
	void AssignParticlePairs();
	void ComputeParticlePairs();
private:
	void ComputeKineticEnergies();
	void ComputePotentialEnergies();
	void ComputeTotalEnergy();
private:
	void ResetKE();
	void ResetPE();
private:
	void DetermineCoulombicForces();
public:
	void ParticleSystemComputation();
	void ComputeParticles();
	void DrawParticles(Graphics& gfx);
};

