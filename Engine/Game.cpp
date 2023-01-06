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


Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	box(300, 300, 200, 200),
	electron(Vec2(350.0f, 350.0f), 30),
	user()
	//ethane(Vec2(350.0f, 350.0f))
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
	electron.Compute();
	user.CalculateInteractions(electron);
	electron.AdjustCollision(box);
	electron.Update();
	user.DeterminePosition(wnd);
	//particles.ParticleSystemComputation();
	//particles.UpdateParticles(dt);
	//particles.AdjustForCollision(dt, box);
}

void Game::ComposeFrame()
{
	box.DrawContainer(gfx);
	electron.Draw(gfx);
	user.Draw(gfx);
	//water.Draw(gfx);
	//particles.DrawParticles(gfx);
	//gui.DrawHUD(gfx);
}


