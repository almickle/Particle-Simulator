#include "Particle.h"

void Particle::Compute()
{
	ComputeForces();
	velocity = momentum / mass;
	position = position + velocity * stepTime;

	forces.clear();
	path.push_back(position);
}

void Particle::AddToPath(Vector2f pos)
{
	path.push_back(pos);
}

void Particle::AddMomentum(Vector2f momenta)
{
	momentum += momenta;
}

void Particle::AddForce(Vector2f force)
{
	forces.push_back(force);
}

void Particle::ComputeForces()
{
	netForce = Vector2f(0.0f, 0.0f);
	for each (Vector2f force in forces)
	{
		netForce += force;
	}
	momentum += netForce * stepTime;
}

Vector2f Particle::GetMomentum()
{
	return momentum;
}

void Particle::ReflectMomentum(Vector2f axis)
{
	momentum = momentum - 2 * momentum.dot(axis) * axis;
}

void Particle::SetPosition(Vector2f in_position)
{
	position = in_position;
}

Vector2f Particle::GetPosition()
{
	return position;
}

Vector2f Particle::GetVelocity()
{
	return velocity;
}

Vector2f Particle::GetNetForce()
{
	return netForce;
}

float Particle::GetRadius()
{
	return radius;
}

vector<Vector2f> Particle::GetPath()
{
	return path;
}

Color Particle::GetColor()
{
	return color;
}

void Particle::SetColor(Color in_color)
{
	color = in_color;
}

float Particle::GetKineticEnergy()
{
	return 0.5f * momentum.squaredNorm() / mass;
}