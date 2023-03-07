#include "Coin.h"

Coin::Coin(sf::Vector2f position)
{
	m_position = position;
	m_stop = false;
	m_isPlayed = false;
};
int Coin::COIN_COUNTING = 0;
Coin::~Coin()
{
	m_currentAni = nullptr;
	if (m_deathAni != nullptr)
	{
		delete m_deathAni;;
	}
	if (m_idleAni != nullptr)
	{
		delete m_idleAni;
	}
	if (m_hitBox != nullptr)
	{
		delete m_hitBox;
	}
}
void Coin::Init()
{
	m_hitBox = new HitBox(sf::Vector2i(16, 16));
	m_hitBox->Init(sf::Vector2f(0, 0));
	m_hitBox->setPosition(m_position.x, m_position.y);
	m_idleAni = new Animation(*DATA->getTexture("Coin/idle"), sf::Vector2i(12, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Coin/disappear"), sf::Vector2i(6, 1), 0.08f);
	m_currentAni = m_idleAni;
	m_hitBox->setTag(COIN);
	//m_sound = DATA->getSound("Coin/coin2");
	
}
void Coin::Update(float deltaTime)
{
	if (m_stop == true) return;
	if (m_hitBox->isAlive())
	{
		m_currentAni->Update(deltaTime);
		m_currentAni->setPosition(getHitBox()->getPosition());
	}
	else
	{
		if (!m_isPlayed)
		{
			if (COIN_COUNTING % 2 == 0) DATA->playSound("Coin/coin1");
			else DATA->playSound("Coin/coin2");
			// m_sound->play();
			m_isPlayed = true;
			//if(COIN_COUNTING % 2 == 0) m_sound = DATA->getSound("Coin/coin1");
			//else m_sound = DATA->getSound("Coin/coin2");
		}
		m_currentAni = m_deathAni;
		if (m_currentAni->getCurrentFrame().x != m_currentAni->getFrameNum().x - 1)
		{
			m_currentAni->Update(deltaTime);
			m_currentAni->setPosition(getHitBox()->getPosition());
		}
		else
		{
			m_stop = true;
			COIN_COUNTING++;
		}
	}
}
void Coin::Render(sf::RenderWindow* window)
{
	if (m_stop == true) return;
	//m_currentAni->setScale(3, 3);
	if (!m_stop)
	{
		window->draw(*m_currentAni);
		window->draw(*m_hitBox);
	}
}