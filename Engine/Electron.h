#pragma once
#include "Particle.h"
#include "ParticlePair.h"
#include "Vec2.h"

class Electron
{
public:
	Electron(Vec2 in_position, int amount)
	{
		position = in_position;
		PopulateElectronPoints(in_position, amount);
		AssignElasticPairs();
		AssignElectrostaticPairs();
	}
private:
	std::vector<Particle*> electronPoints;
	std::vector<ParticlePair*> elasticPairs;
	std::vector<ParticlePair*> electrostaticPairs;
private:
	float orbit = 30.0f;
	float charge = -1.0f;
	float mass = 1.0f;
	Vec2 position;
private:
	float Map(float out_start, float out_end, float in_start, float in_end, float input);
private:
	void PopulateElectronPoints(Vec2 in_position, int amount);
	void AssignElasticPairs();
	void AssignElectrostaticPairs();
private:
	void ComputeElectroStaticForces();
	void ComputeElasticForces();
public:
	void Compute();
	void AdjustCollision(Container& box);
	void Update();
	void Draw(Graphics& gfx);
	std::vector<Particle*> GetPoints();
};

