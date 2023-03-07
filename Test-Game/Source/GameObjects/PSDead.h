#pragma once
#include "IPState.h"
#include "IPlayer.h"
#include "Player.h"
#include "../GameStateManager/GameStateMachine.h"
#include "../GameObjects/MapManager.h"

class PSDead : public IPState
{
public:
	PSDead(IPlayer* player);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	Animation* getAnimation() { return m_animation; }
private:
	IPlayer* m_player;
	Animation* m_animation;
	float m_currentTime;
	float m_remainTime;
	bool isHighest;
	bool m_isPlayed;
};