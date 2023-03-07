#pragma once
#include "../GameManager/ResourceManager.h"
enum TAG
{
	PLAYER,
	MONSTER,
	BOSS,
	THORN,
	COIN,
	MAP,
	TAGNULL,
	DOOR,
	SAW,
	FAN,
	WIND,
	FALLINGPLATS,
	PLATFORM,
};
enum DIRECTION
{
	DNULL,
	ABOVE,
	BELOW,
	RIGHT,
	LEFT,
	INSIDE,
	GOIN,
};
class HitBox :public sf::RectangleShape
{
public:
	HitBox(sf::Vector2i size);
	~HitBox();

	void Init(sf::Vector2f velocity);
	sf::Vector2f getVelocity();
	TAG getTag() { return m_tag; }
	void setTag(TAG tag) { m_tag = tag; }

	DIRECTION getDirection() { return m_direction; }
	void setDirection(DIRECTION direction) { m_direction = direction; }

	bool isAlive() { return m_isAlive; }
	void setAlive(bool alive) { m_isAlive = alive; }

	bool isOnPlatform() { return m_isOnPlatform; }
	void setOnPlatform(bool onPlatform) { m_isOnPlatform = onPlatform; }

	sf::Vector2f getHalfSize() { return this->getSize() / 2.0f; }

private:
	sf::Vector2f m_velocity;
	bool m_isAlive;
	bool m_isOnPlatform;
	TAG m_tag;
	DIRECTION m_direction;
};