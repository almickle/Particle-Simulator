#pragma once
#include "Molecule.h"

class Ethane :
    public Molecule
{
public:
    Ethane(Vec2 in_position)
    {
        Vec2 origin = in_position;
        Particle* carbon1 = new Particle(origin, 5.0f, -2.0f, 16.0f);
        Particle* hydrogen1 = new Particle(origin.Subtract(Vec2(9.57f, 0.0f)), 3.0f, 1.0f, 1.0f);
        Particle* hydrogen2 = new Particle(origin.Subtract(Vec2(-9.57f, 0.0f)), 3.0f, 1.0f, 1.0f);
        Particle* hydrogen3 = new Particle(origin.Subtract(Vec2(0.0f, 10.0f)), 2.0f, -1.0f, 0.01f);
        Particle* carbon2 = new Particle(origin, 5.0f, -2.0f, 16.0f);
        Particle* hydrogen4 = new Particle(origin.Subtract(Vec2(0.0f, -10.0f)), 2.0f, -1.0f, 0.01f);
        Particle* hydrogen5 = new Particle(origin.Subtract(Vec2(0.0f, -10.0f)), 2.0f, -1.0f, 0.01f);
        Particle* hydrogen6 = new Particle(origin.Subtract(Vec2(0.0f, -10.0f)), 2.0f, -1.0f, 0.01f);

        atoms = { carbon1, hydrogen1, hydrogen2, hydrogen3, carbon2, hydrogen4, hydrogen5, hydrogen6 };
        bonds = {
            new Bond(carbon1, carbon2, 0),
            new Bond(carbon1, hydrogen1, 0),
            new Bond(carbon1, hydrogen2, 0),
            new Bond(carbon1, hydrogen3, 0),
            new Bond(carbon2, hydrogen4, 0),
            new Bond(carbon2, hydrogen5, 0),
            new Bond(carbon2, hydrogen6, 0)
        };

        AssignBondingGroups(bonds);
    }
};

