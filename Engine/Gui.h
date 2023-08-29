#pragma once
#include "Painter.h"
#include "Bond.h"

class Gui
{
public:
	Gui(Painter* ptr, Bond* in_bond)
	{
		painter_ptr = ptr;
		bond_ptr = in_bond;
	}
private:
	Painter* painter_ptr;
	Bond* bond_ptr;
private:
	void RenderValueBar(Vector2f position, float height, float value, Color color);
public:
	void RenderHUD();
};

