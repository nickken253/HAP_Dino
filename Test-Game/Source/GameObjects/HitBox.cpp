#include "HitBox.h"

HitBox::HitBox(sf::Vector2i size) : RectangleShape((sf::Vector2f)size)
{
	this->setOrigin((sf::Vector2f)size / 2.f);
	this->setFillColor(sf::Color(0, 0, 0, 0));
	//this->setOutlineColor(sf::Color::Red);
	//this->setOutlineThickness(0.3f);

	m_velocity = sf::Vector2f(0, 0);
	m_isAlive = true;
	m_isOnPlatform = false;
}

HitBox::~HitBox()
{
}

void HitBox::Init(sf::Vector2f velocity)
{
	m_velocity = velocity;
}

sf::Vector2f HitBox::getVelocity()
{
	return m_velocity;
}
