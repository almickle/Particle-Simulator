#pragma once
#include "Graphics.h"
#include "Particle.h"
#include "Bond.h"
#include <vector>

using namespace std;

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
	Container(Graphics& gfx, int margin) {
		height = gfx.cr.bottom - (margin * 2);
		width = gfx.cr.right - (margin * 2);
		posx = margin;
		posy = margin;
	}
private:
	int height = 100;
	int width = 100;
	int posx = 0;
	int posy = 0;
private:
	vector<Particle> ptcls;
public:
	void DrawContainer(Graphics& gfx);
	void CollisionClamp(Particle& ptcl);
	void CollisionWrap(Particle& ptcl);
	void CollisionClamp(Bond& bond);
public:
	int GetContainerHeight();
	int GetContainerWidth();
	int GetContainerX();
	int GetContainerY();
};

