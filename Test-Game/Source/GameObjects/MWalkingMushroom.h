#pragma once
#include "Monster.h"

class MWalkingMushroom : public Monster
{
public:
	MWalkingMushroom(sf::Vector2f position, int distance) { m_position = position; m_distance = distance; };
	~MWalkingMushroom();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	sf::Vector2f m_position;
	int const_distance;

	bool m_stop;
};