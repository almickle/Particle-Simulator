#include "Gui.h"


void Gui::DrawHUD(Graphics& gfx)
{
	ParticleSystem& system = *sys;
	float ke = system.GetKineticEnergy();
	float pe = system.GetPotentialEnergy();
	float te = system.GetTotalEnergy();
	float temp = system.GetTemperature();
	int locx = 50;
	int width = 20;

	DrawBar(gfx, locx, 30, width, ke, te, Color(0, 255, 255));
	DrawBar(gfx, locx, 60, width, pe, te, Color(255, 0, 255));
	DrawBar(gfx, locx, 90, width, te, te, Color(255, 255, 0));
	//DrawFreeBar(gfx, locx, 120, width, temp, Color(0, 255, 30));
}

void Gui::DrawBar(Graphics& gfx, int locx, int locy, int width, float value, float max, Color color)
{
	float adj_val = Map(0, 500, 0, abs(max), value);
	if (abs(value) > max)
	{
		adj_val = 500;
	}
	if (value >= 0.0f)
	{
		for (int x = locx; x < adj_val + locx; x++)
		{
			for (int y = locy; y < locy + width; y++)
			{
				gfx.PutPixel(x, y, color);
			}
		}
	}
	else {
		for (int x = locx; x < abs(adj_val) + locx; x++)
		{
			for (int y = locy; y < locy + width; y++)
			{
				gfx.PutPixel(x, y, Color(255, 50, 50));
			}
		}
	}
}

void Gui::DrawFreeBar(Graphics& gfx, int locx, int locy, int width, float value, Color color)
{
	for (int x = locx; x < value + locx; x++)
	{
		for (int y = locy; y < locy + width; y++)
		{
			gfx.PutPixel(x, y, color);
		}
	}
}


int Gui::Map(float out_start, float out_end, float in_start, float in_end, float input)
{
	return out_start + ((out_end - out_start) / (in_end - in_start)) * (input - in_start);
}