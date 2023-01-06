#pragma once
#include "Graphics.h"

class Atom
{
private:
	int protons;
	int neutrons;
	int electrons;
public:
	void Draw(Graphics& gfx);
};

