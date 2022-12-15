#include "Vec2.h"


// vector math functions
Vec2 Vec2::Unit()
{
	return Vec2( x / Mag(), y / Mag());
}
Vec2 Vec2::Cross( Vec2 vector)
{
	// cross product calculation

	return Vec2(0.0f, 0.0f);
}
float Vec2::Dot(Vec2 vector)
{
	// dot product calculation

	return 0.0f;
}
Vec2 Vec2::Subtract(Vec2 vector)
{
	return Vec2(x - vector.GetX(), y - vector.GetY());
}
Vec2 Vec2::Add(Vec2 vector)
{
	return Vec2(x + vector.GetX(), y + vector.GetY());
}
Vec2 Vec2::Scale(float scalar)
{
	return Vec2(x * scalar, y * scalar);
}
float Vec2::Mag()
{
	return sqrtf(x * x + y * y);
}
float Vec2::Mag2()
{
	return x * x + y * y;
}


// interface functions
void Vec2::InvertX()
{
	x = -x;
}
void Vec2::InvertY()
{
	y = -y;
}


// Draw function
void Vec2::DrawVec(Graphics& gfx, Vec2 start)
{
	float unitx = Unit().GetX();
	float unity = Unit().GetY();
	float startx = start.GetX();
	float starty = start.GetY();
	for (int i = 0; i < (int)x; i++)
	{
		for (int x = 0; x <= (int)unitx; x++)
		{
			int pixelx = i * (int)unitx + x + (int)startx;
			int pixely = i * (int)unity + (int)starty;
			if (pixelx < gfx.ScreenWidth && pixely < gfx.ScreenHeight && pixelx > 0 && pixely > 0) {
				gfx.PutPixel(pixelx, pixely, 255, 255, 255);
			}
		}
		for (int y = 0; y <= (int)unity; y++)
		{
			int pixelx = i *(int) unitx + (int)startx;
			int pixely = i * (int)unity + y + (int)starty;
			if (pixelx < gfx.ScreenWidth && pixely < gfx.ScreenHeight && pixelx > 0 && pixely > 0) {
				gfx.PutPixel(pixelx, pixely, 255, 255, 255);
			}
		}
	}
}


// coordinate getter functions
float Vec2::GetX()
{
	return x;
}
float Vec2::GetY()
{
	return y;
}