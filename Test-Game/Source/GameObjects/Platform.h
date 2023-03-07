#pragma once
#include "Monster.h"

class Platform : public Monster
{
public:
	Platform(sf::Vector2f position, int distance, int velocity) { m_position = position; m_distance = distance; m_velocity = velocity; };
	~Platform();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	sf::Vector2f m_position;
	int const_distance;
	int m_velocity;
};