#pragma once
#include "Particle.h"
#include "Mouse.h"
#include "MainWindow.h"
#include "Electron.h"

class UserCharge
{
private:
	Particle point = Particle(Vec2(350.0f, 350.0f), 3.0f, 2.0f, 1.0f);
public:
	void DeterminePosition(MainWindow& wnd);
	void CalculateInteractions(Electron& electron);
	void Draw(Graphics& gfx);
};

