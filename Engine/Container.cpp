#include "Container.h"

void Container::DrawContainer(Graphics& gfx)
{
	for (int x = posx; x <= posx + width; x++)
	{
		gfx.PutPixel(x, posy, 255, 255, 255);
	}
	for (int x = posx; x <= posx + width; x++)
	{
		gfx.PutPixel(x, posy + height, 255, 255, 255);
	}
	for (int y = posy; y <= posy + height; y++)
	{
		gfx.PutPixel(posx, y, 255, 255, 255);
	}
	for (int y = posy; y <= posy + height; y++)
	{
		gfx.PutPixel(posx + width, y, 255, 255, 255);
	}
}

//void Container::CollisionClamp(Particle& ptcl)
//{
//	//// x-axis clamping
//	//if (ptcl.GetPosition().x() + ptcl.GetRadius() > width + posx)
//	//{
//	//	/*ptcl.GetPosition() = Vector2f((float)width + posx - ptcl.GetRadius(), ptcl.GetPosition().y());*/
//	//	velocity.InvertX();
//	//}
//	//if (ptcl.GetPosition().x() - ptcl.GetRadius() < posx)
//	//{
//	//	//ptcl.GetPosition()() = Vector2f(posx + ptcl.GetRadius(), ptcl.GetPosition().y());
//	//	velocity.InvertX();
//	//}
//
//	//// y-axis clamping
//	//if (ptcl.GetPosition().y() + ptcl.GetRadius() > height + posy)
//	//{
//	//	//ptcl.GetPosition()() = Vector2f(ptcl.GetPosition().x(), (float)height + posy - ptcl.GetRadius());
//	//	velocity.InvertY();
//	//}
//	//if (ptcl.GetPosition().y() - ptcl.GetRadius() < posy)
//	//{
//	//	//ptcl.GetPosition()() = Vector2f(ptcl.GetPosition().x(), posy + ptcl.GetRadius());
//	//	velocity.InvertY();
//	//}
//}

void Container::CollisionClamp(Bond& bond)
{
	for each (Particle* ptcl_ptr in bond.GetParticles())
		{
		Particle& ptcl = *ptcl_ptr;

		bool exceedsRightBound = ptcl.GetPosition().x() + ptcl.GetRadius() > width + posx;
		bool exceedsLeftBound = ptcl.GetPosition().x() - ptcl.GetRadius() < posx;
		bool exceedsTopBound = ptcl.GetPosition().y() - ptcl.GetRadius() < posy;
		bool exceedsBottomBound = ptcl.GetPosition().y() + ptcl.GetRadius() > height + posy;
		// x-axis clamping
		if (exceedsRightBound)
		{
			ptcl.ReflectMomentum(Vector2f(-1.0f, 0.0f));
		}
		if (exceedsLeftBound)
		{
			ptcl.ReflectMomentum(Vector2f(1.0f, 0.0f));
		}
		// y-axis clamping
		if (exceedsBottomBound)
		{
			ptcl.ReflectMomentum(Vector2f(0.0f, -1.0f));
		}
		if (exceedsTopBound)
		{
			ptcl.ReflectMomentum(Vector2f(0.0f, 1.0f));
		}
	}
}

void Container::CollisionWrap(Particle& ptcl)
{
	// x-axis wrapping
	if (ptcl.GetPosition().x() + ptcl.GetRadius() > width + posx)
	{
		ptcl.SetPosition(Vector2f((float)posx + ptcl.GetRadius(), height - ptcl.GetPosition().y() + posy));
	}
	if (ptcl.GetPosition().x() - ptcl.GetRadius() < posx)
	{
		ptcl.SetPosition(Vector2f((float)posx + width - ptcl.GetRadius(), height - ptcl.GetPosition().y() + posy));
	}

	// y-axis wrapping
	if (ptcl.GetPosition().y() + ptcl.GetRadius() > height + posy)
	{
		ptcl.SetPosition(Vector2f(width - ptcl.GetPosition().x() + posx, (float)posy + ptcl.GetRadius()));
	}
	if (ptcl.GetPosition().y() - ptcl.GetRadius() < posy)
	{
		ptcl.SetPosition(Vector2f(width - ptcl.GetPosition().x() + posx, (float)posy - ptcl.GetRadius()));
	}
}

int Container::GetContainerHeight()
{
	return height;
}
int Container::GetContainerWidth()
{
	return width;
}
int Container::GetContainerX()
{
	return posx;
}
int Container::GetContainerY()
{
	return posy;
}