#pragma once
#include "Graphics.h"
#include "Vec2.h"

class Container
{
public:
	Container(int in_height, int in_width, int in_posx, int in_posy)
	{
		height = in_height;
		width = in_width;
		posx = in_posx;
		posy = in_posy;
	}
private:
	int height = Graphics::ScreenHeight;
	int width = Graphics::ScreenWidth;
	int posx = 0;
	int posy = 0;
public:
	void DrawContainer(Graphics& gfx);
public:
	int GetContainerHeight();
	int GetContainerWidth();
	int GetContainerX();
	int GetContainerY();
};

