#include "PSFloat.h"
#include "Player.h"

PSFloat::PSFloat(IPlayer* player)
{
	m_player = player;
	m_currentTime = 0.f;
	m_turnRight = true;
	m_isMove = Player::ISMOVE;
}

void PSFloat::Init()
{
	m_animation = new Animation(*DATA->getTexture("Character/idle"), sf::Vector2i(3, 1), 0.03f);
	//m_animation->setModeEndFrame(true);
}

void PSFloat::Update(float deltaTime)
{

	m_animation->Update(deltaTime);
	m_currentTime += deltaTime;
	float velocity = 50 * m_currentTime; // v = g * t;
	if (m_player->getHitBox()->getDirection() != DIRECTION::INSIDE)
	{
		m_player->getHitBox()->setDirection(DNULL);
		m_player->changeNextState(FALL);
		m_currentTime = 0.f;
	}
	else
	{
		m_player->getHitBox()->move(0, m_player->getHitBox()->getVelocity().y * deltaTime - 10); // y = y * t + v;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			m_player->getHitBox()->move(0, -m_player->getHitBox()->getVelocity().y * deltaTime + 12);
		}
	}

	// MOVE
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (Player::ISTURNRIGHT)
		{
			Player::ISTURNRIGHT = false;
		}
		if (Player::ISMOVE) m_player->getHitBox()->move(-m_player->getHitBox()->getVelocity().x * deltaTime, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (Player::ISTURNRIGHT == false)
		{
			Player::ISTURNRIGHT = true;
		}
		if (Player::ISMOVE) m_player->getHitBox()->move(m_player->getHitBox()->getVelocity().x * deltaTime, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_player->getHitBox()->move(0, -m_player->getHitBox()->getVelocity().y * deltaTime + 5);
	}
	if (!m_player->getHitBox()->isAlive()) m_player->changeNextState(IPState::DEATH);
	m_animation->setPosition(m_player->getHitBox()->getPosition());
}

void PSFloat::Render(sf::RenderWindow* window)
{
	if (Player::ISTURNRIGHT) m_animation->setScale(ScaleCharacter, ScaleCharacter);
	else m_animation->setScale(-ScaleCharacter, ScaleCharacter);
	window->draw(*m_animation);
}
