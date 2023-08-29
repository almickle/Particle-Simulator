#pragma once
#include "Bond.h"

class Atom
{
public:
	Atom()
	{
		Vector2f position = Vector2f(400.0f, 300.0f);
		Color blue = Color(0, 0, 255);
		Color red = Color(255, 0, 0);

		nucleus = Particle(position, blue, 4.0f);
		nucleus.AddMomentum(Vector2f(200.0f, -100.0f));
		float radius = 40.0f;
		electrons = { 
			Particle(position + Vector2f(radius, 0.0f), red, 1.0f), 
			Particle(position + Vector2f(-radius, 0.0f), red, 1.0f),
			Particle(position + Vector2f(0.0f, radius), red, 1.0f),
			Particle(position + Vector2f(0.0f, -radius), red, 1.0f)
		};
		particles.push_back(&nucleus);
		for (int i = 0; i < electrons.size(); i++)
		{
			particles.push_back(&electrons[i]);
			bonds.push_back(Bond(&nucleus, &electrons[i]));
		}
	}
private:
	Particle nucleus;
	vector<Particle> electrons;
	vector<Bond> bonds = {};
	vector<Particle*> particles = {};
private:
	Vector2f position;
	Vector2f momentum;
public:
	void Compute();
	void Draw(Painter& painter);
};

