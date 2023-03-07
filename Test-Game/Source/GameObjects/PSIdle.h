#pragma once
#include "IPState.h"
#include "IPlayer.h"

class PSIdle : public IPState
{
public:
	PSIdle(IPlayer* player);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	Animation* getAnimation() { return m_animation; }
private:
	IPlayer* m_player;

	Animation* m_animation;
	Animation* m_goinAni;
	Animation* m_idleAni;
	bool m_turnRight;
	float m_currentTime;
	bool m_isWin;
};