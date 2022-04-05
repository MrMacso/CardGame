#include "Card.h"

Card::Card(){}

Card::~Card(){m_image.Unload();}
//=========================================================================================================
void Card::CreateCard(std::string file, std::string name, int attack, int defense, int width, int height)
{
	m_image.Load("assets/images/BlankCard.png");
	m_image.SetImageDimension(1, 1, 344, 500);
	SetCardDimension(width, height);

	m_zoomImage.Load("assets/images/BlankCard.png");
	m_zoomImage.SetImageDimension(1, 1, 344, 500);
	m_zoomImage.SetSpriteDimension(width * 1.6, height * 1.6);

	m_profile.Load(file);
	m_profile.SetImageDimension(1, 1, 400, 400);
	m_profile.SetSpriteDimension(width* 0.8 , height * 0.5);

	m_zoomProfile.Load(file);
	m_zoomProfile.SetImageDimension(1, 1, 400, 400);
	m_zoomProfile.SetSpriteDimension(width * 1.2, height * 0.8);

	m_select.Load("assets/images/Select.png");
	m_select.SetImageDimension(1, 1, 404, 560);
	m_select.SetSpriteDimension(width * 1.07, height * 1.07);


	m_name = name;
	m_attack = attack;
	m_defense = defense;
	SetText();
}
//=========================================================================================================
void Card::SetCardDimension( int width, int height )
{
	m_image.SetSpriteDimension(width, height);
	m_collider.w = width;
	m_collider.h = height;
}
//=========================================================================================================
void Card::SetCardPosition(int width, int height)
{
	SetPosition(width, height);
	m_collider.x = width;
	m_collider.y = height;
}
//=========================================================================================================
SDL_Rect Card::GetCollider()
{
	return m_collider;
}
//=========================================================================================================
void Card::SetText()
{
	int card = 1;
	auto loadCard = [&card](Sprite& image,SDLText& text, const std::string& name)
	{
		int positionX = image.GetSpriteDimension().x * 0.8;
		int positionY = image.GetSpriteDimension().y * 0.06;
		text.Initialize();
		text.Load("assets/images/fontbold.ttf", 60);
		text.SetText(name);
		text.SetDimension(positionX, positionY);
	};
	loadCard(m_image, m_textName, m_name);
	loadCard(m_image, m_textDetails, "ATK: " + std::to_string(m_attack) + "\n DEF: " + std::to_string(m_defense));
	loadCard(m_zoomImage, m_zoomTextName, m_name);
	loadCard(m_zoomImage, m_zoomTextDetails, "ATK: " + std::to_string(m_attack) + "\n DEF: " + std::to_string(m_defense));

}
//=========================================================================================================
void Card::Update()
{
	bool isMouseClicked = Input::Instance()->IsMouseClicked();
	SDL_Point mousePos = Input::Instance()->GetMousePosition();

	int cardPosX = m_zoomImage.GetSpriteDimension().x;
	int cardPosY = m_zoomImage.GetSpriteDimension().y;

	//positions for zoom image
	int zoomPos = mousePos.y - cardPosY;

	int namePositionX = m_zoomImage.GetSpriteDimension().x * 0.1 + mousePos.x;
	int namePositionY = m_zoomImage.GetSpriteDimension().y * 0.05 + zoomPos;

	int profilePositionX = m_zoomImage.GetSpriteDimension().x * 0.14 + mousePos.x;
	int profilePositionY = m_zoomImage.GetSpriteDimension().y * 0.2 + zoomPos;

	int detailPositionX = m_zoomImage.GetSpriteDimension().x * 0.1 + mousePos.x;
	int detailPositionY = m_zoomImage.GetSpriteDimension().y * 0.8 + zoomPos;

	int selectPositionX = GetPosition().x - 5;
	int selectPositionY = GetPosition().y - 5;

	//center of the card
	int centerX = mousePos.x - (m_image.GetSpriteDimension().x / 2);
	int centerY = mousePos.y - (m_image.GetSpriteDimension().y / 2);

	//SDL_Rect& zone = 

	if (SDL_PointInRect(&mousePos, &m_collider) && isMouseClicked == false)
	{
		m_select.Render(selectPositionX, selectPositionY, 0);
		m_zoomImage.Render(mousePos.x , zoomPos, 0);
		m_zoomProfile.Render( profilePositionX,  profilePositionY, 0);
		m_zoomTextName.Render( namePositionX, namePositionY);
		m_zoomTextDetails.Render(detailPositionX, detailPositionY);
	}
	if (SDL_PointInRect(&mousePos, &m_collider) && isMouseClicked == true)
	{
		SetCardPosition(centerX, centerY);
	}
	//if (SDL_HasIntersection(&zone, &m_collider) && isMouseClicked == true)
	//{
	//	SetCardPosition(zone.x, zone.y);
	//}
}
//=========================================================================================================
void Card::Render()
{
	int namePositionX = m_image.GetSpriteDimension().x * 0.1;
	int namePositionY = m_image.GetSpriteDimension().y * 0.05;

	int detailPositionX = m_image.GetSpriteDimension().x * 0.1;
	int detailPositionY = m_image.GetSpriteDimension().y * 0.8;

	int profilePositionX = m_image.GetSpriteDimension().x * 0.1;
	int profilePositionY = m_image.GetSpriteDimension().y * 0.2;

	m_image.Render(m_position.x, m_position.y, m_angle);
	m_profile.Render(m_position.x + profilePositionX, m_position.y + profilePositionY, m_angle);
	m_textName.Render(m_position.x + namePositionX, m_position.y + namePositionY);
	m_textDetails.Render(m_position.x + detailPositionX, m_position.y + detailPositionY);
}
//=========================================================================================================
