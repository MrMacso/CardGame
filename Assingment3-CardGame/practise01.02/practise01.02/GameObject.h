#pragma once

#include <SDL.h>
#include <string>
//#include "Input.h"
#include "Screen.h"
#include "Vector2D.h"

class GameObject
{

public:
	GameObject();

	float GetAngle() const;
	const std::string& GetTag() const;

	const Vector2D& GetSize() const;
	 Vector2D GetPosition() ;

	void SetTag(const std::string& tag);
	void SetAngle(float angle);

	void SetSize(int width, int height);
	void SetSize(const Vector2D& size);

	void SetPosition(int x, int y);
	void SetPosition(const Vector2D& position);

	virtual void Render() = 0;

protected:
	float m_angle;
	std::string m_tag;

	Vector2D m_size;
	Vector2D m_position;
	Vector2D m_velocity;
};

