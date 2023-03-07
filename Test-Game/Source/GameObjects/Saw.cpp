#include "Saw.h"

Saw::~Saw()
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
void Saw::Init()
{
	m_hitBox = new HitBox(sf::Vector2i(38, 38));
	m_hitBox->Init(sf::Vector2f(- m_velocity.x, m_velocity.y));
	m_hitBox->setPosition(m_position.x, m_position.y);
	m_runAni = new Animation(*DATA->getTexture("Saw/on"), sf::Vector2i(8, 1), 0.01f);
	m_currentAni = m_runAni;
	m_isTurnRight = false;
	m_hitBox->setTag(SAW);
	const_distance = m_distance;
	m_stop = false;
}
void Saw::Update(float deltaTime)
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
void Saw::Render(sf::RenderWindow* window)
{
	/*if (m_isTurnRight) m_currentAni->setScale(0.5, 0.5);
	else m_currentAni->setScale(-0.5, 0.5);*/
	window->draw(*m_currentAni);
	window->draw(*m_hitBox);
}