#pragma once
#include "../GameManager/ResourceManager.h"
#include "HitBox.h"

class Monster
{
public:
	Monster();
	~Monster();
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render(sf::RenderWindow* window);

	HitBox* getHitBox() { return m_hitBox; }

protected:
	HitBox* m_hitBox;
	Animation* m_currentAni;
	Animation* m_deathAni;
	Animation* m_runAni;
	//sf::Vector2f m_position;
	bool m_isTurnRight;
	int m_distance;
	bool m_stop;
};