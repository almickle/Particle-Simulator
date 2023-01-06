#include "BondingGroup.h"

void BondingGroup::AssignRelationships()
{

}

void BondingGroup::AddBond(Bond* bond)
{
	bonds.push_back(bond);
}

std::vector<Bond*> BondingGroup::GetBonds()
{
	return bonds;
}