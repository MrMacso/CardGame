#include "Zone.h"


Zone::Zone()
{
}

Zone::~Zone(){m_image.Unload();}
//=========================================================================================================
void Zone::CreateZone(int width, int height)
{
	m_image.Load("assets/images/Zone.jpg");
	m_image.SetImageDimension(1, 1, 300, 437);
	SetZoneDimension(width, height);
}
//=========================================================================================================
void Zone::SetZoneDimension(int width, int height)
{
	m_image.SetSpriteDimension(width, height);
	m_collider.w = width;
	m_collider.h = height;
}
//=========================================================================================================
void Zone::SetZonePosition(int width, int height)
{
	SetPosition(width, height);
	m_collider.x = width;
	m_collider.y = height;
}
//=========================================================================================================
SDL_Rect Zone::GetCollider()
{
	return m_collider;
}
//=========================================================================================================
void Zone::Render()
{
	m_image.Render(m_position.x, m_position.y, m_angle);
}
//=========================================================================================================