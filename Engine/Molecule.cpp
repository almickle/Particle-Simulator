#include "Molecule.h"

void Molecule::Draw(Graphics& gfx)
{
	for (int i = 0; i < atoms.size(); i++)
	{
		Particle& atom = *atoms[i];
		atom.DrawParticle(gfx);
	}
}

void Molecule::AssignBondingGroups(std::vector<Bond*> bonds)
{
	for (int i = 0; i < atoms.size(); i++)
	{
		groups.push_back(new BondingGroup());
		BondingGroup& group = *groups[i];
		for (int k = 0; k < bonds.size(); k++)
		{
			Bond& bond = *bonds[k];
			if (atoms[i] == &bond.GetEntityA() || atoms[i] == &bond.GetEntityB())
			{
				group.AddBond(bonds[k]);
			}
		}
	}
	std::vector<BondingGroup*>::iterator i;
	for (i = groups.begin(); i != groups.end(); i++) {
		BondingGroup* group_ptr = *i;
		BondingGroup& group = *group_ptr;
		if (group.GetBonds().size() <= 1)
		{
			delete* i;
			i = groups.erase(i) - 1;
		}
	}
}


// [ a, b, c, d, e, f, g, h ]
// [ [a, c], [a, d], [a, e], [a, b], [b, f], [b, g], [b, h] ]
// 
// [ 
	// [ [a, c], [a, d], [a, e], [a, b] ], 
	// [ [a, b], [b, f], [b, g], [b, h] ] 
// ]




//// iterating over all bonds in molecule
//for (int i = 0; i < bonds.size(); i++)
//{
//	Bond& bond = *bonds[i];
//	if (i == 0)
//	{
//		BondingGroup& firstGroup = *groups[0];
//		firstGroup.AddBond(bonds[0]);
//		continue;
//	}
//	// iterating over already identified groups
//	for (int k = 0; k < groups.size(); k++)
//	{
//		BondingGroup& currentGroup = *groups[k];
//		int p = 0;
//		bool hasGroup = false;
//		// iterating over bonds in a group being constructed
//		for (int b = 0; b < currentGroup.GetBonds().size(); b++)
//		{
//			Bond& currentBond = *currentGroup.GetBonds()[b];
//			// iterating over entities composing a bond
//			for (int e = 0; e < 2; e++)
//			{
//				Particle& entityA = currentBond.GetEntityA();
//				Particle& entityB = currentBond.GetEntityB();
//
//				Particle& entityJ = bond.GetEntityA();
//				Particle& entityK = bond.GetEntityB();
//
//				int size = currentGroup.GetBonds().size();
//				if (&entityJ == &entityA || &entityJ == &entityB || &entityK == &entityA || &entityK == &entityB)
//				{
//					p++;
//					break;
//				}
//			}
//		}
//		if (p == currentGroup.GetBonds().size())
//		{
//			currentGroup.AddBond(bonds[i]);
//			hasGroup = true;
//		}
//		if (hasGroup == false)
//		{
//			groups.push_back(new BondingGroup(bonds[i]));
//		}
//	}
//}