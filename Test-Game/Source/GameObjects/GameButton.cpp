#include "GameButton.h"

GameButton::GameButton()
{
	m_isHanding = false;
	m_isPlaySound = false;
}

GameButton::~GameButton()
{
}

void GameButton::Init(std::string name)
{
	m_name = name;
	this->setTexture(DATA->getTexture("Buttons/" + name));
	this->setSize(sf::Vector2f(95, 100));
}
void GameButton::BrightTexture(std::string name)
{
	//if (name == "Volume_on") name = "Volume_off";
	this->setTexture(DATA->getTexture("Buttons/" + name + "2"));
}
void GameButton::NormalTexture(std::string name)
{
	//if (name == "Volume_on2") name = "Volume_off2";
	this->setTexture(DATA->getTexture("Buttons/" + name));
}
std::string GameButton::getName()
{
	return m_name;
}
void GameButton::Update(float deltaTime)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && OPERATOR->allowClickMouse() == true)
	{
		HandleTouchEvent();
	}
}

void GameButton::Render(sf::RenderWindow* window)
{
	window->draw(*this);
}

void GameButton::HandleTouchEvent()
{
	m_isHanding = false;
	if (this->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow())))
	{
		m_buttonClickFunc();
		m_isHanding = true;
		OPERATOR->setClick();
	}
}

bool GameButton::isHandle()
{
	return m_isHanding;
}

void GameButton::setOnClick(void(*Func)())
{
	m_buttonClickFunc = Func;
}
