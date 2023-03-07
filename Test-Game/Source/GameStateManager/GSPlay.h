#pragma once
#include "GameStateBase.h"
#include "../GameManager/OperationsManager.h"
#include "../GameObjects/MapManager.h"
#include "../GameObjects/Map01.h"
#include "../GameObjects/Map02.h"
#include "../GameObjects/Map03.h"
#include "../GameObjects/Map04.h"
#include "../GameObjects/Map05.h"
#include "../GameObjects/Map06.h"
#include "../GameObjects/MapEnd.h"
#include "../GameObjects/Coin.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/MapManager.h"

class GSPlay : public GameStateBase, public MapManager
{
public:
	GSPlay();
	virtual ~GSPlay();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	

private:

	std::list<GameButton*> m_listButton;
	ParallelBG m_parallelBG;
	sf::View view;
	MapManager* m_map;
	sf::Text m_coinCounting;
	sf::Sprite coinDecor;
	GameButton* button2;
	GameButton* PauseBtn;

	sf::RectangleShape m_live[3];
	// std::vector<sf::Sprite> m_live;
};
