#pragma once

#include "ParticleSystem.h" 

class Gui
{
public:
	Gui(ParticleSystem* sys_ref)
	{
		sys = sys_ref;
	}
private:
	ParticleSystem* sys;
private:
	void DrawBar(Graphics& gfx, int locx, int locy, int width, float value, int scale, Color color);
public:
	void DrawHUD(Graphics& gfx);
};

