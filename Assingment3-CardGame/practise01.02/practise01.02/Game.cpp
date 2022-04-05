#include "Game.h"

Game::Game(GameState* initialState)
{
    m_gamestate.reset(initialState);
}
//======================================================================
bool Game::Initialize()
{
    Screen::Instance()->Initialize("Test", 1600, 1040);
    return true;
}
//======================================================================
bool Game::Run()
{
    m_gamestate->OnEnter();
    

    while (m_gamestate)
    {
        Screen::Instance()->Clear();
        Input::Instance()->Update();

        GameState* nextState = m_gamestate->Update();
        
        m_gamestate->Render();
        m_gamestate->Update();

        //clearing the screen
        //updating the input
        //checking delta time
        //updating the current screen
        Screen::Instance()->Present();

        if (nextState != m_gamestate.get())
        {
            m_gamestate->OnExit();
            m_gamestate.reset(nextState);

            if (m_gamestate)
            {
                m_gamestate->OnEnter();
            }
        }
    }
        return true;
}
//======================================================================
void Game::Shutdown()
{
}
