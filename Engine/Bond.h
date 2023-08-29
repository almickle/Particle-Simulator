#pragma once
#define _USE_MATH_DEFINES
#include "Particle.h"
#include "Painter.h"
#include <math.h>
#include <array>
#include <Eigen/Geometry>



class Bond
{
public:
	Bond()
	{
		ptcla_ptr = &Particle();
		ptclb_ptr = &Particle();

		particles[0] = ptcla_ptr;
		particles[1] = ptclb_ptr;

		Particle& ptcla = *ptcla_ptr;
		Particle& ptclb = *ptclb_ptr;
		ptcla.AddMomentum(Vector2f(-120.0f, 100.0f));
		ptclb.AddMomentum(Vector2f(-100.0f, 120.0f));

		ComputeInitialData();
	}
	Bond(Particle* in_ptcla, Particle* in_ptclb)
	{
		ptcla_ptr = in_ptcla;
		ptclb_ptr = in_ptclb;

		particles.push_back(in_ptcla);
		particles.push_back(in_ptclb);

		ComputeInitialData();
	}
public:
	void DrawBond(Painter& painter);
	void Compute();
private:
	Particle* ptcla_ptr;
	Particle* ptclb_ptr;
	vector<Particle*> particles = {};
private:
	float equillibriumLength = 20.0f;
	float springConstant = 10000.0f;
private:
	Vector2f midPoint;
	Vector2f displacement;
	Vector2f distanceA;
	Vector2f distanceB;
	Vector2f deltaA;
	Vector2f deltaB;
private:
	float initialEnergy;
private:
	void HarmonicOscillator();
	void ComputeInitialData();
public:
	vector<Particle*> GetParticles();
	Particle& GetParticleA();
	Particle& GetParticleB();
	float GetMomentum();
	float GetKineticEnergy();
	float GetPotentialEnergy();
	float GetTotalEnergy();
	float GetInitialEnergy();
};

