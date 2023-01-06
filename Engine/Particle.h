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
	Particle(Vec2 in_position, float in_radius, float in_charge, float in_mass)
	{
		position = in_position;
		radius = in_radius;
		charge = in_charge;
		mass = in_mass;
		charge < 0.0f ? color = Color(255, 0, 0) : color = Color(0, 0, 255);
	}
	Particle(float v, float space, bool flag, bool sign, Container& box) {
		radius = 5.0f;
		mass = 1.0f;
		sign ? charge = 1.0f : charge = -1.0f;
		charge < 0.0f ? color = Color(255, 0, 0) : color = Color(0, 0, 255);
		float adj;
		float speed;
		flag ? adj = space : adj = -space;
		flag ? speed = v : speed = -v;
		position = Vec2((float)box.GetContainerX() + ((float)(box.GetContainerWidth() - adj) / 2.0f), (float)box.GetContainerY() + ((float)box.GetContainerHeight() / 2.0f));
		velocity = Vec2(speed, 0.0f);
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
	float kineticEnergy = 0.0f;
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
	void AddVelocity(float boost);
	void RetractPosition(float dx);
	void AdjustVelocity(Vec2 vel);
	void ProjectPosition(float dt, float ct);
public:
	Vec2 GetPosition();
	float GetRadius();
	float GetCharge();
	float GetKE();
	Vec2 GetVelocity();
	float GetMass();
public:
	void SetPosition(Vec2 location);
};

