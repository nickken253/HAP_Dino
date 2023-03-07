#pragma once
#include "GameStateBase.h"
#include "../GameObjects/ParallelBG.h"
class GSMenu : public GameStateBase
{
public:
	GSMenu();
	virtual ~GSMenu();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

private:
	std::list<GameButton*> m_listButton;
	sf::Sprite m_background;
	sf::Sprite m_gameTitle;
	ParallelBG m_parallelBG;
	sf::Music* m_music;

	bool m_isPlaySound;
};
