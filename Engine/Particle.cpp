#include "Particle.h"
#include <corecrt_math.h>


void Particle::DrawParticle(Graphics& gfx)
{
	float r2 = radius * radius;
	for (int x = (int)-radius; x <= (int)radius; x++)
	{
		for (int y = (int)-radius; y <= (int)radius; y++)
		{
			float d2 = (float)x*(float)x + (float)y*(float)y;
			if (d2 < r2) {
				gfx.PutPixel((int)(position.GetX() + (float)x), (int)(position.GetY() + (float)y), color);
			}
		}
	}
}

void Particle::Compute()
{
	position = position.Add(velocity);
	velocity = velocity.Add(acceleration);
	SummateForces();
	acceleration = acceleration.Add(netForce.Scale(1 / mass));

	Clamp();
}

void Particle::SetVelocity(Vec2 in_velocity)
{
	velocity = in_velocity;
}

void Particle::SummateForces()
{
	for (int i = 0; i < forces.size(); i++)
	{
		netForce = netForce.Add(forces[i]);
	}
}

void Particle::AddForce(Vec2 in_force)
{
	forces.push_back(in_force);
}

void Particle::Wrap()
{
	// x-axis wrapping
	if (position.GetX()+radius > Graphics::ScreenWidth)
	{
		position = Vec2(radius, position.GetY());
	}
	if (position.GetX()-radius < 0)
	{
		position = Vec2((float)Graphics::ScreenWidth - radius, position.GetY());
	}

	// y-axis wrapping
	if (position.GetY()+radius > Graphics::ScreenHeight)
	{
		position = Vec2(position.GetX(), radius);
	}
	if (position.GetY()-radius < 0)
	{
		position = Vec2(position.GetX(), (float)Graphics::ScreenHeight - radius);
	}
}

void Particle::Clamp()
{
	// x-axis clamping
	if (position.GetX() + radius > Graphics::ScreenWidth)
	{
		position = Vec2((float)Graphics::ScreenWidth - radius, position.GetY());
		velocity.InvertX();
	}
	if (position.GetX() - radius < 0)
	{
		position = Vec2(radius, position.GetY());
		velocity.InvertX();
	}

	// y-axis clamping
	if (position.GetY() + radius > Graphics::ScreenHeight)
	{
		position = Vec2(position.GetX(), (float)Graphics::ScreenHeight - radius);
		velocity.InvertY();
	}
	if (position.GetY() - radius < 0)
	{
		position = Vec2(position.GetX(), radius);
		velocity.InvertY();
	}
}


Vec2 Particle::CalculateCoulombic(Particle& ptcl)
{
	Vec2 posa = position;
	Vec2 posb = ptcl.position;
	Vec2 dist = position.Subtract(ptcl.position);
	float d2 = dist.Mag2();
	if (dist.Mag2() < 40000.0f) {
		float fscalar = ke * charge * ptcl.charge / dist.Mag2();
		Vec2 F = dist.Unit().Scale(fscalar);

		return dist.Unit().Scale(fscalar);
	}

	return Vec2(0.0f, 0.0f);
}

void Particle::ClearForces()
{
	forces.clear();
}


Vec2 Particle::GetPosition()
{
	return position;
}

float Particle::GetRadius()
{
	return radius;
}