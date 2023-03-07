#include "Door.h"

Door::Door(sf::Vector2f position)
{
	m_position = position;
	m_isOpened = false;
}
Door::~Door()
{
	m_currentAni = nullptr;
	if (m_idleAni != nullptr)
	{
		delete m_idleAni;;
	}
	if (m_openAni != nullptr)
	{
		delete m_openAni;
	}
	if (m_hitBox != nullptr)
	{
		delete m_hitBox;
	}
}
void Door::Init()
{
	m_hitBox = new HitBox(sf::Vector2i(32, 64));
	m_hitBox->Init(sf::Vector2f(-MRunVelocity, 0));
	m_hitBox->setPosition(m_position.x, m_position.y);
	m_idleAni = new Animation(*DATA->getTexture("Door/idle"), sf::Vector2i(1, 1), 0.06f);
	m_openAni = new Animation(*DATA->getTexture("Door/open"), sf::Vector2i(6, 1), 0.2f);
	m_currentAni = m_idleAni;
	m_hitBox->setTag(DOOR);
	m_stop = false;
}
void Door::Update(float deltaTime)
{
	if (m_stop == true) return;
	if (m_hitBox->isAlive())
	{
		m_currentAni->Update(deltaTime);
		m_currentAni->setPosition(getHitBox()->getPosition());
	}
	else
	{
		m_currentAni = m_openAni;
		if (m_currentAni->getCurrentFrame().x != m_currentAni->getFrameNum().x - 1)
		{
			m_currentAni->Update(deltaTime);
			m_currentAni->setPosition(getHitBox()->getPosition());
		}
		else m_stop = true, m_isOpened = true;
	}
}
void Door::Render(sf::RenderWindow* window)
{
	window->draw(*m_currentAni);
	window->draw(*m_hitBox);
}