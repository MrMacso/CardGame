#include <iostream>

#include "Game.h"
#include "MenuState.h"
#include "Screen.h"

//#include "GameObject.h"
//#include "SDL.h"
//#include "SDL_image.h"
//#include "SDLText.h"
//#include "SDL_ttf.h"
//#include "Sprite.h"
//#include <string>
//#include "Music.h"
//#include "Vector2D.h"
//#include "Screen.h"
//#include "Button.h"


std::unique_ptr<Game> game = std::make_unique<Game>(new MenuState);


int main(int i, char* v[])
{
	if (game->Initialize())
	{
		game->Run();
		game->Shutdown();
	}
	return 0;
}

