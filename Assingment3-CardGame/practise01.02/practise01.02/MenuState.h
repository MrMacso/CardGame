#pragma once
#include "GameState.h"
#include "Sprite.h"
#include "Button.h"
#include "PlayState.h"

class MenuState : public GameState
{
public:
	~MenuState() override {};

	bool OnEnter() override;
	GameState* Update() override;
	bool Render() override;
	void OnExit() override;
private:
	Sprite background;
	Button m_startButton;
	Button m_howToButton;
	Button m_exitButton;
	
};

