#include "Player.h"


Player::Player()
{
	m_velocity = 0;
	m_health = 1000;
	m_position.x = 753;
	m_position.y = 350;
	m_image[static_cast<int>(State::IDLE)]->Load("assets/images/FightLightBanditLeft.png");
	m_image[static_cast<int>(State::RUN)]->Load("assets/images/LeftRunLightBandit.png");
	m_image[static_cast<int>(State::ATTACK)]->Load("assets/images/AttackLeftLightBandit.png");
	m_image[static_cast<int>(State::HURT)]->Load("assets/images/FightLightBandit.png");
	m_image[static_cast<int>(State::DIE)]->Load("assets/images/FightLightBandit.png");

	for (int i = 0; i < static_cast<int>(State::TOTAL_STATES); i++)
	{
		m_image[i]->SetSpriteDimension(132, 120);

		if (i == static_cast<int>(State::IDLE))
		{
			m_image[i]->SetImageDimension(4, 1, 192, 48);
		}
		else
		{
			m_image[i]->SetImageDimension(8, 1, 384, 48);
		}
		m_image[i]->IsAnimated(true);
		m_image[i]->SetAnimationVelocity(0.5f);

		if ( i == static_cast<int>(State::DIE))
		{
			m_image[i]->IsAnimationLooping(true);
		}
		else
		{
			m_image[i]->IsAnimationLooping(true);
		}
	}
}
Player::~Player()
{
	m_image[static_cast<int>(m_state)]->Unload();
}
int Player::GetVelocity()
{
	return m_velocity;
}
int Player::GetHealth()
{
	return m_health;
}
void Player::SetHealth(int health)
{
	m_health = health;
}
void Player::ReduceHealth(int damage)
{
	m_health = m_health - damage;
}
void Player::IncreaseHealth(int heal)
{
	m_health = m_health + heal;
}
void Player::CheckHealth()
{
	if (m_health < 0)
	{
		m_health = 0;
	}
	if (m_health > 1000)
	{
		m_health = 1000;
	}
}
void Player::SetState(State state)
{
	m_state = state;
}
void Player::SetVelocity(int velocity)
{
	m_velocity = velocity;
}
void Player::SetIsAttacking(bool attack)
{
	m_isAttacking = attack;
}
bool Player::GetIsAttacking()
{
	return m_isAttacking;
}
void Player::AttackCollider()
{
	if (m_isAttacking == true)
	{
		m_collider.SetDimension(90, 90);
		m_collider.SetPosition(m_position.x, m_position.y + 30);
	}
	else
	{
		m_collider.SetDimension(45, 90);
		m_collider.SetPosition(m_position.x + 35, m_position.y + 30);
	}
}

const BoxCollider Player::GetCollider()
{
	return m_collider;
}



void Player::Update()
{
	if (Input::Instance()->GetKeyDown() == SDLK_a)
	{
		m_direction.x = -1;
		m_direction.y = 0;
		m_facingDirection = Direction::LEFT;
		SetState(State::RUN);

	}
	else if (Input::Instance()->GetKeyDown() == SDLK_d)
	{

		m_direction.x = 1;
		m_direction.y = 0;
		m_facingDirection = Direction::RIGHT;
		SetState(State::RUN);

	}
	else if (Input::Instance()->GetKeyDown() == SDLK_w)
	{
		m_direction.x = 0;
		m_direction.y = -1;
		SetState(State::RUN);
	}
	else if (Input::Instance()->GetKeyDown() == SDLK_s)
	{
		m_direction.x = 0;
		m_direction.y = 1;
		SetState(State::RUN);
	}
	else if (Input::Instance()->GetKeyDown() == SDLK_e)
	{
		IncreaseHealth(10);
	}
	else
	{
		m_direction.x = 0;
		m_direction.y = 0;
		SetState(State::IDLE);
		m_isAttacking = false;
	}
	if (Input::Instance()->GetKeyDown() == SDLK_q)
	{
		SetState(State::ATTACK);
		m_isAttacking = true;
		AttackCollider();
	}
	//======================================================================
	CheckHealth();
	m_direction = m_direction.Scale(m_velocity);
	m_position = m_position.Add(m_direction);

	m_collider.SetDimension(45, 90);
	m_collider.SetPosition(m_position.x +35, m_position.y + 30);
	m_collider.Update();
	m_image[static_cast<int>(m_state)]->Update();
}

void Player::Render()
{
	if (m_facingDirection == Direction::LEFT)
	{
		m_image[static_cast<int>( m_state)]->Render(m_position.x, m_position.y, m_angle, Sprite::NO_FLIP);
	}
	if(m_facingDirection == Direction::RIGHT)
	{
		m_image[static_cast<int>(m_state)]->Render(m_position.x, m_position.y, m_angle, Sprite::HORZ_FLIP);
	}
}
