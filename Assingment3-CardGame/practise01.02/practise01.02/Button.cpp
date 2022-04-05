#include "Button.h"

Button::Button()
{
}

Button::~Button()
{
	m_image.Unload();
}

void Button::CreateButton(std::string file, std::string hoverfile, int width, int height)
{
	m_image.Load(file);
	m_hoverImage.Load(hoverfile);
	m_image.SetImageDimension(1, 1,  width, height);
	m_hoverImage.SetImageDimension(1, 1, width, height);
}

void Button::SetButtonDimension(int width, int height)
{
	m_image.SetSpriteDimension( width, height);
	m_hoverImage.SetSpriteDimension( width, height);
	m_collider.w = width;
	m_collider.h = height;
}

void Button::SetButtonPosition(int width, int height)
{
	SetPosition(width, height);
	m_collider.x = width;
	m_collider.y = height;
}

SDL_Rect Button::GetCollider()
{
	return m_collider;
}

void Button::Update()
{

}
void Button::Render()
{
	SDL_Point point = Input::Instance()->GetMousePosition();

	if (SDL_PointInRect(&point, &m_collider))
	{
		m_hoverImage.Render(m_position.x, m_position.y, m_angle);
	}
	else
	{
		m_image.Render(m_position.x, m_position.y, m_angle);
	}
}
