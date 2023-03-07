#pragma once
#include "GameStateBase.h"
#include "../GameObjects/ParallelBG.h"
class GSLeaderBoard : public GameStateBase
{
public:
	GSLeaderBoard();
	virtual ~GSLeaderBoard();

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
	std::list<sf::Text*> m_listScore;
};
