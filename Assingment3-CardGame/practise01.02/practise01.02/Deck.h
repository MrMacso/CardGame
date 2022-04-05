#pragma once
#include "Card.h"
#include "GameObject.h"
#include "Input.h"

#include <vector>
class Deck :
    public GameObject
{
public:

	Deck();
	~Deck();

	void OnEnter();
	void Decks();
	
	SDL_Rect GetCurrentCollider();
	void SetCurrentCollider(SDL_Rect& collider);
	void Update();
	void Render();
	Card GetInosuke();


private:
	Card m_inosuke;
	Card m_tanjiro;
	SDL_Rect m_currentCollider;

	std::vector<Card> m_playerDeck;
	std::vector<Card> m_aiDeck;
};

