#pragma once
#include "IPState.h"
#include "IPlayer.h"

class Player;
class PSGoin : public IPState
{
public:
	PSGoin(IPlayer* player);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void setMove(bool isMove) { m_isMove = isMove; }
	Animation* getAnimation() { return m_animation; }
private:
	IPlayer* m_player;
	Animation* m_animation;

	float m_currentTime;
	bool m_turnRight;
	bool m_isMove;
	sf::Sound* m_sound;
	bool m_isPlayed;
};