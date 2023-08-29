#include "Atom.h"

void Atom::Compute()
{
	for (int i = 0; i < bonds.size(); i++)
	{
		bonds[i].Compute();
	}
	for (int i = 0; i < particles.size(); i++)
	{
		Particle& ptcl = *particles[i];
		ptcl.Compute();
	}
}

void Atom::Draw(Painter& painter)
{
	painter.DrawPath(nucleus.GetPath());
	for (int i = 0; i < bonds.size(); i++)
	{
		bonds[i].DrawBond(painter);
	}
	for (int i = 0; i < particles.size(); i++)
	{
		Particle& ptcl = *particles[i];
		painter.DrawParticle(ptcl);
	}
}