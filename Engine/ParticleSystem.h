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
public:
	void CalculateForces();
	void ComputeParticles();
	void DrawParticles(Graphics& gfx);
};

