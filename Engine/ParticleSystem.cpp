#include "ParticleSystem.h"

// on initialization
void ParticleSystem::AssignParticlePairs()
{
	for (int i = 0; i < particles.size(); i++)
	{
		for (int k = i; k < particles.size(); k++)
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

void ParticleSystem::AddCovalentForces()
{
	for (int i = 0; i < particlepairs.size(); i++)
	{
		ParticlePair& pair = *particlepairs[i];
		Particle& ptcla = pair.PtclaAddr();
		Particle& ptclb = pair.PtclbAddr();
		float fmag = pair.GetCovalentForce();
		Vec2 dira = ptclb.GetPosition().Subtract(ptcla.GetPosition()).Unit();
		Vec2 dirb = ptcla.GetPosition().Subtract(ptclb.GetPosition()).Unit();

		ptcla.AddForce(dira.Scale(fmag));
		ptclb.AddForce(dirb.Scale(fmag));
	}
}


// interparticle calculations
void ParticleSystem::ParticleSystemComputation()
{
	ComputeParticlePairs();
	DetermineCoulombicForces();
	AddCovalentForces();
	ComputeTotalEnergy();
	CalculateTemperature();
}


// compute and draw
void ParticleSystem::UpdateParticles(float dt)
{
	for (int i = 0; i < particles.size(); i++)
	{
		Particle& ptcl = *particles[i];
		ptcl.Update(dt);
	}
}
void ParticleSystem::AdjustForCollision(float ft, Container& box)
{
	for (int i = 0; i < particlepairs.size(); i++)
	{
		ParticlePair& pair = *particlepairs[i];
		if (pair.GetColliding())
		{
			pair.RetractPositions();
			pair.AdjustVelocities();
		//	//pair.ProjectPositions();

			pair.ResolveCollision();
		}
		Particle& ptcla = pair.PtclaAddr();
		Particle& ptclb = pair.PtclbAddr();
		ptcla.Clamp(box);
		ptclb.Clamp(box);

		//ReturnEnergy();
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

// temperature
void ParticleSystem::CalculateTemperature()
{
	float ke = TotalKE;
	float pc = ParticleCount();
	float bz = boltzman;
	temperature = (TotalKE / ParticleCount()) / boltzman;
}
float ParticleSystem::GetTemperature()
{
	return temperature;
}
void ParticleSystem::ChangeTemperature(bool up, float value)
{

}
void ParticleSystem::ReturnEnergy()
{
	float velperptcl = lostVelocity / particleCount;
	for (int i = 0; i < particleCount; i++)
	{
		Particle& ptcl = *particles[i];
		ptcl.AddVelocity(velperptcl);
	}
	lostVelocity = 0.0f;
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


// getter functions
float ParticleSystem::GetKineticEnergy()
{
	return TotalKE;
}
float ParticleSystem::GetPotentialEnergy()
{
	return TotalPE;
}
float ParticleSystem::GetTotalEnergy()
{
	return TotalEnergy;
}
int ParticleSystem::ParticleCount()
{
	return (int)particles.size();
}