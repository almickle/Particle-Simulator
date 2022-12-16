#pragma once
#include "Vec2.h"
#include "Colors.h"
#include "Graphics.h"
#include "Container.h"
#include <vector>
#include <random>

class Particle
{
public:
	Particle(float in_radius, float in_mass, float in_charge, Vec2 in_position) {
		radius = in_radius;
		mass = in_mass;
		charge = in_charge;
		charge > 0.0f ? color = Color(255, 0, 0) : color = Color(0, 0, 255);
		position = in_position;
		CalculateKE();
	}
	Particle(float in_radius, float in_mass, float in_charge, Vec2 in_position, Vec2 in_velocity) {
		radius = in_radius;
		mass = in_mass;
		charge = in_charge;
		charge > 0.0f ? color = Color(255, 0, 0) : color = Color(0, 0, 255);
		position = in_position;
		velocity = in_velocity;
		CalculateKE();
	}
	Particle(bool sign, float mag)
	{
		radius = mag + 4.0f;
		mass = 1.0f;
		sign ? charge = mag : charge = -mag;
		charge < 0.0f ? color = Color(255, 0, 0) : color = Color(0, 0, 255);
		position = Vec2((float)(rand() % 800), (float)(rand() % 600));
		CalculateKE();
	}
	Particle()
	{
		radius = 5.0f;
		mass = 1.0f;
		charge = 0.0f;
		color = Color(255, 255, 0);
		position = Vec2((float)(rand() % 800), (float)(rand() % 600));
		velocity = Vec2((float)(rand() % 3), (float)(rand() % 3));
		CalculateKE();
	}
	Particle(Vec2 in_position, Vec2 in_velocity, Color in_color) {
		radius = 5.0f;
		mass = 1.0f;
		charge = 1.0f;
		color = in_color;
		position = in_position;
		velocity = in_velocity;
		CalculateKE();
	}
	Particle(bool sign, float mag, Container& box)
	{
		radius = mag + 4.0f;
		mass = 1.0f;
		sign ? charge = mag : charge = -mag;
		charge < 0.0f ? color = Color(255, 0, 0) : color = Color(0, 0, 255);
		position = Vec2((float)box.GetContainerX() + (float)(rand() % box.GetContainerWidth()), (float)box.GetContainerY() + (float)(rand() % box.GetContainerHeight()));
		CalculateKE();
	}
private:
	float radius;
	float mass;
	float charge;
private:
	Vec2 position;
	Vec2 velocity = Vec2(0.0f, 0.0f);
	Vec2 acceleration = Vec2(0.0f, 0.0f);
	Vec2 netForce = Vec2(0.0f, 0.0f);
	std::vector<Vec2> forces;
	float kineticEnergy;
private:
	Color color;
public:
	void DrawParticle(Graphics& gfx);
	void Update(float dt);
public:
	void Wrap();
	void Clamp(Container& box);
private:
	void ClearForces();
	void CalculateKE();
	void SummateForces();
public:
	void AddForce(Vec2 in_force);
	void RetractPosition(Vec2 dx);
	void AdjustVelocity(Vec2 cpv, float cpm);
	void ProjectPosition(float dt, float ct);
public:
	Vec2 GetPosition();
	float GetRadius();
	float GetCharge();
	float GetKE();
	Vec2 GetVelocity();
	float GetMass();
};

