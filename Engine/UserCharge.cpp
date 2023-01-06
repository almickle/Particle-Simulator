#include "UserCharge.h"

void UserCharge::Draw(Graphics& gfx)
{
	point.DrawParticle(gfx);
}

void UserCharge::DeterminePosition(MainWindow& wnd)
{
	Vec2 mousePos = Vec2(wnd.mouse.GetPosX(), wnd.mouse.GetPosY());
	if (wnd.mouse.LeftIsPressed())
	{
		point.SetPosition(mousePos);
	}
}

void UserCharge::CalculateInteractions(Electron& electron)
{
	for (int i = 0; i < electron.GetPoints().size(); i++)
	{
		Particle& elpoint = *electron.GetPoints()[i];
		ParticlePair pair = ParticlePair(&elpoint, &point);
		float coulombic = pair.GetCoulombic();
		Vec2 dira = elpoint.GetPosition().Subtract(point.GetPosition()).Unit();
		elpoint.AddForce(dira.Scale(coulombic));
	}
}

// (mousePos.GetX() > 0 && mousePos.GetX() < 500 && mousePos.GetY() > 0 && mousePos.GetY() < 500