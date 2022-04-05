#pragma once
#include <SDL.h>
#include "Vector2D.h"
#include <iostream>

class Input
{
	
public:
	
	static Input* Instance();
	void Update();

	char GetKeyUp();
	char GetKeyDown();

	int GetMouseButtonUp();
	int GetMouseButtonDown();

	bool IsKeyPressed();
	bool IsMouseClicked();
	bool IsWindowClosed();

	const SDL_Point& GetMousePosition();

private:

	Input(){}
	Input(const Input&);
	Input& operator=(Input&);

	char m_keyUp{true};
	char m_keyDown{false};

	bool m_isKeyPressed{ false };
	bool m_isMouseClicked{ false };
	bool m_isWindowClosed{ false };

	int m_mouseButtonUp;
	int m_mouseButtonDown;

	SDL_Point m_mousePosition;
};

