#include "PSFall.h"
#include "Player.h"

PSFall::PSFall(IPlayer* player)
{
	m_player = player;
	m_turnRight = true;
	m_isMove = Player::ISMOVE;
}
void PSFall::Init()
{
	m_animation = new Animation(*DATA->getTexture("Character/fall"), sf::Vector2i(1, 1), 0.08f);
	//m_animation = new Animation(*DATA->getTexture("Character/idle"), sf::Vector2i(3, 1), 0.2f);
	m_animation->setModeEndFrame(true);
}

void PSFall::Update(float deltaTime)
{
	m_animation->Update(deltaTime);

	// FALLING AFTER JUMPING
	m_currentTime += deltaTime;
	float velocity = 20 * m_currentTime; // v = g * t;
	m_player->getHitBox()->move(0, velocity);

	if (m_player->getHitBox()->getDirection() == DIRECTION::ABOVE)
	{
		velocity = 0;
		m_player->changeNextState(IDLE);
		m_currentTime = 0.f;
	}
	// FLOAT
	if (m_player->getHitBox()->getDirection() == DIRECTION::INSIDE)
	{
		velocity = 0;
		m_player->changeNextState(FLOAT);
		m_currentTime = 0.f;
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

	// DEAD
	if (!m_player->getHitBox()->isAlive()) m_player->changeNextState(IPState::DEATH);

	m_animation->setPosition(m_player->getHitBox()->getPosition());
}

void PSFall::Render(sf::RenderWindow* window)
{
	if (Player::ISTURNRIGHT) m_animation->setScale(ScaleCharacter, ScaleCharacter);
	else m_animation->setScale(-ScaleCharacter, ScaleCharacter);
	window->draw(*m_animation);
}
