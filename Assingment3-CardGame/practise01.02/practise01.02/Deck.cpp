#include "Deck.h"

Deck::Deck()
{
}

Deck::~Deck()
{
}

void Deck::OnEnter()
{
    m_inosuke.CreateCard("assets/images/Inosuke.png", "Inosuke       ",
        2500, 2100, 129, 187);
    m_inosuke.SetCardPosition(650, 700);

    m_tanjiro.CreateCard("assets/images/Tanjiro.jpg", "Tanjiro     ",
        3000, 2500, 129, 187);
    m_tanjiro.SetCardPosition(800, 700);
}

void Deck::Decks()
{
    m_playerDeck.push_back(m_inosuke);
    m_playerDeck.push_back(m_tanjiro);
}

SDL_Rect Deck::GetCurrentCollider()
{
    return m_currentCollider;
}
//=========================================================================================================
void Deck::SetCurrentCollider(SDL_Rect& collider)
{
    m_currentCollider = collider;
}

void Deck::Update()
{
    m_inosuke.Update();
    m_tanjiro.Update();
}

void Deck::Render()
{
    m_inosuke.Render();
    m_tanjiro.Render();
}

Card Deck::GetInosuke()
{
    return m_inosuke;
}
