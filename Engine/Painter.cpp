#include "Painter.h"
#include "Colors.h"

using namespace std;

void Painter::DrawLocalVector(Vector2f position, Vector2f vector, Color color, float scale)
{
	Graphics& graphics = *gfx;
	float step_x = vector.normalized().x();
	float step_y = vector.normalized().y();
	float mag = vector.norm();
	for (int i = 0; i < mag * scale; i++)
	{
		Vector2f currentPosition = Vector2f(position.x() + step_x + i * step_x, position.y() + step_y + i * step_y);
		Vector2f vectorTip = position + vector;

		if ((vector - currentPosition).norm() * scale < 1)
		{
			break;
		}
		graphics.PutPixel(position.x() + step_x + i * step_x, position.y() + step_y + i * step_y, color);
	}
	DrawCircle(3.0f, position + vector, Color(255, 255, 255));
}

void Painter::DrawPath(vector<Vector2f> path)
{
	Graphics& graphics = *gfx;
	for each (Vector2f point in path)
	{
		graphics.PutPixel(point.x(), point.y(), Color(255, 255, 255));
	}
}

void Painter::DrawLine(Vector2f pointA, Vector2f pointB)
{
	Graphics& graphics = *gfx;
	Vector2f vector = pointA - pointB;
	Vector2f position = pointB;
	float step_x = vector.normalized().x();
	float step_y = vector.normalized().y();
	float mag = vector.norm();
	for (int i = 0; i < mag; i++)
	{
		Vector2f currentPosition = Vector2f(position.x() + step_x + i * step_x, position.y() + step_y + i * step_y);
		if ((vector - currentPosition).norm() < 1)
		{
			break;
		}
		graphics.PutPixel(position.x() + step_x + i * step_x, position.y() + step_y + i * step_y, Color(255, 255, 255));
	}

}

void Painter::DrawTriangle()
{

}

void Painter::DrawRectangle(Vector2f position, float height, float width, Color color)
{
	Graphics& graphics = *gfx;
	for (int i=0; i < width; i++)
	{
		for (int k = 0; k < height; k++)
		{
			graphics.PutPixel(i + position.x(), k + position.y(), color);
		}
	}
}

void Painter::DrawCircle(float radius, Vector2f position, Color color)
{
	float r2 = radius * radius;
	for (int x = (int)-radius; x <= (int)radius; x++)
	{
		for (int y = (int)-radius; y <= (int)radius; y++)
		{
			float d2 = (float)x * (float)x + (float)y * (float)y;
			if (d2 < r2) {
				Graphics& graphics = *gfx;
				graphics.PutPixel((int)(position.x() + (float)x), (int)(position.y() + (float)y), color);
			}
		}
	}
}

void Painter::DrawParticle(Particle& ptcl)
{
	float radius = ptcl.GetRadius();
	Vector2f position = ptcl.GetPosition();
	Color color = ptcl.GetColor();
	float r2 = radius * radius;
	for (int x = (int)-radius; x <= (int)radius; x++)
	{
		for (int y = (int)-radius; y <= (int)radius; y++)
		{
			float d2 = (float)x * (float)x + (float)y * (float)y;
			if (d2 < r2) {
				Graphics& graphics = *gfx;
				graphics.PutPixel((int)(position.x() + (float)x), (int)(position.y() + (float)y), color);
			}
		}
	}
}