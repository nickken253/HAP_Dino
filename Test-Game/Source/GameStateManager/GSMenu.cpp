#include "GSMenu.h"

GSMenu::GSMenu()
{
}

GSMenu::~GSMenu()
{
}

void GSMenu::Exit()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}

void GSMenu::Init()
{
	std::printf("Open Menu\n");
	GameButton* button;
	m_isPlaySound = false;
	// Music
	{
		DATA->getMusic("Playing/play-1-10")->stop();
		DATA->playMusic("Menu");
	}
	// BUTTON
	{
		// Play Button
		{
			button = new GameButton();
			button->Init("Play");
			button->setOnClick([]() {GSM->ChangeState(STATETYPES::PLAY); DATA->playMusic("Playing/play-1-10"); DATA->getMusic("Playing/play-1-10")->setLoop(true); DATA->playSound("Mouse/click"); });
			button->setFillColor(sf::Color::Yellow);
			button->setPosition(screenWidth / 2 - screenWidth / 4.75, screenHight / 2 + screenHight / 4);
			button->setOrigin(button->getSize() / 2.f);
			// button->setScale(1.5f, 1.5f);
			m_listButton.push_back(button);
		}

		// Exit Button
		{
			button = new GameButton();
			button->Init("Close");
			button->setOnClick([]() {WConnect->getWindow()->close(); DATA->playSound("Mouse/click"); });
			// button->setFillColor(sf::Color(148, 33, 25));
			button->setPosition(screenWidth / 2 + screenWidth / 4.75, screenHight / 2 + screenHight / 4);
			button->setOrigin(button->getSize() / 2.f);
			m_listButton.push_back(button);
		}

		// Settings Button
		{
			button = new GameButton();
			button->Init("Settings");
			button->setOnClick([]() {GSM->ChangeState(STATETYPES::SETTING);  DATA->playSound("Mouse/click"); });
			button->setPosition(screenWidth / 2 - screenWidth / 8, screenHight / 2 + screenHight / 4);
			button->setOrigin(button->getSize() / 2.f);
			m_listButton.push_back(button);
		}

		// About Button
		{
			button = new GameButton();
			button->Init("About");
			button->setOnClick([]() {GSM->ChangeState(STATETYPES::ABOUT); DATA->playSound("Mouse/click"); });
			button->setPosition(screenWidth / 2 + screenWidth / 8, screenHight / 2 + screenHight / 4);
			button->setOrigin(button->getSize() / 2.f);
			m_listButton.push_back(button);
		}

		// Leaderboard Button
		{
			button = new GameButton();
			button->Init("Leaderboard");
			button->setOnClick([]() {GSM->ChangeState(STATETYPES::LEADERBOARD); DATA->playSound("Mouse/click"); });
			button->setPosition(screenWidth / 2 - screenWidth / 24, screenHight / 2 + screenHight / 4);
			button->setOrigin(button->getSize() / 2.f);
			m_listButton.push_back(button);
		}

		// Achievements Button
		{
			button = new GameButton();
			button->Init("Help");
			button->setOnClick([]() {GSM->ChangeState(STATETYPES::TUTORIAL);  DATA->playSound("Mouse/click"); });
			button->setPosition(screenWidth / 2 + screenWidth / 24, screenHight / 2 + screenHight / 4);
			button->setOrigin(button->getSize() / 2.f);
			m_listButton.push_back(button);
		}
	}

	// Background
	{
		sf::Texture* texture = DATA->getTexture("Background Layers/Hills Layer 01");
		m_background.setTexture(*texture);
		m_background.setScale(ScaleBG, ScaleBG);
		m_background.setPosition(screenWidth / 2, screenHight / 2);
		m_background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
		m_parallelBG.Init();
	}

	// Title
	{
		sf::Texture* titleTexture = DATA->getTexture("Background Layers/Game Title");
		m_gameTitle.setTexture(*titleTexture);
		m_gameTitle.setScale(ScaleBG, ScaleBG);
		m_gameTitle.setPosition(screenWidth / 2, screenHight / 2);
		m_gameTitle.setOrigin((sf::Vector2f)titleTexture->getSize() / 2.f);
	}

	// HIGH SCORE
	{
		HSM->readFile();
	}
}

void GSMenu::Update(float deltaTime)
{
	m_parallelBG.Update(deltaTime);
	for (auto btn : m_listButton)
	{
		if (btn->getPosition().x - btn->getGlobalBounds().width / 2 + 192 <= sf::Mouse::getPosition().x && btn->getPosition().x + btn->getGlobalBounds().width / 2 + 192 >= sf::Mouse::getPosition().x && btn->getPosition().y - btn->getGlobalBounds().height / 2 + 192 <= sf::Mouse::getPosition().y && btn->getPosition().y + btn->getGlobalBounds().height / 2 + 192 >= sf::Mouse::getPosition().y)
		{
			if (btn->isPlaySound() == false)
			{
				btn->setPlaySound(true);
				DATA->playSound("Mouse/hover");
				
			}
			btn->BrightTexture(btn->getName());
		}
		else
		{
			if (btn->isPlaySound() == true)
			{
				btn->setPlaySound(false);
				// DATA->playSound("Mouse/hover");

			}
			btn->NormalTexture(btn->getName());
		}
		btn -> Update(deltaTime);
	}
}

void GSMenu::Render(sf::RenderWindow* window)
{
	window->draw(m_background);
	window->setView(window->getDefaultView());
	m_parallelBG.Render(window);
	window->draw(m_gameTitle);
	for (auto btn : m_listButton)
	{
		//btn->setScale(5, 5);
		btn -> Render(window);
	}
}
