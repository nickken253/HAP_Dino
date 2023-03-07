#pragma once
#include "../GameManager/ResourceManager.h"
#include "HitBox.h"

class Coin
{
public:
	Coin(sf::Vector2f position);
	~Coin();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	HitBox* getHitBox() { return m_hitBox; }
	static int COIN_COUNTING;
private:
	sf::Vector2f m_position;
	HitBox* m_hitBox;
	Animation* m_currentAni;
	Animation* m_deathAni;
	Animation* m_idleAni;
	sf::Sound* m_sound;
	bool m_isPlayed;
	bool m_stop;
	
};