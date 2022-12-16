/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <chrono>


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	particles({
		new Particle(true, 1.0f), new Particle(true, 1.0f), new Particle(true, 1.0f), new Particle(true, 1.0f),
		new Particle(false, 1.0f), new Particle(false, 1.0f), new Particle(false, 1.0f), new Particle(false, 1.0f),
		new Particle(true, 1.0f), new Particle(true, 1.0f), new Particle(true, 1.0f), new Particle(true, 1.0f),
		new Particle(false, 1.0f), new Particle(false, 1.0f), new Particle(false, 1.0f), new Particle(false, 1.0f),
		new Particle(false, 1.0f), new Particle(false, 1.0f), new Particle(false, 1.0f), new Particle(false, 1.0f),
		new Particle(true, 1.0f), new Particle(true, 1.0f), new Particle(true, 1.0f), new Particle(true, 1.0f),
		new Particle(false, 1.0f), new Particle(false, 1.0f), new Particle(false, 1.0f), new Particle(false, 1.0f),
		new Particle(true, 1.0f), new Particle(true, 1.0f), new Particle(true, 1.0f), new Particle(true, 1.0f),
		new Particle(false, 1.0f), new Particle(false, 1.0f), new Particle(false, 1.0f), new Particle(false, 1.0f),
		new Particle(false, 1.0f), new Particle(false, 1.0f), new Particle(false, 1.0f), new Particle(false, 1.0f),
		//new Particle(Vec2(300.0f, 300.0f), Vec2(0.0f, 0.0f), Color(0, 255, 255)),
		//new Particle(Vec2(500.0f, 300.0f), Vec2(-5.0f, 0.0f), Color(255, 255, 0))
	}),	
	gui(&particles)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = frameTimer.Mark();
	particles.ParticleSystemComputation();
	particles.UpdateParticles(dt);
	particles.AdjustForCollision(dt);
}

void Game::ComposeFrame()
{
	particles.DrawParticles(gfx);
	gui.DrawHUD(gfx);
}


