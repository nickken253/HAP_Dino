#include "Layer.h"

void Layer::Init(std::string name, float speed)
{
	sf::Texture* texture = DATA->getTexture(name);
	m_sizeImage = (sf::Vector2i)texture->getSize();
	m_speed = speed;

	m_image1.setTexture(*texture);
	m_image1.setScale(ScaleBG, ScaleBG);
	m_image1.setOrigin((sf::Vector2f)m_sizeImage/ 2.f);
	m_image1.setPosition(sf::Vector2f(screenWidth / 2, screenHight / 2));
	

	m_image2.setTexture(*texture);
	m_image2.setScale(ScaleBG, ScaleBG);
	m_image2.setOrigin((sf::Vector2f)m_sizeImage / 2.f);
	m_image2.setPosition(screenWidth * 1.5, m_image1.getPosition().y);
}

void Layer::Update(float deltaTime)
{
	m_image1.move(-m_speed * deltaTime, 0);
	m_image2.move(-m_speed * deltaTime, 0);

	if (m_image2.getPosition().x <= (float)screenWidth / 2)
	{
		int delta = (float)screenWidth / 2 - m_image2.getPosition().x;
		m_image1.setPosition(sf::Vector2f(screenWidth / 2 + delta, screenHight / 2));
		m_image2.setPosition(screenWidth * 1.5 + delta, m_image1.getPosition().y);
	}
}

void Layer::Render(sf::RenderWindow* window)
{
	window->draw(m_image1);
	window->draw(m_image2);
}

void Layer::setPosition(sf::Vector2i pos)
{
	//m_image1.setPosition((sf::Vector2f)pos);
	//m_image2.setPosition(pos.x + m_sizeImage.x, pos.y);
}
