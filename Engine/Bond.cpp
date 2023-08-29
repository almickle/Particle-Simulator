#include "Bond.h"

void Bond::Compute()
{
	HarmonicOscillator();
}

void Bond::HarmonicOscillator()
{
	Particle& ptcla = *ptcla_ptr;
	Particle& ptclb = *ptclb_ptr;

	displacement = ptcla.GetPosition() - ptclb.GetPosition();
	midPoint = (ptcla.GetPosition() + ptclb.GetPosition()) / 2;
	distanceA = midPoint - ptcla.GetPosition();
	distanceB = midPoint - ptclb.GetPosition();

	Vector2f equillibriumA = equillibriumLength * distanceA.normalized();
	Vector2f equillibriumB = equillibriumLength * distanceB.normalized();

	deltaA = distanceA - equillibriumA;
	deltaB = distanceB - equillibriumB;

	ptcla.AddForce(springConstant * deltaA);
	ptclb.AddForce(springConstant * deltaB);
}

void Bond::ComputeInitialData()
{
	Particle& ptcla = *ptcla_ptr;
	Particle& ptclb = *ptclb_ptr;

	displacement = ptcla.GetPosition() - ptclb.GetPosition();
	midPoint = (ptcla.GetPosition() + ptclb.GetPosition()) / 2;	

	distanceA = midPoint - ptcla.GetPosition();
	distanceB = midPoint - ptclb.GetPosition();

	Vector2f equillibriumA = equillibriumLength * distanceA.normalized();
	Vector2f equillibriumB = equillibriumLength * distanceB.normalized();

	deltaA = distanceA - equillibriumA;
	deltaB = distanceB - equillibriumB;

	initialEnergy = GetTotalEnergy();
}

void Bond::DrawBond(Painter& painter)
{
	Particle& ptcla = *ptcla_ptr;
	Particle& ptclb = *ptclb_ptr;
	painter.DrawLine(ptclb.GetPosition(), ptcla.GetPosition());
	//painter.DrawCircle(20.0f, ptclb.GetPosition(), Color(255, 255, 255));
	//painter.DrawLine(ptcla.GetPosition(), ptclb.GetPosition());
}

vector<Particle*> Bond::GetParticles()
{
	return particles;
}

Particle& Bond::GetParticleA()
{
	Particle& ptcla = *ptcla_ptr;
	return ptcla;
}

Particle& Bond::GetParticleB()
{
	Particle& ptclb = *ptclb_ptr;
	return ptclb;
}

float Bond::GetMomentum()
{
	Particle& ptcla = *ptcla_ptr;
	Particle& ptclb = *ptclb_ptr;
	return ptcla.GetMomentum().norm() + ptclb.GetMomentum().norm();
}

float Bond::GetTotalEnergy()
{
	return GetKineticEnergy() + GetPotentialEnergy();
}

float Bond::GetKineticEnergy()
{
	Particle& ptcla = *ptcla_ptr;
	Particle& ptclb = *ptclb_ptr;
	return ptcla.GetKineticEnergy() + ptclb.GetKineticEnergy();
}

float Bond::GetPotentialEnergy()
{
	return 0.5f * springConstant * deltaA.squaredNorm() + 0.5f * springConstant * deltaB.squaredNorm();
}

float Bond::GetInitialEnergy()
{
	return initialEnergy;
}