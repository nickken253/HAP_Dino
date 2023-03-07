#pragma once
#include "../GameManager/ResourceManager.h"

class Layer
{
public:
	void Init(std::string name, float speed);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void setPosition(sf::Vector2i pos);
private:
	sf::Sprite m_image1;
	sf::Sprite m_image2;
	float m_speed;

	sf::Vector2i m_sizeImage;
};
