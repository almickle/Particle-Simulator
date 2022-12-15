#pragma once
#include "Vec2.h"
#include "Colors.h"
#include "Graphics.h"
#include <vector>

class Particle
{
public:
	Particle(float in_radius, float in_mass, float in_charge, Vec2 in_position) {
		radius = in_radius;
		mass = in_mass;
		charge = in_charge;
		charge > 0.0f ? color = Color(255, 0, 0) : color = Color(0, 0, 255);
		position = in_position;
	}
	Particle(float in_radius, float in_mass, float in_charge, Vec2 in_position, Vec2 in_velocity) {
		radius = in_radius;
		mass = in_mass;
		charge = in_charge;
		charge > 0.0f ? color = Color(255, 0, 0) : color = Color(0, 0, 255);
		position = in_position;
		velocity = in_velocity;
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
	void AddForce(Vec2 in_force);
	void Compute(float dt);
private:
	void Wrap();
	void Clamp();
private:
	void ClearForces();
	void CalculateKE();
	void SummateForces();
public:
	Vec2 GetPosition();
	float GetRadius();
	float GetCharge();
	float GetKE();
};

