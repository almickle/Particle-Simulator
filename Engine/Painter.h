#pragma once
#include "Graphics.h"
#include "Particle.h"
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

class Painter
{
public:
	Painter(Graphics* gfx_ptr)
	{
		gfx = gfx_ptr;
	}
private:
	Graphics* gfx;
public:
	void DrawCircle(float radius, Vector2f position, Color color);
	void DrawTriangle();
	void DrawRectangle(Vector2f position, float height, float width, Color color);
	void DrawParticle(Particle& ptcl);
	void DrawLocalVector(Vector2f position, Vector2f vector, Color color, float scale);
	void DrawLine(Vector2f pointA, Vector2f pointB);
	void DrawPath(vector<Vector2f> path);
};