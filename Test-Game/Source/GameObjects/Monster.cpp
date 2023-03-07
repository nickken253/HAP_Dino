#include "Monster.h"

Monster::Monster()
{
	m_stop = false;
}

Monster::~Monster()
{
	m_currentAni = nullptr;
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

void Monster::Init()
{
}

void Monster::Update(float deltaTime)
{
}


void Monster::Render(sf::RenderWindow* window)
{
}
