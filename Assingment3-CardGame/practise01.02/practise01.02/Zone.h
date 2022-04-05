#pragma once
#include "Card.h"
#include "GameObject.h"
#include "Input.h"
#include "Sprite.h"
class Zone :
    public GameObject
{
public:
    Zone();
    ~Zone();
    void CreateZone(int width, int height);
    void SetZoneDimension(int width, int height);
    void SetZonePosition(int width, int height);
    SDL_Rect GetCollider();

    void Render();

private:

    Sprite m_image;
    SDL_Rect m_collider{ 0,0 };
    SDL_Rect m_currentCollider;
};

