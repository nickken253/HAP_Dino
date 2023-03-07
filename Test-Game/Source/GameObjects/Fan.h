#pragma once
#include "Monster.h"
#include "Wind.h"
#include "CollisionManager.h"

class Fan : public Monster
{
public:
	Fan(sf::Vector2f position, int windBoxLong) { m_position = position; m_windBoxLong = windBoxLong; };
	~Fan();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	std::list<Wind*> getWindList() { return m_listWind; }

	int m_windBoxLong;
	HitBox* m_windHitBox;
	sf::Vector2f m_position;
	std::list<Wind*> m_listWind;
	bool m_isActivated;
	CollisionManager m_collisionManager;
};