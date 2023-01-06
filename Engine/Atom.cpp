#include "Atom.h"
#include "Vec2.h"
#include "Colors.h"

void Atom::Draw(Graphics& gfx)
{
	int radius = 5;
	float r2 = radius * radius;
	Vec2 position = Vec2(350.0f, 350.0f);
	Color color = Color(255, 0, 255);
	for(int x = (int)-radius; x <= (int)radius; x++)
	{
		for (int y = (int)-radius; y <= (int)radius; y++)
		{
			float d2 = (float)x * (float)x + (float)y * (float)y;
			if (d2 < r2) {
				gfx.PutPixel((int)(position.GetX() + (float)x), (int)(position.GetY() + (float)y), color);
			}
		}
	}
}