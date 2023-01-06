#include "Particle.h"
#include <corecrt_math.h>



// onframe computation bundle
void Particle::Update(float dt)
{
	SummateForces();
	acceleration = netForce.Scale(1 / mass);
	velocity = velocity.Add(acceleration); // .Scale(dt * 60.0f));
	position = position.Add(velocity); // .Scale(dt * 60.0f));

	CalculateKE();
	ClearForces();
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
void Particle::AddVelocity(float boost)
{
	velocity = velocity.Add(velocity.Unit().Scale(boost));
}

// collision handling
void Particle::RetractPosition(float dx)
{
	position = position.Subtract(velocity.Scale(dx));
}
void Particle::AdjustVelocity(Vec2 vel)
{
	velocity = vel;
}
void Particle::ProjectPosition(float ft, float ct)
{
	float travelTime = ft - ct;
	position = position.Add(velocity.Scale((travelTime * 60.0f)));
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

// setter functions
void Particle::SetPosition(Vec2 location)
{
	position = location;
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
void Particle::Clamp(Container& box)
{
	// x-axis clamping
	if (position.GetX() + radius > box.GetContainerWidth() + box.GetContainerX())
	{
		position = Vec2((float)box.GetContainerWidth() + box.GetContainerX() - radius, position.GetY());
		velocity.InvertX();
	}
	if (position.GetX() - radius < box.GetContainerX())
	{
		position = Vec2(box.GetContainerX() + radius, position.GetY());
		velocity.InvertX();
	}

	// y-axis clamping
	if (position.GetY() + radius > box.GetContainerHeight() + box.GetContainerY())
	{
		position = Vec2(position.GetX(), (float)box.GetContainerHeight() + box.GetContainerY() - radius);
		velocity.InvertY();
	}
	if (position.GetY() - radius < box.GetContainerY())
	{
		position = Vec2(position.GetX(), box.GetContainerY() + radius);
		velocity.InvertY();
	}
}