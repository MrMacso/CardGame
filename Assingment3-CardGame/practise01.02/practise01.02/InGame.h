#pragma once
#include "Deck.h"


class InGame
{
public:
	InGame();
	~InGame();
	void OnEnter();
	SDL_Rect GetCurrentCollider();
	void SetCurrentCollider(SDL_Rect collider);
	void Update();
	void Render();

private:
	SDL_Rect m_currentCollider;

	Deck m_deck;

};

