#include "Fan.h"

void Fan::Init()
{
	m_hitBox = new HitBox(sf::Vector2i(24, 8));
	m_hitBox->Init(sf::Vector2f(0, 0));
	m_hitBox->setPosition(m_position.x, m_position.y);
	m_runAni = new Animation(*DATA->getTexture("Fan/on"), sf::Vector2i(4, 1), 0.06f);
	m_deathAni = new Animation(*DATA->getTexture("Fan/off"), sf::Vector2i(1, 1), 1.0f);
	m_currentAni = m_deathAni;
	m_hitBox->setTag(FAN);
	m_isActivated = false;
}
Fan::~Fan()
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
void Fan::Update(float deltaTime)
{
	if (m_hitBox->isAlive())
	{
		m_currentAni->Update(deltaTime);
		m_currentAni->setPosition(getHitBox()->getPosition());
	}
	else
	{
		m_currentAni = m_runAni;
		if (!m_isActivated)
		{
			m_listWind.push_back(new Wind(sf::Vector2f(m_hitBox->getPosition().x, m_hitBox->getPosition().y - 32 * 0.5 - 4)));
			m_listWind.push_back(new Wind(sf::Vector2f(m_hitBox->getPosition().x, m_hitBox->getPosition().y - 32 * 1.5 - 4)));
			m_listWind.push_back(new Wind(sf::Vector2f(m_hitBox->getPosition().x, m_hitBox->getPosition().y - 32 * 2.5 - 4)));
			for (auto it : m_listWind)
			{
				it->Init();
				m_collisionManager.addObj(it->getHitBox());
			}
			m_isActivated = true;
		}
		m_currentAni->Update(deltaTime);
		m_currentAni->setPosition(getHitBox()->getPosition());
		//m_stop = true;
	}
	for (auto it : m_listWind)
	{
		it->Update(deltaTime);
	}
}

void Fan::Render(sf::RenderWindow* window)
{
	for (auto it : m_listWind)
	{
		it->Render(window);
	}
	m_currentAni->setScale(1, 1);
	if (!m_stop)
	{
		window->draw(*m_currentAni);
		window->draw(*m_hitBox);
		// m_hitBox->~HitBox();
	}

}