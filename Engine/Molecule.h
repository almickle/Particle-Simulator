#pragma once
#include "Particle.h"
#include "Bond.h"
#include "BondingGroup.h"

class Molecule
{
public:
	Molecule()
	{
		atoms = {};
		bonds = {};
	}
protected:
	std::vector<Particle*> atoms;
	std::vector<Bond*> bonds;
	std::vector<BondingGroup*> groups;
protected:
	void AssignBondingGroups(std::vector<Bond*> bonds);
public:
	void Draw(Graphics& gfx);
};

