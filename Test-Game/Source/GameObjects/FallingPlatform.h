#pragma once
#include "Monster.h"
#include "CollisionManager.h"

class FallingPlatform : public Monster
{
public:
	FallingPlatform(sf::Vector2f position) { m_position = position; };
	~FallingPlatform();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	int m_windBoxLong;
	HitBox* m_windHitBox;
	sf::Vector2f m_position;
	bool m_isActivated;
	CollisionManager m_collisionManager;
	float m_currentTime;
};