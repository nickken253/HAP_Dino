#pragma once
#include <SFML/Graphics.hpp>
#include "../GameManager/WindowConnector.h"
#include "../GameManager/ResourceManager.h"
#include "../GameManager/OperationsManager.h"

class GameButton : public sf::RectangleShape
{
public:
	GameButton();
	~GameButton();

	void Init(std::string name);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void BrightTexture(std::string name);
	void NormalTexture(std::string name);
	std::string getName();
	void HandleTouchEvent();
	bool isHandle();
	bool isPlaySound(){ return m_isPlaySound; }
	void setPlaySound(bool isPlayed) { m_isPlaySound = isPlayed; }
	void setOnClick(void (*Func)());
private:
	void (*m_buttonClickFunc)();
	bool m_isHanding;
	std::string m_name;
	bool m_isPlaySound;
};