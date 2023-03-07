#pragma once
#include "GameStateBase.h"
#include "../GameObjects/ParallelBG.h"
class GSSettings : public GameStateBase
{
public:
	GSSettings();
	virtual ~GSSettings();

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

	sf::Text m_sound;
	sf::Text m_music;
};
