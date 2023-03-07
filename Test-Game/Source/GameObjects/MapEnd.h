#pragma once
#include "MapManager.h"

class MapEnd : public MapManager
{
public:
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	bool IsWin() { return m_isWin; }
	sf::Vector2f getViewPosition() { return view.getCenter(); }
private:
	bool m_isWin;
	sf::Sprite m_preEnd;
	bool m_isEnded;
	float m_currentTime;
};