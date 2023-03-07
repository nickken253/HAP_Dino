#include "GSAbout.h"

GSAbout::GSAbout()
{
}

GSAbout::~GSAbout()
{
}

void GSAbout::Exit()
{
}

void GSAbout::Pause()
{
}

void GSAbout::Resume()
{
}

void GSAbout::Init()
{
	std::printf("About\n");
	GameButton* button;

	// Exit Button
	button = new GameButton();
	button->Init("Back");
	button->setOnClick([]() {GSM->PopState(); DATA->playSound("Mouse/click"); });
	button->setScale(0.8, 0.8);
	button->setPosition(screenWidth - (button->getSize() / 2.f).x, (button->getSize() / 2.f).y);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	// BackGround
	sf::Texture* texture = DATA->getTexture("Background Layers/Hills Layer 01");
	m_background.setTexture(*texture);
	m_background.setScale(3, 3);
	m_background.setPosition(screenWidth / 2, screenHight / 2);
	m_background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_parallelBG.Init();

	// Title
	sf::Texture* boardTexture = DATA->getTexture("Background Layers/About");
	m_board.setTexture(*boardTexture);
	m_board.setScale(ScaleBG, ScaleBG);
	m_board.setPosition(screenWidth / 2, screenHight / 2);
	m_board.setOrigin((sf::Vector2f)boardTexture->getSize() / 2.f);
	
}

void GSAbout::Update(float deltaTime)
{
	m_parallelBG.Update(deltaTime);
	for (auto btn : m_listButton)
	{
		if (btn->getPosition().x - btn->getGlobalBounds().width / 2 + 192 <= sf::Mouse::getPosition().x && btn->getPosition().x + btn->getGlobalBounds().width / 2 + 192 >= sf::Mouse::getPosition().x && btn->getPosition().y - btn->getGlobalBounds().height / 2 + 192 <= sf::Mouse::getPosition().y && btn->getPosition().y + btn->getGlobalBounds().height / 2 + 192 >= sf::Mouse::getPosition().y)
		{
			btn->BrightTexture(btn->getName());
		}
		else btn->NormalTexture(btn->getName());
		btn->Update(deltaTime);
	}
}

void GSAbout::Render(sf::RenderWindow* window)
{
	
	window->draw(m_background);
	m_parallelBG.Render(window);
	window->draw(m_board);
	for (auto btn : m_listButton)
	{
		btn->Render(window);
	}
}
