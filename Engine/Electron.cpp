#include "Electron.h"

void Electron::PopulateElectronPoints(Vec2 in_position, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		float angle = Map(0.0f, 2.0f*3.141592f, 0.0f, amount, i);
		Vec2 location = Vec2(cosf(angle), sinf(angle)).Scale(orbit).Add(in_position);
		electronPoints.push_back(new Particle(location, 1.0f, charge/amount, mass/amount));
	}
}
void Electron::AssignElasticPairs()
{
	for (int i = 0; i < electronPoints.size(); i++)
	{
		if (i == electronPoints.size()-1)
		{
			elasticPairs.push_back(new ParticlePair(electronPoints[i], electronPoints[0]));
		}
		else {
			elasticPairs.push_back(new ParticlePair(electronPoints[i], electronPoints[i + 1]));
		}
	}
}
void Electron::AssignElectrostaticPairs()
{
	for (int i = 0; i < electronPoints.size(); i++)
	{
		for (int k = i; k < electronPoints.size(); k++)
		{
			if (i != k)
			{
				electrostaticPairs.push_back(new ParticlePair(electronPoints[i], electronPoints[k]));
			}
		}
	}
}

float Electron::Map(float out_start, float out_end, float in_start, float in_end, float input)
{
	return out_start + ((out_end - out_start) / (in_end - in_start)) * (input - in_start);
}

void Electron::ComputeElectroStaticForces()
{
	for (ParticlePair* espair : electrostaticPairs)
	{
		ParticlePair& pair = *espair;
		pair.Calculate();

		Particle& ptcla = pair.PtclaAddr();
		Particle& ptclb = pair.PtclbAddr();
		Vec2 dira = ptcla.GetPosition().Subtract(ptclb.GetPosition()).Unit();
		Vec2 dirb = ptclb.GetPosition().Subtract(ptcla.GetPosition()).Unit();

		ptcla.AddForce(dira.Scale(pair.GetCoulombic()));
		ptclb.AddForce(dirb.Scale(pair.GetCoulombic()));
	}
}
void Electron::ComputeElasticForces()
{
	for (ParticlePair* elpair : elasticPairs)
	{
		ParticlePair& pair = *elpair;
		pair.ComputeElasticForce();

		Particle& ptcla = pair.PtclaAddr();
		Particle& ptclb = pair.PtclbAddr();
		Vec2 dira = ptclb.GetPosition().Subtract(ptcla.GetPosition()).Unit();
		Vec2 dirb = ptcla.GetPosition().Subtract(ptclb.GetPosition()).Unit();

		ptcla.AddForce(dira.Scale(pair.GetElasticForce()));
		ptclb.AddForce(dirb.Scale(pair.GetElasticForce()));
	}
}

void Electron::AdjustCollision(Container& box)
{
	for (int i = 0; i < electronPoints.size(); i++)
	{
		Particle& point = *electronPoints[i];
		point.Clamp(box);
	}
}

void Electron::Compute() 
{
	ComputeElasticForces();
	ComputeElectroStaticForces();
}
void Electron::Update()
{
	for (Particle* point : electronPoints)
	{
		Particle& ptcl = *point;
		ptcl.Update(1.0f);
	}
}
void Electron::Draw(Graphics& gfx)
{
	for (int i = 0; i < electronPoints.size(); i++)
	{
		Particle& point = *electronPoints[i];
		point.DrawParticle(gfx);
	}
}

std::vector<Particle*> Electron::GetPoints()
{
	return electronPoints;
}