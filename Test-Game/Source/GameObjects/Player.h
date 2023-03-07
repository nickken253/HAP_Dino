#pragma once
#include "IPlayer.h"

class Player : public IPlayer
{
public:
	Player();
	~Player();
	void changeNextState(IPState::STATE nextState);

	void Init(sf::Vector2f position);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void setMove(bool isMove) { ISMOVE = isMove; }
	HitBox* getHitBox();

	static bool ISTURNRIGHT;
	static bool ISMOVE;
	static int LIVE;
	HitBox* m_hitBox;

	sf::Vector2f GetPosition() { return m_body->getPosition(); }

private:
	void performStateChange();
	
	IPState::STATE m_nextState;

	IPState* m_currentState;
	IPState* m_runState;
	IPState* m_jumpState;
	IPState* m_fallState;
	IPState* m_deathState;
	IPState* m_launchState;
	IPState* m_snullState;
	IPState* m_idleState;
	IPState* m_goinState;
	IPState* m_winningState;
	IPState* m_floatState;
	sf::Sound* m_sound;
	bool m_isPlayed;
	sf::RectangleShape* m_body;
	sf::Vector2f m_position;
};