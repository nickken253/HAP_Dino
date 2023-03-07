#include "FallingPlatform.h"

void FallingPlatform::Init()
{
	m_hitBox = new HitBox(sf::Vector2i(32, 10));
	m_hitBox->Init(sf::Vector2f(0, 0));
	m_hitBox->setPosition(m_position.x, m_position.y);
	m_runAni = new Animation(*DATA->getTexture("Falling Platforms/on"), sf::Vector2i(4, 1), 0.06f);
	m_deathAni = new Animation(*DATA->getTexture("Falling Platforms/off"), sf::Vector2i(1, 1), 1.0f);
	m_currentAni = m_runAni;
	m_hitBox->setTag(FALLINGPLATS);
	m_isActivated = false;
}
FallingPlatform::~FallingPlatform()
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
void FallingPlatform::Update(float deltaTime)
{
	if (m_hitBox->isAlive())
	{
		m_currentAni->Update(deltaTime);
		m_currentAni->setPosition(getHitBox()->getPosition());
	}
	else
	{
		m_currentTime += deltaTime;
		float velocity = 10 * m_currentTime; // v = g * t;
		
		m_currentAni = m_deathAni;
		m_currentAni->setModeEndFrame(true);
		m_currentAni->Update(deltaTime);
		m_currentAni->setPosition(getHitBox()->getPosition());
		if (m_currentTime > 0.3f)
		{
			m_hitBox->move(0, velocity);
		}
	}
}

void FallingPlatform::Render(sf::RenderWindow* window)
{
	m_currentAni->setScale(1, 1);
	if (!m_stop)
	{
		window->draw(*m_currentAni);
		window->draw(*m_hitBox);
		// m_hitBox->~HitBox();
	}

}