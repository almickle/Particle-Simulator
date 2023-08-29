#pragma once
#include "Colors.h"
#include <Eigen/Dense>
#include <vector>

using namespace Eigen;
using namespace std;

class Particle
{
public:
	Particle()
	{

	}
	Particle(Vector2f in_position, Color in_color, float in_mass)
	{
		position = in_position;
		color = in_color;
		mass = in_mass;
		radius = sqrt(in_mass) * 4;
	}

public:
	//void DrawParticle(Painter& painter);
	void Compute();
private:
	float stepTime = 0.01f;
private:
	Color color = Color(255, 255, 0);
private:
	float mass = 1.0f;
	float charge = -1.0f;
	float radius = 5.0f;
private:
	Vector2f position = Vector2f(0.0f, 0.0f);
	Vector2f velocity = Vector2f(0.0f, 0.0f);
	Vector2f acceleration = Vector2f(0.0f, 0.0f);
	Vector2f momentum = Vector2f(0.0f, 0.0f);
private:
	vector<Vector2f> forces = { Vector2f(0.0f, 0.0f) };
	Vector2f netForce = Vector2f(0.0f, 0.0f);
	void ComputeForces();
public:
	vector<Vector2f> path;
	void AddToPath(Vector2f pos);
public:
	void AddMomentum(Vector2f momenta);
	void AddForce(Vector2f force);
public:
	Vector2f GetPosition();
	Vector2f GetVelocity();
	Vector2f GetMomentum();
	Vector2f GetNetForce();
	Color GetColor();
	float GetRadius();
	void SetPosition(Vector2f position);
	void ReflectMomentum(Vector2f axis);
	void SetColor(Color color);
	float GetKineticEnergy();
	vector<Vector2f> GetPath();
};