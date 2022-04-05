#pragma once
#include "GameObject.h"
#include "Input.h"
#include "Zone.h"
#include "Sprite.h"
#include "SDLText.h"
class Card : public GameObject
{
public:
    Card();
    ~Card();

    void CreateCard(std::string file, std::string name, int attack, int defense, int width, int height);
    void SetCardDimension(int width, int height);
    void SetCardPosition(int width, int height);
    SDL_Rect GetCollider();
    void SetText();
    void Update();
    void Render();



private:
    std::string m_name = "null";
    Sprite m_image;
    Sprite m_zoomImage;
    Sprite m_profile;
    Sprite m_zoomProfile;
    Sprite m_select;
    SDL_Rect m_collider;

    //card details
    int m_attack{ 0 };
    int m_defense{ 0 };
    SDLText m_textName;
    SDLText m_textDetails;

    SDLText m_zoomTextName;
    SDLText m_zoomTextDetails;
};

