#pragma once

#include "Graphics.h"
#include <corecrt_math.h>

struct Vec2
{
public:
	Vec2( float in_x, float in_y )
	{
		x = in_x;
		y = in_y;
	}
	Vec2() {
		x = 0.0f;
		y = 0.0f;
	}
private:
	float x;
	float y;
public:
	Vec2 Unit();
	Vec2 Cross( Vec2 vector );
	float Dot( Vec2 vector );
	Vec2 Add(Vec2 vector);
	Vec2 Subtract(Vec2 vector);
	Vec2 Scale(float scalar);
	float Mag();
	float Mag2();
public:
	void DrawVec(Graphics& gfx, Vec2 start);
public:
	void InvertY();
	void InvertX();
public:
	float GetX();
	float GetY();
};

