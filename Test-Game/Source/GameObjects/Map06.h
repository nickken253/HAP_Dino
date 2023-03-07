#pragma once
#include "MapManager.h"

class Map06 : public MapManager
{
public:
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	bool IsWin() { return m_isWin; }
	sf::Vector2f getViewPosition() { return view.getCenter(); }
private:
	bool m_isWin;
};