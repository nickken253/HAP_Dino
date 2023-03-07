#pragma once
#include "../GameManager/ResourceManager.h"
// #include "MapCollider.h"
#include "HitBox.h"

class TileMapBase : public sf::Drawable, public sf::Transformable
{
public:
	bool LoadBase(const sf::Texture* texture, sf::Vector2i BaseSize, std::vector<int> Tile, int Width, int Height);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		states.texture = &m_tileMapBase;
		target.draw(m_vertices, states);
	}
private:
	sf::VertexArray m_vertices;
	sf::Texture m_tileMapBase;
	// HitBox* m_wall;
	// std::list<HitBox*> m_listWall;
	// MapCollider* m_mapCollider;
};