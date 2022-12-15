#include "Gui.h"


void Gui::DrawHUD(Graphics& gfx)
{
	ParticleSystem& system = *sys;
	float ke = system.GetKineticEnergy();
	float pe = system.GetPotentialEnergy();
	float te = system.GetTotalEnergy();
	int pc = system.ParticleCount();
	int locx = 50;
	int width = 20;
	int scale = 10000 / (pc * pc);

	DrawBar(gfx, locx, 30, width, ke, scale, Color(0, 255, 255));
	DrawBar(gfx, locx, 60, width, pe, scale, Color(255, 0, 255));
	DrawBar(gfx, locx, 90, width, te, scale, Color(255, 255, 0));
}

void Gui::DrawBar(Graphics& gfx, int locx, int locy, int width, float value, int scale, Color color)
{
	if (value > 0.0f)
	{
		for (int x = locx; x < value * scale + locx; x++)
		{
			for (int y = locy; y < locy + width; y++)
			{
				gfx.PutPixel(x, y, color);
			}
		}
	}
	else {
		for (int x = locx; x < abs(value) * scale + locx; x++)
		{
			for (int y = locy; y < locy + width; y++)
			{
				gfx.PutPixel(x, y, Color(255, 50, 50));
			}
		}
	}
}