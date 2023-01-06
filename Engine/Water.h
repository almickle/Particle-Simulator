#pragma once
#include "Molecule.h"

class Water :
    public Molecule
{
public:
    Water(Vec2 in_position)
    {
        Vec2 origin = in_position;
        Particle* oxygen = new Particle(origin, 5.0f, -2.0f, 16.0f);
        Particle* hydrogen1 = new Particle(origin.Subtract(Vec2(9.57f, 0.0f)), 3.0f, 1.0f, 1.0f);
        Particle* hydrogen2 = new Particle(origin.Subtract(Vec2(-9.57f, 0.0f)), 3.0f, 1.0f, 1.0f);
        Particle* lonepair1 = new Particle(origin.Subtract(Vec2(0.0f, 10.0f)), 2.0f, -1.0f, 0.01f);
        Particle* lonepair2 = new Particle(origin.Subtract(Vec2(0.0f, -10.0f)), 2.0f, -1.0f, 0.01f);

        atoms = { oxygen, hydrogen1, hydrogen2, lonepair1, lonepair2};
        bonds = { 
            new Bond(oxygen, hydrogen1, 0), 
            new Bond(oxygen, hydrogen2, 0), 
            new Bond(oxygen, lonepair1, 0), 
            new Bond(oxygen, lonepair2, 0) 
        };

        AssignBondingGroups(bonds);
    }
};

