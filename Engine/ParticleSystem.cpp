#include "ParticleSystem.h"

// on initialization
void ParticleSystem::AssignParticlePairs()
{
	for (int i = 0; i < particles.size(); i++)
	{
		for (int k = 0; k < particles.size(); k++)
		{
			if (i != k)
			{
				particlepairs.push_back(new ParticlePair(particles[i], particles[k]));
			}
		}
	}
}


void ParticleSystem::ComputeParticlePairs()
{
	for (int i = 0; i < particlepairs.size(); i++)
	{
		ParticlePair& pair = *particlepairs[i];
		pair.Calculate();
	}
}
void ParticleSystem::DetermineCoulombicForces()
{
	for (int i = 0; i < particlepairs.size(); i++)
	{
		ParticlePair& pair = *particlepairs[i];
		Particle& ptcla = pair.PtclaAddr();
		Particle& ptclb = pair.PtclbAddr();
		float fmag = pair.GetCoulombic();
		Vec2 dira = ptcla.GetPosition().Subtract(ptclb.GetPosition()).Unit();
		Vec2 dirb = ptclb.GetPosition().Subtract(ptcla.GetPosition()).Unit();

		ptcla.AddForce(dira.Scale(fmag));
		ptclb.AddForce(dirb.Scale(fmag));
	}
}

// interparticle calculations
void ParticleSystem::ParticleSystemComputation()
{
	ComputeParticlePairs();
	DetermineCoulombicForces();
	ComputeTotalEnergy();
}

// compute and draw
void ParticleSystem::ComputeParticles(float dt)
{
	for (int i = 0; i < particles.size(); i++)
	{
		Particle& ptcl = *particles[i];
		ptcl.Compute(dt);
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


// energy calculations
void ParticleSystem::ComputeKineticEnergies()
{
	for (int i = 0; i < particles.size(); i++)
	{
		Particle& ptcl = *particles[i];
		TotalKE += ptcl.GetKE();
	}
}
void ParticleSystem::ComputePotentialEnergies()
{
	for (int i = 0; i < particlepairs.size(); i++)
	{
		ParticlePair& pair = *particlepairs[i];
		TotalPE += pair.GetPotentialEnergy();
	}
}
void ParticleSystem::ComputeTotalEnergy()
{
	ResetKE();
	ResetPE();
	ComputeKineticEnergies();
	ComputePotentialEnergies();
	TotalEnergy = TotalPE + TotalKE;
}


// resetting energy each frame
void ParticleSystem::ResetKE()
{
	TotalKE = 0.0f;
}
void ParticleSystem::ResetPE()
{
	TotalPE = 0.0f;
}

