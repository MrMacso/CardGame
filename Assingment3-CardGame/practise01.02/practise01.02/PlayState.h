#pragma once

#include "GameState.h"
#include "Sprite.h"
#include "Deck.h"
#include "Zone.h"

class PlayState : public GameState
{
public:
	~PlayState() override {}

	bool OnEnter() override;
	GameState* Update() override;
	bool Render() override;
	void OnExit() override;
private:

	bool m_isCardPickedUp{ false };
	Sprite m_background;
	Zone m_zone;
	Deck m_deck;
};

