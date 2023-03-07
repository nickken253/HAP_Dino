#pragma once
#include "../GameManager/ResourceManager.h"
#include "HitBox.h"

class MapCollider
{
public:
	MapCollider();
	~MapCollider();
	std::list<sf::Vector2i> loadMapCollider(sf::Vector2i BaseSize, std::vector<int> Tile, int Width, int Height);
private:
	int m_count;
	std::list<HitBox*> m_listBaseMap;
	std::list<sf::Vector2i> m_listPos;
};