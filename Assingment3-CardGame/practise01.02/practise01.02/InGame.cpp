#include "InGame.h"

InGame::InGame()
{
}

InGame::~InGame()
{
}

void InGame::OnEnter()
{


	m_deck.OnEnter();
}

SDL_Rect InGame::GetCurrentCollider()
{
    return m_currentCollider;
}

void InGame::SetCurrentCollider(SDL_Rect collider)
{
    m_currentCollider = collider;
}

void InGame::Update()
{
	bool isMouseClicked = Input::Instance()->IsMouseClicked();
	SDL_Point mousePos = Input::Instance()->GetMousePosition();

	SDL_Rect card = m_deck.GetInosuke().GetCollider();
	m_deck.Update();

	//if (SDL_HasIntersection(&card, &zone) && isMouseClicked == true)
	{
		//m_deck.GetInosuke().SetCardPosition(m_zone.GetPosition().x, m_zone.GetPosition().y);
	}
}

void InGame::Render()
{

	m_deck.Render();
}
