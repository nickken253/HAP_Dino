#pragma once
#include "Monster.h"

class Wind : public Monster
{
public:
	Wind(sf::Vector2f position) { m_position = position; };
	~Wind();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	sf::Vector2f m_position;
	int const_distance;
};