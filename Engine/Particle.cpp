#include "Particle.h"
#include <corecrt_math.h>



// onframe computation bundle
void Particle::Update(float dt)
{
	SummateForces();
	acceleration = netForce.Scale(1 / mass);
	velocity = velocity.Add(acceleration.Scale(dt * 60.0f));
	position = position.Add(velocity.Scale(dt * 60.0f));

	CalculateKE();
	ClearForces();

	Clamp();
}


// internal onframe functions
void Particle::SummateForces()
{
	netForce = Vec2(0.0f, 0.0f);
	for (int i = 0; i < forces.size(); i++)
	{
		netForce = netForce.Add(forces[i]);
	}
}
void Particle::ClearForces()
{
	forces.clear();
}
void Particle::CalculateKE()
{
	kineticEnergy = 0.5f * mass * velocity.Mag2();
}
void Particle::DrawParticle(Graphics& gfx)
{
	float r2 = radius * radius;
	for (int x = (int)-radius; x <= (int)radius; x++)
	{
		for (int y = (int)-radius; y <= (int)radius; y++)
		{
			float d2 = (float)x * (float)x + (float)y * (float)y;
			if (d2 < r2) {
				gfx.PutPixel((int)(position.GetX() + (float)x), (int)(position.GetY() + (float)y), color);
			}
		}
	}
}


// interface functions
void Particle::AddForce(Vec2 in_force)
{
	forces.push_back(in_force);
}
void Particle::AdjustPosition(float amount)
{
	position = position.Subtract(velocity.Unit().Scale(amount));
}
void Particle::AdjustVelocity(Vec2 cpv, float cpm)
{
	velocity = cpv.Scale(cpm / mass);
}


// getter functions
Vec2 Particle::GetPosition()
{
	return position;
}
float Particle::GetRadius()
{
	return radius;
}
float Particle::GetCharge()
{
	return charge;
}
float Particle::GetKE()
{
	return kineticEnergy;
}
Vec2 Particle::GetVelocity()
{
	return velocity;
}
float Particle::GetMass()
{
	return mass;
}

// border handling
void Particle::Wrap()
{
	// x-axis wrapping
	if (position.GetX() + radius > Graphics::ScreenWidth)
	{
		position = Vec2(radius, position.GetY());
	}
	if (position.GetX() - radius < 0)
	{
		position = Vec2((float)Graphics::ScreenWidth - radius, position.GetY());
	}

	// y-axis wrapping
	if (position.GetY() + radius > Graphics::ScreenHeight)
	{
		position = Vec2(position.GetX(), radius);
	}
	if (position.GetY() - radius < 0)
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





//Vec2 Particle::CalculateCoulombic(Particle& ptcl)
//{
//	Vec2 dist = position.Subtract(ptcl.position);
//	float fscalar = ke * charge * ptcl.charge / dist.Mag2();
//
//	return dist.Unit().Scale(fscalar);
//}

// setter functions
//void Particle::SetVelocity(Vec2 in_velocity)
//{
//	velocity = in_velocity;
//}