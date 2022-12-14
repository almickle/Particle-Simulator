#include "ParticleSystem.h"


void ParticleSystem::CalculateForces()
{
	for (int i = 0; i < particles.size(); i++)
	{
		Particle& ptcla = *particles[i];
		ptcla.ClearForces();
		for (int k = 0; k < particles.size(); k++)
		{
			if (k != i)
			{
				Particle& ptclb = *particles[k];
				ptcla.AddForce(ptcla.CalculateCoulombic(ptclb));
			}
		}
	}
}

void ParticleSystem::DrawParticles(Graphics& gfx)
{
	for (int i = 0; i < particles.size(); i++)
	{
		Particle& ptcl = *particles[i];
		ptcl.DrawParticle(gfx);
	}
}

void ParticleSystem::ComputeParticles()
{
	for (int i = 0; i < particles.size(); i++)
	{
		Particle& ptcl = *particles[i];
		ptcl.Compute();
	}
}