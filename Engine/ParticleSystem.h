#pragma once
#include "Particle.h"
#include "ParticlePair.h"
#include "Container.h"
#include <vector>


class ParticleSystem
{
public:
	ParticleSystem(std::vector<Particle*> in_particles)
	{
		particles = in_particles;
		particleCount = ParticleCount();
		CalculateTemperature();
		AssignParticlePairs();
	}
public:
	void Populate(float v, float space, bool flag, Container& box)
	{
		particles.push_back(new Particle(v, space, true, true, box));
		particles.push_back(new Particle(v, space, false, false, box));
		particleCount = ParticleCount();
		CalculateTemperature();
		AssignParticlePairs();
	}
private:
	std::vector<Particle*> particles;
	std::vector<ParticlePair*> particlepairs;
private:
	float TotalKE;
	float TotalPE;
	float TotalEnergy;
	float temperature;
	int particleCount;
private:
	float lostVelocity = 0.0f;
private:
	const float boltzman = 0.001381f;
private:
	void AssignParticlePairs();
	void ComputeParticlePairs();
private:
	void ComputeKineticEnergies();
	void ComputePotentialEnergies();
	void ComputeTotalEnergy();
private:
	void CalculateTemperature();
private:
	void ReturnEnergy();
private:
	void ResetKE();
	void ResetPE();
private:
	void DetermineCoulombicForces();
	void AddCovalentForces();
public:
	void ParticleSystemComputation();
	void UpdateParticles(float dt);
	void AdjustForCollision(float ft, Container& box);
	void DrawParticles(Graphics& gfx);
public:
	void ChangeTemperature(bool up, float value);
public:
	float GetKineticEnergy();
	float GetPotentialEnergy();
	float GetTotalEnergy();
	int ParticleCount();
	float GetTemperature();
};

