#pragma once
#include "../GameManager/ResourceManager.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/MWalkingMushroom.h"
#include "../GameObjects/FatBird.h"
#include "../GameObjects/CollisionManager.h"
#include "../GameObjects/TileMapBase.h"
#include "../GameObjects/ParallelBG.h"
#include "../GameObjects/MapManager.h"
#include "../GameObjects/MapCollider.h"
#include "../GameObjects/Coin.h"
#include "../GameObjects/Door.h"
#include "../GameObjects/Saw.h"
#include "../GameObjects/Fan.h"
#include "../GameObjects/FallingPlatform.h"
#include "../GameObjects/Thorn.h"
#include "../GameObjects/Platform.h"

class MapManager
{
public:
	MapManager();
	~MapManager();
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render(sf::RenderWindow* window);
	static int LEVEL;
	static bool RESETMAP;
	virtual sf::Vector2f getViewPosition();
protected:
	sf::View view;
	sf::Sprite m_background;
	
	
	Player m_player;
	Door* m_door;

	CollisionManager m_collisionManager;

	std::vector<int> m_mapMatrix;
	MapCollider m_mapCollider;
	TileMapBase map;

	std::vector<int> m_mapDecor;
	TileMapBase mapDecor;

	std::list<Monster*> m_listMonster;
	std::list<Coin*> m_listCoin;
	std::list<HitBox*> m_listCollision;
	std::list<sf::Vector2i> m_listPos;
	std::list<Wind*> m_listWind;

	Fan* m_fan;
	bool checked;
};
