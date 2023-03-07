#pragma once
#include "Monster.h"

class Thorn : public Monster
{
public:
	Thorn(sf::Vector2f position) { m_position = position; };
	~Thorn();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	sf::Vector2f m_position;
	int const_distance;
};