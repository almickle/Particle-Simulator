#pragma once
#include "Particle.h"
#include <vector>

using std::vector;

class ParticleSystem
{
public:
	ParticleSystem(vector<Particle*> in_particles)
	{
		particles = in_particles;
	}
private:
	vector<Particle*> particles;
private:
	float TotalKE;
	float TotalPE;
	float TotalEnergy;
private:
	vector<Vec2> distances;
private:
	void CalculateKineticEnergy();
	void CalculatePotentialEnergy();
	void ComputeTotalEnergy();
private:
	void ResetKE();
	void ResetPE();
private:
	void CalculateDistances();
	void CalculateCoulombicForces();
public:
	void ComputeParticles();
	void DrawParticles(Graphics& gfx);
};

