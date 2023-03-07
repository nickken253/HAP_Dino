#pragma once
#include "../GameManager/ResourceManager.h"

class IPState
{
public:
	enum STATE
	{
		RUN,
		JUMP,
		FALL,
		WINNING,
		DEATH,
		LAUNCH,
		SNULL,
		IDLE,
		GOIN,
		FLOAT,
	};
	// virtual IPState(Player* player) = 0;

	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;

	virtual Animation* getAnimation() = 0;
};