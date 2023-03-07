#include "FatBird.h"


FatBird::~FatBird()
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
	if (m_fallAni != nullptr)
	{
		delete m_runAni;
	}
	if (m_groundAni != nullptr)
	{
		delete m_runAni;
	}
	if (m_hitBox != nullptr)
	{
		delete m_hitBox;
	}
}
void FatBird::Init()
{
	m_hitBox = new HitBox(sf::Vector2i(20, 24));
	m_hitBox->Init(sf::Vector2f(0, MJumpVelocity));
	m_hitBox->setPosition(m_position.x, m_position.y);
	m_runAni = new Animation(*DATA->getTexture("FatBird/idle"), sf::Vector2i(8, 1), 0.06f);
	m_fallAni = new Animation(*DATA->getTexture("FatBird/fall"), sf::Vector2i(4, 1), 0.06f);
	m_deathAni = new Animation(*DATA->getTexture("FatBird/dead"), sf::Vector2i(5, 1), 0.02f);
	m_groundAni = new Animation(*DATA->getTexture("FatBird/ground"), sf::Vector2i(4, 1), 0.12f);
	m_currentAni = m_runAni;
	m_hitBox->setTag(MONSTER);
	m_stop = false;
	m_isGround = false;
	m_isHighest = true;
	m_isFalling = false;
	m_isUprising = false;
	const_distance = m_distance;
}
void FatBird::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_stop == true) return;
	if (m_hitBox->isAlive())
	{
		if (m_isHighest)
		{
			if (m_currentTime < 2.0f)
			{
				m_currentAni->Update(deltaTime);
			}
			else
			{
				m_currentTime = 0.f;
				m_isHighest = false;
				m_isFalling = true;
				m_currentAni = m_fallAni;
			}
			
			
		}
		else if (m_isFalling)
		{
			float velocity = 10 * m_currentTime; // v = g * t;
			m_hitBox->move(0, velocity);
			m_distance--;
			if (m_currentAni->getCurrentFrame().x != m_currentAni->getFrameNum().x - 1)
			{
				m_currentAni->Update(deltaTime);
			}
			if (m_distance < 0)
			{
				m_currentAni = m_groundAni;
				m_currentTime = 0.f;
				m_isFalling = false;
				m_isGround = true;
			}
		}
		else if (m_isGround)
		{
			m_currentAni = m_groundAni;
			if (m_currentTime < 0.72f)
			{
				if (m_currentTime < 0.48f) 
				{
					m_currentAni->Update(deltaTime);
				}
			}
			else
			{
				m_currentAni = m_runAni;
				m_currentTime = 0.f;
				m_isGround = false;
				m_isUprising = true;
			}
		}
		else if (m_isUprising)
		{
			// m_currentAni = m_runAni;
			float velocity = - 10 * m_currentTime; // v = g * t;
			m_hitBox->move(0, velocity);
			m_distance++;
			m_currentAni->Update(deltaTime);
			if (m_distance > const_distance)
			{
				m_currentTime = 0.f;
				m_isUprising = false;
				m_isHighest = true;
			}
		}
		// m_currentAni->Update(deltaTime);
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
void FatBird::Render(sf::RenderWindow* window)
{
	if (m_stop == true) return;
	m_currentAni->setScale(0.5, 0.5);
	if (!m_stop)
	{
		window->draw(*m_currentAni);
		window->draw(*m_hitBox);
		// m_hitBox->~HitBox();
	}
}