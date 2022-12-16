#include "Container.h"

void Container::DrawContainer(Graphics& gfx)
{
	for (int x = posx; x <= posx + width; x++)
	{
		gfx.PutPixel(x, posy, 255, 255, 255);
	}
	for (int x = posx; x <= posx + width; x++)
	{
		gfx.PutPixel(x, posy + height, 255, 255, 255);
	}
	for (int y = posy; y <= posy + height; y++)
	{
		gfx.PutPixel(posx, y, 255, 255, 255);
	}
	for (int y = posy; y <= posy + height; y++)
	{
		gfx.PutPixel(posx + width, y, 255, 255, 255);
	}
}

int Container::GetContainerHeight()
{
	return height;
}
int Container::GetContainerWidth()
{
	return width;
}
int Container::GetContainerX()
{
	return posx;
}
int Container::GetContainerY()
{
	return posy;
}