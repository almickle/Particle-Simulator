#include "Bond.h"

void Bond::Compute()
{
	Particle& atom1 = *atoms[0];
	Particle& atom2 = *atoms[1];
	Vec2 dira = atom2.GetPosition().Subtract(atom1.GetPosition()).Unit();
	Vec2 dirb = atom1.GetPosition().Subtract(atom2.GetPosition()).Unit();

	atom1.AddForce(dira.Scale(force));
	atom2.AddForce(dirb.Scale(force));
}

void Bond::MaintainBondLength()
{
	if (distanceSq < length) {

	}
}

float Bond::CalculateDistanceSq()
{
	Particle& atom1 = *atoms[0];
	Particle& atom2 = *atoms[1];

	distanceSq = atom1.GetPosition().Subtract(atom1.GetPosition()).Mag2();
	return distanceSq;
}

Particle& Bond::GetEntityA()
{
	return *atoms[0];
}

Particle& Bond::GetEntityB()
{
	return *atoms[1];
}