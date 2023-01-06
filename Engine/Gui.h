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
	void DrawBar(Graphics& gfx, int locx, int locy, int width, float value, float max, Color color);
	void DrawFreeBar(Graphics& gfx, int locx, int locy, int width, float value, Color color);
	int Map(float out_start, float out_end, float in_start, float in_end, float input);
public:
	void DrawHUD(Graphics& gfx);
};

