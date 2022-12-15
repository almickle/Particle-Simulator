#include "ParticleSystem.h"


// interparticle calculations
void ParticleSystem::CalculateCoulombicForces() // needs work
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
void ParticleSystem::CalculateDistances() {

}


// compute and draw
void ParticleSystem::ComputeParticles()
{
	for (int i = 0; i < particles.size(); i++)
	{
		Particle& ptcl = *particles[i];
		ptcl.Compute();
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
void ParticleSystem::CalculateKineticEnergy()
{
	for (int i = 0; i < particles.size(); i++)
	{
		Particle& ptcl = *particles[i];
		TotalKE += ptcl.GetKE();
	}
}
void ParticleSystem::CalculatePotentialEnergy() // is hard coded: fix
{
	Particle& ptcla = *particles[0];
	Particle& ptclb = *particles[1];
	float dist = ptcla.GetPosition().Subtract(ptclb.GetPosition()).Mag();
	TotalPE = 8987.0f / dist;
}
void ParticleSystem::ComputeTotalEnergy()
{
	CalculateKineticEnergy();
	CalculatePotentialEnergy();
	TotalEnergy = TotalPE + TotalKE;
	ResetKE();
	ResetPE();
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