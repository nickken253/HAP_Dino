#pragma once
#include "Monster.h"

class FatBird : public Monster
{
public:
	FatBird(sf::Vector2f position, int distance) { m_position = position; m_distance = distance; };
	~FatBird();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	sf::Vector2f m_position;
	Animation* m_fallAni;
	Animation* m_groundAni;

	bool m_stop;
	bool m_isGround;
	bool m_isHighest;
	bool m_isFalling;
	bool m_isUprising;

	int const_distance;
	float m_currentTime;
};