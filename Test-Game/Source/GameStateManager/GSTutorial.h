#pragma once
#include "GameStateBase.h"
#include "../GameObjects/ParallelBG.h"

class GSTutorial : public GameStateBase
{
public:
	GSTutorial();
	virtual ~GSTutorial();

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
};
