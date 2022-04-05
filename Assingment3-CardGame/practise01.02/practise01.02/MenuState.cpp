#include "MenuState.h"


bool MenuState::OnEnter()
{
    background.Load("assets/images/MenuBg.jpg");
    background.SetImageDimension(1, 1, 1920, 1521);
    background.SetSpriteDimension(1600, 1040);

    int button = 1;
    auto loadButton = [&button](Button& name, const std::string& loadOriginal, const std::string& loadSelect, 
                                int heightPos, int widthPos)
    {
        name.CreateButton(loadOriginal, loadSelect, 300, 120);
        name.SetButtonDimension(300, 120);
        name.SetButtonPosition(heightPos, widthPos);
    };
    loadButton(m_startButton, "assets/images/StartB.png", "assets/images/StartBSelect.png", 650, 400);
    loadButton(m_howToButton, "assets/images/HowToB.png", "assets/images/HowToBSelect.png", 650, 550);
    loadButton(m_exitButton, "assets/images/ExitB.png", "assets/images/ExitBSelect.png", 650, 700);

    return true;
}
//======================================================================
GameState* MenuState::Update()
{
    SDL_Point mousePos = Input::Instance()->GetMousePosition();
    SDL_Rect startCollider = m_startButton.GetCollider();
    SDL_Rect howToCollider = m_howToButton.GetCollider();
    SDL_Rect exitCollider = m_exitButton.GetCollider();
    bool isMouseClicked = Input::Instance()->IsMouseClicked();

    if (SDL_PointInRect(&mousePos, &startCollider) && isMouseClicked == true)
    {
        return new PlayState;
    }
    if (SDL_PointInRect(&mousePos, &howToCollider) && isMouseClicked == true)
    {
        return new PlayState;
    }
    if (SDL_PointInRect(&mousePos, &exitCollider) && isMouseClicked == true)
    {
        return nullptr;
    }
    return this;
}
//======================================================================
bool MenuState::Render()
{
    background.Render(0, 0, 0);
    m_startButton.Render();
    m_howToButton.Render();
    m_exitButton.Render();

    return true;
}
//======================================================================
void MenuState::OnExit()
{
    background.Unload();
}
