#include "PSJump.h"
#include "Player.h"

PSJump::PSJump(IPlayer* player)
{
	m_player = player;
	m_currentTime = 0.f;
	m_turnRight = true;
	m_isMove = Player::ISMOVE;
	m_isPlayed = false;
}

void PSJump::Init()
{
	m_animation = new Animation(*DATA->getTexture("Character/jump"), sf::Vector2i(3, 1), 0.08f);
	m_animation->setModeEndFrame(true);
}

void PSJump::Update(float deltaTime)
{
	DATA->getSound("Player/run")->stop();
	if (!m_isPlayed)
	{
		DATA->playSound("Player/jump");
		m_isPlayed = true;
	}
	m_animation->Update(deltaTime);
	m_currentTime += deltaTime;
	float velocity = 20 * m_currentTime; // v = g * t;
	
	if (m_player->getHitBox()->getDirection() == DIRECTION::BELOW)
	{
		m_player->changeNextState(FALL);
		m_isPlayed = false;
		m_currentTime = 0.f;
	}
	if (m_player->getHitBox()->getDirection() == DIRECTION::ABOVE)
	{
		m_player->getHitBox()->setDirection(DNULL);
	}

	// JUMP
	if (-m_player->getHitBox()->getVelocity().y * deltaTime + velocity >= 0)
	{
		m_player->changeNextState(FALL);
		m_isPlayed = false;
		m_currentTime = 0.f;
	}
	else m_player->getHitBox()->move(0, -m_player->getHitBox()->getVelocity().y * deltaTime + velocity); // y = y * t + v;

	// FLOAT
	if (m_player->getHitBox()->getDirection() == DIRECTION::INSIDE)
	{
		m_player->changeNextState(FLOAT);
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
	if (!m_player->getHitBox()->isAlive()) m_player->changeNextState(IPState::DEATH);
	m_animation->setPosition(m_player->getHitBox()->getPosition());
}

void PSJump::Render(sf::RenderWindow* window)
{
	if (Player::ISTURNRIGHT) m_animation->setScale(ScaleCharacter, ScaleCharacter);
	else m_animation->setScale(-ScaleCharacter, ScaleCharacter);
	window->draw(*m_animation);
}
