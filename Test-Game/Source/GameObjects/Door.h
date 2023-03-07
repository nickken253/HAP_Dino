#pragma once
#include "../GameManager/ResourceManager.h"
#include "HitBox.h"

class Door
{
public:
	Door(sf::Vector2f position);
	~Door();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	bool isOpened() { return m_isOpened; }
	HitBox* getHitBox() { return m_hitBox; }

protected:
	HitBox* m_hitBox;
	Animation* m_currentAni;
	Animation* m_idleAni;
	Animation* m_openAni;
	sf::Vector2f m_position;
	bool m_stop;
	bool m_isOpened;
};