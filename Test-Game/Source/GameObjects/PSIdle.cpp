#include "PSIdle.h"
#include "Player.h"

PSIdle::PSIdle(IPlayer* player)
{
	m_player = player;
	m_turnRight = true;
}

void PSIdle::Init()
{
	m_animation = new Animation(*DATA->getTexture("Character/idle"), sf::Vector2i(3, 1), 0.2f);
	DATA->getSound("Player/run")->stop();
}

void PSIdle::Update(float deltaTime)
{
	m_animation->Update(deltaTime);

	// MOVE
	DATA->getSound("Player/run")->stop();
	if (m_player->getHitBox()->getDirection() == DIRECTION::GOIN)
	{
		m_player->changeNextState(STATE::GOIN);
	}
	if (m_player->getHitBox()->getDirection() == DIRECTION::DNULL)
	{
		m_player->changeNextState(STATE::FALL);
	}
	// FLOAT
	if (m_player->getHitBox()->getDirection() == DIRECTION::INSIDE)
	{
		m_player->changeNextState(STATE::FLOAT);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_player->changeNextState(STATE::JUMP);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (Player::ISTURNRIGHT == false)
			{
				Player::ISTURNRIGHT = true;
			}
		}
		else
		{
			if (Player::ISTURNRIGHT)
			{
				Player::ISTURNRIGHT = false;
			}
		}
		m_player->changeNextState(STATE::RUN);
	}

	// DEAD
	if (!m_player->getHitBox()->isAlive()) m_player->changeNextState(STATE::DEATH);

	m_animation->setPosition(m_player->getHitBox()->getPosition());
}

void PSIdle::Render(sf::RenderWindow* window)
{
	if (Player::ISTURNRIGHT) m_animation->setScale(ScaleCharacter, ScaleCharacter);
	else m_animation->setScale(-ScaleCharacter, ScaleCharacter);
	window->draw(*m_animation);
}
