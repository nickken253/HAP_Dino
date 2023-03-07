#pragma once
#include "HitBox.h"

class CollisionManager
{
public:
	void addObj(HitBox* hitBox);
	void addMap(HitBox* hitBox);
	bool checkCollision(HitBox* a, HitBox* b);
	void Update();

	void Move(HitBox* hitBox, float dx, float dy);
	void Move(float dx, float dy);
	bool checkCollision(HitBox* a, HitBox* b, sf::Vector2f& direction, float push);
	sf::Vector2f getPosition(HitBox* hitBox);
	sf::Vector2f getHalfSize(HitBox* hitBox);
private:
	std::list<HitBox*> m_listObj;
	std::list<HitBox*> m_listMap;
	std::list<HitBox*> m_listWind;
	sf::Vector2f m_direction = sf::Vector2f(0, 0);
	int indexx = 0;
	// HitBox m_hitBox;
};