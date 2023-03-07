#include "Thorn.h"

Thorn::~Thorn()
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
void Thorn::Init()
{
	m_hitBox = new HitBox(sf::Vector2i(32, 14));
	m_hitBox->Init(sf::Vector2f(0, 0));
	m_hitBox->setPosition(m_position.x, m_position.y);
	m_runAni = new Animation(*DATA->getTexture("Thorn/idle"), sf::Vector2i(1, 1), 1.0f);
	m_currentAni = m_runAni;
	m_isTurnRight = false;
	m_hitBox->setTag(SAW);
	m_stop = false;
}
void Thorn::Update(float deltaTime)
{
	m_currentAni->Update(deltaTime);
	m_currentAni->setPosition(getHitBox()->getPosition());
}
void Thorn::Render(sf::RenderWindow* window)
{

	window->draw(*m_currentAni);
	window->draw(*m_hitBox);
}