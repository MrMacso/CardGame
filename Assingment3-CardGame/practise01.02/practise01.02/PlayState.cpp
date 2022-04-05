#include "PlayState.h"
#include "MenuState.h"

bool PlayState::OnEnter()
{
    m_background.Load("assets/images/Forest.jpg");
    m_background.SetImageDimension(1, 1, 1800, 1200);
    m_background.SetSpriteDimension(1600, 1040);
    m_zone.CreateZone(129, 187);
    m_zone.SetZonePosition(600, 100);

    m_deck.OnEnter();

    return true;
}

GameState* PlayState::Update()
{
    m_deck.Update();

    //check key presses/mouse click
    //check if buttons are clicked
    //if (userWishToExitToMenu)
    //{
    //    return new MenuState;
    //}
    //if (userWishToPause)
    //{
    //    return new PauseState;
    //}
    //return this;
    return this;
}

bool PlayState::Render()
{
    m_background.Render(0, 0, 0);
    m_zone.Render();
    m_deck.Render();
    return true;
}

void PlayState::OnExit()
{
    m_background.Unload();
}
