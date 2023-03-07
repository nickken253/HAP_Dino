#include "Platform.h"

Platform::~Platform()
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
void Platform::Init()
{
	m_hitBox = new HitBox(sf::Vector2i(32, 8));
	m_hitBox->Init(sf::Vector2f(0,-m_velocity));
	m_hitBox->setPosition(m_position.x, m_position.y);
	m_runAni = new Animation(*DATA->getTexture("Platforms/on"), sf::Vector2i(8, 1), 0.01f);
	m_currentAni = m_runAni;
	m_isTurnRight = false;
	m_hitBox->setTag(PLATFORM);
	const_distance = m_distance;
	m_stop = false;
}
void Platform::Update(float deltaTime)
{
	if (m_hitBox->isAlive() == false)
	{
		if (m_distance > 0)
		{
			m_hitBox->move(m_hitBox->getVelocity() * deltaTime);
			m_distance--;
		}
	}
	m_currentAni->Update(deltaTime);
	m_currentAni->setPosition(getHitBox()->getPosition());
}
void Platform::Render(sf::RenderWindow* window)
{
	/*if (m_isTurnRight) m_currentAni->setScale(0.5, 0.5);
	else m_currentAni->setScale(-0.5, 0.5);*/
	window->draw(*m_currentAni);
	window->draw(*m_hitBox);
}