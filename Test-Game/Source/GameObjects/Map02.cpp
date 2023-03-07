#include "Map02.h"

void Map02::Init()
{
	MapManager::RESETMAP = false;
	checked = false;
	// SET VIEW
	view.setCenter(sf::Vector2f(0.0f, 0.0f));
	view.setSize(sf::Vector2f(ViewSizeWidht, ViewSizeHight));

	// CHECK WIN
	m_isWin = false;

	// ADD PLAYER
	{
		m_player.Init(sf::Vector2f(Pos0X + 0.5 * 32, Pos0Y + 9.5 * 32));
		m_collisionManager.addObj(m_player.getHitBox());
	}

	// ADD MONSTER
	{
		// WALKING MUSHROOMS
		m_listMonster.push_back(new MWalkingMushroom(sf::Vector2f(Pos0X + 32 * 31.5, Pos0Y + 32 * 12.5 + 7), 1.5 * 32));

		// THORN
		m_listMonster.push_back(new Thorn(sf::Vector2f(Pos0X + 32 * 7.5, Pos0Y + 32 * 15.5 + 9)));
		m_listMonster.push_back(new Thorn(sf::Vector2f(Pos0X + 32 * 8.5, Pos0Y + 32 * 15.5 + 9)));
		m_listMonster.push_back(new Thorn(sf::Vector2f(Pos0X + 32 * 13.5, Pos0Y + 32 * 15.5 + 9)));
		m_listMonster.push_back(new Thorn(sf::Vector2f(Pos0X + 32 * 16.5, Pos0Y + 32 * 15.5 + 9)));
		m_listMonster.push_back(new Thorn(sf::Vector2f(Pos0X + 32 * 19.5, Pos0Y + 32 * 20.5 + 9)));
		m_listMonster.push_back(new Thorn(sf::Vector2f(Pos0X + 32 * 20.5, Pos0Y + 32 * 20.5 + 9)));
		m_listMonster.push_back(new Thorn(sf::Vector2f(Pos0X + 32 * 23.5, Pos0Y + 32 * 20.5 + 9)));
		m_listMonster.push_back(new Thorn(sf::Vector2f(Pos0X + 32 * 24.5, Pos0Y + 32 * 20.5 + 9)));
		m_listMonster.push_back(new Thorn(sf::Vector2f(Pos0X + 32 * 27.5, Pos0Y + 32 * 20.5 + 9)));
		m_listMonster.push_back(new Thorn(sf::Vector2f(Pos0X + 32 * 28.5, Pos0Y + 32 * 20.5 + 9)));
		m_listMonster.push_back(new Thorn(sf::Vector2f(Pos0X + 32 * 31.5, Pos0Y + 32 * 20.5 + 9)));
		m_listMonster.push_back(new Thorn(sf::Vector2f(Pos0X + 32 * 32.5, Pos0Y + 32 * 20.5 + 9)));
		m_listMonster.push_back(new Thorn(sf::Vector2f(Pos0X + 32 * 35.5, Pos0Y + 32 * 20.5 + 9)));
		m_listMonster.push_back(new Thorn(sf::Vector2f(Pos0X + 32 * 41.5, Pos0Y + 32 * 9.5 + 9)));
		m_listMonster.push_back(new Thorn(sf::Vector2f(Pos0X + 32 * 42.5, Pos0Y + 32 * 9.5 + 9)));

		// PLATFORMS
		m_listMonster.push_back(new Platform(sf::Vector2f(Pos0X + 32 * 37.5, Pos0Y + 32 * 19.5), 32 * 3, 200));

		for (auto it : m_listMonster)
		{
			it->Init();
			m_collisionManager.addObj(it->getHitBox());
		}
	}
	// ADD COIN
	{
		//m_coin = new Coin(sf::Vector2f(300, 625));
		m_listCoin.push_back(new Coin(sf::Vector2f(Pos0X + 6.5 * 32, Pos0Y + 32 * 11.5)));
		m_listCoin.push_back(new Coin(sf::Vector2f(Pos0X + 6.5 * 32, Pos0Y + 32 * 12.5)));
		m_listCoin.push_back(new Coin(sf::Vector2f(Pos0X + 6.5 * 32, Pos0Y + 32 * 13.5)));
		m_listCoin.push_back(new Coin(sf::Vector2f(Pos0X + 6.5 * 32, Pos0Y + 32 * 14.5)));
		m_listCoin.push_back(new Coin(sf::Vector2f(Pos0X + 11.5 * 32, Pos0Y + 32 * 15.5)));
		m_listCoin.push_back(new Coin(sf::Vector2f(Pos0X + 12.5 * 32, Pos0Y + 32 * 15.5)));
		m_listCoin.push_back(new Coin(sf::Vector2f(Pos0X + 14.5 * 32, Pos0Y + 32 * 15.5)));
		m_listCoin.push_back(new Coin(sf::Vector2f(Pos0X + 15.5 * 32, Pos0Y + 32 * 15.5)));
		m_listCoin.push_back(new Coin(sf::Vector2f(Pos0X + 21.5 * 32, Pos0Y + 32 * 20.5)));
		m_listCoin.push_back(new Coin(sf::Vector2f(Pos0X + 22.5 * 32, Pos0Y + 32 * 20.5)));
		m_listCoin.push_back(new Coin(sf::Vector2f(Pos0X + 25.5 * 32, Pos0Y + 32 * 20.5)));
		m_listCoin.push_back(new Coin(sf::Vector2f(Pos0X + 26.5 * 32, Pos0Y + 32 * 20.5)));
		m_listCoin.push_back(new Coin(sf::Vector2f(Pos0X + 29.5 * 32, Pos0Y + 32 * 20.5)));
		m_listCoin.push_back(new Coin(sf::Vector2f(Pos0X + 30.5 * 32, Pos0Y + 32 * 20.5)));
		m_listCoin.push_back(new Coin(sf::Vector2f(Pos0X + 33.5 * 32, Pos0Y + 32 * 20.5)));
		m_listCoin.push_back(new Coin(sf::Vector2f(Pos0X + 34.5 * 32, Pos0Y + 32 * 20.5)));
		m_listCoin.push_back(new Coin(sf::Vector2f(Pos0X + 41.5 * 32, Pos0Y + 32 * 8.5)));
		m_listCoin.push_back(new Coin(sf::Vector2f(Pos0X + 42.5 * 32, Pos0Y + 32 * 8.5)));
		for (auto it : m_listCoin)
		{
			it->Init();
			m_collisionManager.addObj(it->getHitBox());
		}
	}
	map.setOrigin(m_background.getOrigin());
	map.setPosition(m_background.getPosition());

	// ADD DOOR
	m_door = new Door(sf::Vector2f(Pos0X + 47.5 * 32, Pos0Y + (8.5 + 0.5) * 32));
	m_door->Init();
	m_collisionManager.addObj(m_door->getHitBox());

	// BACKGROUND
	{
		sf::Texture* texture = DATA->getTexture("Background Layers/Background01");
		m_background.setTexture(*texture);
		m_background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
		m_background.setPosition(screenWidth / 2, screenHight / 2);
	}

	// MAP
	{
		m_mapMatrix =
		{
			22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
			22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
			22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
			22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
			22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
			5, 42, 42, 42, 42, 42, 42, 42, 42, 6, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 5, 42, 42, 42, 42, 42, 42, 42, 42, 42, 6, 22, 22,
			23, 61, 62, 62, 62, 62, 62, 62, 63, 21, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23, 61, 62, 62, 62, 62, 62, 62, 62, 63, 21, 22, 22,
			23, 81, 82, 82, 82, 82, 82, 82, 83, 21, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23, 81, 82, 82, 82, 82, 82, 82, 82, 83, 41, 42, 42,
			49, 81, 82, 82, 82, 82, 82, 82, 83, 21, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 5, 42, 42, 42, 42, 42, 6, 22, 22, 22, 23, 81, 82, 82, 82, 82, 82, 82, 82, 85, 62, 63, 49,
			50, 101, 102, 102, 102, 66, 82, 82, 83, 21, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23, 61, 62, 62, 62, 63, 21, 22, 22, 22, 23, 81, 82, 82, 65, 102, 102, 102, 102, 102, 102, 103, 50,
			2, 2, 2, 2, 3, 81, 82, 82, 83, 21, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23, 81, 82, 82, 82, 83, 21, 22, 22, 22, 23, 81, 65, 102, 103, 1, 2, 2, 2, 2, 2, 2, 2,
			22, 22, 22, 22, 23, 81, 82, 82, 83, 41, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 6, 22, 22, 22, 23, 81, 82, 82, 82, 83, 21, 22, 22, 22, 23, 81, 83, 45, 46, 21, 22, 22, 22, 22, 22, 22, 22,
			22, 22, 22, 22, 23, 81, 82, 82, 85, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 63, 21, 22, 22, 22, 23, 101, 102, 102, 102, 103, 21, 22, 22, 22, 23, 81, 85, 62, 63, 21, 22, 5, 42, 42, 42, 42, 42,
			22, 22, 22, 22, 23, 81, 82, 82, 82, 65, 102, 66, 82, 82, 82, 82, 82, 82, 82, 82, 83, 21, 22, 22, 22, 25, 2, 2, 2, 2, 2, 26, 22, 22, 22, 23, 81, 82, 82, 83, 21, 22, 23, 61, 62, 62, 62, 62,
			22, 22, 22, 22, 23, 81, 82, 82, 82, 83, 4, 81, 82, 82, 82, 82, 82, 82, 82, 82, 83, 21, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23, 81, 82, 82, 83, 21, 22, 23, 81, 82, 82, 82, 82,
			22, 22, 22, 22, 23, 101, 102, 102, 102, 103, 24, 101, 102, 102, 102, 102, 102, 66, 82, 82, 83, 21, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23, 81, 82, 82, 83, 21, 22, 23, 81, 82, 82, 82, 82,
			22, 22, 22, 22, 25, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 81, 82, 82, 83, 41, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 43, 81, 82, 82, 83, 21, 22, 23, 81, 82, 82, 82, 82,
			22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23, 81, 82, 82, 85, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 86, 82, 82, 83, 21, 22, 23, 81, 82, 82, 82, 82,
			22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23, 81, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 65, 102, 103, 21, 22, 23, 81, 82, 82, 82, 82,
			22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23, 81, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 83, 45, 46, 21, 22, 23, 81, 82, 82, 82, 82,
			22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23, 101, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 93, 106, 107, 21, 22, 23, 81, 82, 82, 82, 82,
			22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 25, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 26, 22, 23, 81, 82, 82, 82, 82,
			22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23, 101, 102, 102, 102, 102,
			22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 25, 2, 2, 2, 2, 2,
		};

		map.LoadBase(DATA->getTexture("Map/Terrain (32x32) minisize"), sf::Vector2i(32, 32), m_mapMatrix, 48, 24);
	}

	// MAP
	{
		m_mapDecor =
		{
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 24, 25, 0, 0, 0, 9, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 31, 32, 0, 0, 0, 16, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 16, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 26, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 33, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 16, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 9, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 9, 16, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 16, 23, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 24, 25, 0, 6, 7, 0, 26, 27, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 32, 0, 0, 0, 0, 33, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 3, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		};

		mapDecor.LoadBase(DATA->getTexture("Map/Decorations (32x32)"), sf::Vector2i(32, 32), m_mapDecor, 48, 24);
	}

	// MAP COLLIDER
	{
		float tmpX = m_background.getPosition().x;
		float tmpY = m_background.getPosition().y;
		m_listPos = m_mapCollider.loadMapCollider(sf::Vector2i(32, 32), m_mapMatrix, 48, 24);
		for (auto it : m_listPos)
		{
			HitBox* tmpHitBox = new HitBox(sf::Vector2i(32, 32));
			tmpHitBox->setPosition(sf::Vector2f(it.x + 48 / 3 - abs(tmpX - m_background.getGlobalBounds().width / 2), it.y + 48 / 3 - abs(tmpY - m_background.getGlobalBounds().height / 2)));
			tmpHitBox->setTag(MAP);
			m_collisionManager.addObj(tmpHitBox);
			m_collisionManager.addMap(tmpHitBox);
			m_listCollision.push_back(tmpHitBox);
		}
	}

	
}
void Map02::Update(float deltaTime)
{
	// FOLLOWING CAMERA
	sf::Vector2f pos;
	if (m_player.getHitBox()->getPosition().x < m_background.getPosition().x)
	{
		pos.x = std::max(m_player.getHitBox()->getPosition().x, m_background.getPosition().x - m_background.getGlobalBounds().width / 2 + ViewSizeWidht / 2);
	}
	else pos.x = std::min(m_player.getHitBox()->getPosition().x, m_background.getPosition().x + m_background.getGlobalBounds().width / 2 - ViewSizeWidht / 2);
	if (m_player.getHitBox()->getPosition().y < m_background.getPosition().y)
	{
		pos.y = std::max(m_player.getHitBox()->getPosition().y, m_background.getPosition().y - m_background.getGlobalBounds().height / 2 + ViewSizeHight / 2);
	}
	else pos.y = std::min(m_player.getHitBox()->getPosition().y, m_background.getPosition().y + m_background.getGlobalBounds().height / 2 - ViewSizeHight / 2);
	view.setCenter(pos);


	if (m_player.getHitBox()->getPosition().x > m_background.getPosition().x - m_background.getGlobalBounds().width / 2 && m_player.getHitBox()->getPosition().x < m_background.getPosition().x + m_background.getGlobalBounds().width / 2 && m_player.getHitBox()->getPosition().y > m_background.getPosition().y - m_background.getGlobalBounds().height / 2 && m_player.getHitBox()->getPosition().y < m_background.getPosition().y + m_background.getGlobalBounds().height / 2)
	{

		m_player.setMove(true);
	}
	else
	{
		m_player.setMove(false);
		if (m_player.getHitBox()->getPosition().x <= m_background.getPosition().x - m_background.getGlobalBounds().width / 2)
		{
			m_player.getHitBox()->setPosition(m_background.getPosition().x - m_background.getGlobalBounds().width / 2 + 1, m_player.getHitBox()->getPosition().y);
		}
		if (m_player.getHitBox()->getPosition().x >= m_background.getPosition().x + m_background.getGlobalBounds().width / 2)
		{
			m_player.getHitBox()->setPosition(m_background.getPosition().x + m_background.getGlobalBounds().width / 2 - 1, m_player.getHitBox()->getPosition().y);
		}
	}

	m_player.Update(deltaTime);
	// UPDATE HITBOX
	{
		for (auto it : m_listMonster)
		{
			if (it->getHitBox()->getPosition().y < m_background.getPosition().y + m_background.getGlobalBounds().height / 2 + 20) it->Update(deltaTime);
		}
		for (auto it : m_listCoin)
		{
			it->Update(deltaTime);
		}
		m_door->Update(deltaTime);
		m_collisionManager.Update();
		for (auto it : m_listWind)
		{
			it->Update(deltaTime);
		}
	}
	if (m_player.getHitBox()->getPosition().y > m_background.getPosition().y + m_background.getGlobalBounds().height / 2 + 20) m_player.getHitBox()->setAlive(false);
	if (m_door->getHitBox()->isAlive() == false && m_door->isOpened()) MapManager::LEVEL++, MapManager::RESETMAP = true;
}
void Map02::Render(sf::RenderWindow* window)
{
	window->draw(m_background);
	window->draw(map);
	window->draw(mapDecor);
	window->setView(view);
	for (auto it : m_listCollision)
	{
		window->draw(*it);
	}
	for (auto it : m_listWind)
	{
		it->Render(window);
	}
	m_door->Render(window);
	for (auto it : m_listMonster)
	{
		if (it->getHitBox()->getPosition().y < m_background.getPosition().y + m_background.getGlobalBounds().height / 2 + 20) it->Render(window);
	}
	m_player.Render(window);
	for (auto it : m_listCoin)
	{
		it->Render(window);
	}

}