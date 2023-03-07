#include "MWalkingMushroom.h"

void MWalkingMushroom::Init()
{
	m_hitBox = new HitBox(sf::Vector2i(19, 19));
	m_hitBox->Init(sf::Vector2f(-MRunVelocity, 0));
	m_hitBox->setPosition(m_position.x, m_position.y);
	m_runAni = new Animation(*DATA->getTexture("Standing Mushroom/run"), sf::Vector2i(4, 1), 0.12f);
	m_deathAni = new Animation(*DATA->getTexture("Standing Mushroom/dead"), sf::Vector2i(5, 1), 0.02f);
	m_currentAni = m_runAni;
	m_isTurnRight = false;
	m_hitBox->setTag(MONSTER);
	const_distance = m_distance;
	m_stop = false;
}
MWalkingMushroom::~MWalkingMushroom()
{
	if (m_hitBox == nullptr)
	{
		delete m_hitBox;
	}
	if (m_deathAni != nullptr)
	{
		delete m_deathAni;;
	}
	if (m_runAni != nullptr)
	{
		delete m_runAni;
	}
	if (m_hitBox != nullptr)
	{
		delete m_hitBox;
	}
}
void MWalkingMushroom::Update(float deltaTime)
{
	if (m_stop == true) return;
	if (m_hitBox->isAlive())
	{
		if (m_distance < 0)
		{
			m_isTurnRight = !m_isTurnRight;
			m_distance = const_distance;
		}
		else m_distance--;
		
		if (m_isTurnRight == false)
		{
			m_hitBox->move(m_hitBox->getVelocity() * deltaTime);
		}
		else
		{
			m_hitBox->move(-m_hitBox->getVelocity() * deltaTime);
		}
		m_currentAni->Update(deltaTime);
		m_currentAni->setPosition(getHitBox()->getPosition());
	}
	else
	{
		m_currentAni = m_deathAni;
		if (m_currentAni->getCurrentFrame().x != m_currentAni->getFrameNum().x - 1)
		{
			m_currentAni->Update(deltaTime);
			m_currentAni->setPosition(getHitBox()->getPosition());
		}
		else m_stop = true;
	}
}

void MWalkingMushroom::Render(sf::RenderWindow* window)
{
	if (m_stop == true) return;
	if (m_isTurnRight) m_currentAni->setScale(0.5, 0.5);
	else m_currentAni->setScale(-0.5, 0.5);
	if (!m_stop)
	{
		window->draw(*m_currentAni);
		window->draw(*m_hitBox);
		// m_hitBox->~HitBox();
	}
	
}