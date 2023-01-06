#pragma once
#include "Particle.h"
#include "Bond.h"

class BondingGroup
{
public:
	BondingGroup()
	{
		bonds = {};
	}
	BondingGroup(Bond* bond)
	{
		bonds = { bond };
	}
private:
	Particle* centralAtom;
	std::vector<Particle*> entities;
	std::vector<Bond*> bonds;
public:
	void AddBond(Bond* bond);
	void AssignRelationships();
public:
	std::vector<Bond*> GetBonds();
};

