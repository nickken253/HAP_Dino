#include "Wind.h"

Wind::~Wind()
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
void Wind::Init()
{
	m_hitBox = new HitBox(sf::Vector2i(32, 32));
	m_hitBox->Init(sf::Vector2f(0, 0));
	m_hitBox->setPosition(m_position.x, m_position.y);
	m_runAni = new Animation(*DATA->getTexture("Fan/wind"), sf::Vector2i(4, 1), 0.1f);
	m_currentAni = m_runAni;
	m_hitBox->setTag(WIND);
	m_stop = false;
}
void Wind::Update(float deltaTime)
{
	m_currentAni->Update(deltaTime);
	m_currentAni->setPosition(getHitBox()->getPosition());
}
void Wind::Render(sf::RenderWindow* window)
{
	window->draw(*m_currentAni);
	window->draw(*m_hitBox);
}