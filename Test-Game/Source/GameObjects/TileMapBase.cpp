#include "TileMapBase.h"

bool TileMapBase::LoadBase(const sf::Texture* texture, sf::Vector2i BaseSize, std::vector<int> Tile, int Width, int Height)
{
	m_tileMapBase = *texture;
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(Width * Height * 4);
	
	for (int i = 0; i < Width; ++i)
	{
		for (int j = 0; j < Height; ++j)
		{
			int tileNumber = Tile[i + j * Width] - 1;
			int tu = tileNumber % (m_tileMapBase.getSize().x / BaseSize.x);
			int tv = tileNumber / (m_tileMapBase.getSize().x / BaseSize.x);

			sf::Vertex* square = &m_vertices[(i + j * Width) * 4];

			square[0].position = sf::Vector2f(i * BaseSize.x, j * BaseSize.y);
			square[1].position = sf::Vector2f((i + 1) * BaseSize.x, j * BaseSize.y);
			square[2].position = sf::Vector2f((i + 1) * BaseSize.x, (j + 1) * BaseSize.y);
			square[3].position = sf::Vector2f(i * BaseSize.x, (j + 1) * BaseSize.y);

			square[0].texCoords = sf::Vector2f(tu * BaseSize.x, tv * BaseSize.y);
			square[1].texCoords = sf::Vector2f((tu + 1) * BaseSize.x, tv * BaseSize.y);
			square[2].texCoords = sf::Vector2f((tu + 1) * BaseSize.x, (tv + 1) * BaseSize.y);
			square[3].texCoords = sf::Vector2f(tu * BaseSize.x, (tv + 1) * BaseSize.y);
		}
	}
	return true;
}


