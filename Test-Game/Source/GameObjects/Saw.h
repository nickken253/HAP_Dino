#pragma once
#include "Monster.h"

class Saw : public Monster
{
public:
	Saw(sf::Vector2f position, int distance, sf::Vector2f velocity) { m_position = position; m_distance = distance; m_velocity = velocity; };
	~Saw();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	sf::Vector2f m_position;
	int const_distance;
	sf::Vector2f m_velocity;
};