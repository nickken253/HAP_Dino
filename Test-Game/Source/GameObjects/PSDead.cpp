#include "PSDead.h"

PSDead::PSDead(IPlayer* player)
{
	m_player = player;
	m_remainTime = 1.f;
	m_isPlayed = false;
}

void PSDead::Init()
{
	m_animation = new Animation(*DATA->getTexture("Character/hurt"), sf::Vector2i(4, 1), 0.08f);
	m_animation->setModeEndFrame(true);
	isHighest = false;
}

void PSDead::Update(float deltaTime)
{
	m_animation->Update(deltaTime);
	m_currentTime += deltaTime;
	DATA->getSound("Player/run")->stop();
	if (!m_isPlayed)
	{
		DATA->playSound("Player/dead");
		m_isPlayed = true;
		Player::LIVE--;
	}
	m_animation->rotate(-10 * m_currentTime);
	if (m_currentTime > m_remainTime)
	{
		GSM->PopState();
		if (Player::LIVE > 0) GSM->ChangeState(STATETYPES::PLAY);
		else
		{
			GSM->ChangeState(STATETYPES::END);
			DATA->getMusic("Playing/play-1-10")->stop();
			DATA->playMusic("Sad_ending");
		}
	}
	

	float velocity = 30 * m_currentTime; // v = g * t;
	if (isHighest) m_player->getHitBox()->move(0, velocity);
	if (!isHighest && -m_player->getHitBox()->getVelocity().y * deltaTime + velocity >= 0)
	{
		isHighest = true;
		m_currentTime = 0.f;
	}
	else if (!isHighest)
	{
		
		m_player->getHitBox()->move(0, -m_player->getHitBox()->getVelocity().y * deltaTime + velocity);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		// m_player->changeNextState(DEATH);
	}
	m_animation->setPosition(m_player->getHitBox()->getPosition());
}

void PSDead::Render(sf::RenderWindow* window)
{
	m_animation->setScale(ScaleCharacter, ScaleCharacter);
	window->draw(*m_animation);
}
