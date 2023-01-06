#include "ParticlePair.h"
#include "ParticleSystem.h"


void ParticlePair::Calculate()
{
	Particle& ptcla = PtclaAddr();
	Particle& ptclb = PtclbAddr();

	float d = ptcla.GetPosition().Subtract(ptclb.GetPosition()).Mag();
	float df = d;
	if (d < (ptcla.GetRadius() + ptclb.GetRadius()))
	{
		df = ptcla.GetRadius() + ptclb.GetRadius();
		colliding = true;
	}
	else {
		colliding = false;
	}

	float pe = coulombsK * ptcla.GetCharge() * ptclb.GetCharge() / df;
	float f = pe / df;

	distance = d;
	potentialEnergy = pe;
	coulombic = f;
}
void ParticlePair::ComputeElasticForce()
{
	Particle& ptcla = PtclaAddr();
	Particle& ptclb = PtclbAddr();

	float d = ptcla.GetPosition().Subtract(ptclb.GetPosition()).Mag();
	float df = d;
	if (d < (ptcla.GetRadius() + ptclb.GetRadius()))
	{
		df = ptcla.GetRadius() + ptclb.GetRadius();
		colliding = true;
	}
	else {
		colliding = false;
	}

	elastic = elasticK * df;
	distance = d;
}

Vec2 ParticlePair::RetractPositions()
{
	Particle& ptcla = PtclaAddr();
	Particle& ptclb = PtclbAddr();

	float r2 = ptcla.GetRadius() + ptcla.GetRadius();
	float d = r2 - distance;
	float av = ptcla.GetVelocity().Mag();
	float bv = ptclb.GetVelocity().Mag();
	float tv = av + bv;
	float avfr = av / tv;
	float bvfr = bv / tv;
	float dxa = d * avfr;
	float dxb = d * bvfr;

	ptcla.RetractPosition(av);
	ptclb.RetractPosition(bv);

	/*ptcla.RetractPosition(dxa);
	ptclb.RetractPosition(dxb);*/

	return Vec2(dxa, dxb);
}
void ParticlePair::AdjustVelocities()
{
	Particle& ptcla = PtclaAddr();
	Particle& ptclb = PtclbAddr();
	float pam = ptcla.GetMass();
	float pbm = ptclb.GetMass();
	Vec2 pav = ptcla.GetVelocity();
	Vec2 pbv = ptclb.GetVelocity();

	Vec2 vela = pbv.Scale(pbm).Add(pav.Scale(pam)).Subtract(pav.Scale(pbm)).Scale(2.0f).Scale(1.0f / (pam + pbm));
	Vec2 velb = pav.Scale(pam).Add(pbv.Scale(pbm)).Subtract(pbv.Scale(pam)).Scale(2.0f).Scale(1.0f / (pam + pbm));

	ptcla.AdjustVelocity(vela);
	ptclb.AdjustVelocity(velb);
}
void ParticlePair::ProjectPositions()
{
	Particle& ptcla = PtclaAddr();
	Particle& ptclb = PtclbAddr();
}
void ParticlePair::ResolveCollision()
{
	colliding = false;
}


float ParticlePair::GetCoulombic()
{
	return coulombic;
}
float ParticlePair::GetPotentialEnergy()
{
	return potentialEnergy;
}
float ParticlePair::GetCovalentForce()
{
	return covalentForce;
}
float ParticlePair::GetElasticForce()
{
	return elastic;
}

Particle& ParticlePair::PtclaAddr()
{
	return *ptcls[0];
}
Particle& ParticlePair::PtclbAddr()
{
	return *ptcls[1];
}

bool ParticlePair::GetColliding()
{
	return colliding;
}
float ParticlePair::GetDistance()
{
	return distance;
}