#pragma once
#include "GameStateBase.h"
#include "../GameManager/OperationsManager.h"
#include "../GameObjects/ParallelBG.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/MapManager.h"


class GSEnd : public GameStateBase
{
public:
	GSEnd();
	virtual ~GSEnd();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	
private:
	std::list<GameButton*> m_listButton;
	sf::Sprite m_background;
	sf::Sprite m_board;
	ParallelBG m_parallelBG;
	sf::Text m_coinCounting;
	sf::Text m_level;
	sf::Text m_total;

	int m_tmpCoin;
	int m_tmpLevel;
	int m_tmpTotal;
	int Total;
	float m_currentTime;
	bool m_isPlayed;
	bool m_isBest;

	GameButton* m_musicBtn;
	GameButton* m_soundBtn;
};
