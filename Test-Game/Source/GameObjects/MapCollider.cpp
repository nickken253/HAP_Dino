#include "MapCollider.h"

MapCollider::MapCollider()
{
	m_count = 0;
}

MapCollider::~MapCollider()
{
}

std::list<sf::Vector2i> MapCollider::loadMapCollider(sf::Vector2i BaseSize, std::vector<int> Tile, int Width, int Height)
{
	for (int i = 0; i < Width; ++i)
	{
		for (int j = 0; j < Height; ++j)
		{
			if (Tile[i + j * Width] > 0 && Tile[i + j * Width] <= 48 && Tile[i + j * Width] != 22)
			{
				m_count++;
				m_listPos.push_back(sf::Vector2i(i * BaseSize.x, j * BaseSize.y));
			}
		}
	}
	return m_listPos;
}
