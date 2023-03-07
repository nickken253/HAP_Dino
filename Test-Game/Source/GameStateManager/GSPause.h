#pragma once
#include "GameStateBase.h"
#include "../GameObjects/ParallelBG.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/MapManager.h"

class GSPause : public GameStateBase
{
public:
	GSPause();
	virtual ~GSPause();

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

	GameButton* m_musicBtn;
	GameButton* m_soundBtn;
};
