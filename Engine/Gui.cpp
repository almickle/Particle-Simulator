#include "Gui.h"

void Gui::RenderValueBar(Vector2f position, float height, float value, Color color)
{
	Painter& painter= *painter_ptr;
	painter.DrawRectangle(position, height, value, color);
}

void Gui::RenderHUD()
{
	Bond& bond = *bond_ptr;
	float kinetic = bond.GetKineticEnergy();
	float potential = bond.GetPotentialEnergy();
	float energy = bond.GetTotalEnergy();
	float initialEnergy = bond.GetInitialEnergy();

	float scale = 200.0f;
	RenderValueBar(Vector2f(820.0f, 480.0f), 20.0f, kinetic / energy * scale, Color(0, 60, 200));
	RenderValueBar(Vector2f(820.0f, 510.0f), 20.0f, potential / energy * scale, Color(0, 200, 60));
	RenderValueBar(Vector2f(820.0f, 540.0f), 20.0f, sqrt(abs(energy - initialEnergy)) / initialEnergy * scale, Color(255, 20, 200));
}