#include "GSPause.h"

GSPause::GSPause()
{
}

GSPause::~GSPause()
{
}

void GSPause::Exit()
{
}

void GSPause::Pause()
{
}

void GSPause::Resume()
{
}

void GSPause::Init()
{
	std::printf("Pause\n");
	GameButton* button;

	// Back Button
	button = new GameButton();
	button->Init("Back");
	button->setOnClick([]() {GSM->PopState();  DATA->playSound("Mouse/click"); });
	button->setScale(0.8, 0.8);
	button->setPosition(screenWidth - (button->getSize() / 2.f ).x, (button->getSize() / 2.f).y);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	// Settings Button
	button = new GameButton();
	button->Init("Settings");
	button->setOnClick([]() { GSM->ChangeState(STATETYPES::SETTING); DATA->playSound("Mouse/click"); });
	button->setPosition(screenWidth / 2 - screenWidth / 24, screenHight / 2);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	// Home Button
	button = new GameButton();
	button->Init("Menu");
	button->setOnClick([]() { GSM->PopState(); GSM->PopState(); DATA->playSound("Mouse/click"); DATA->playMusic("Menu");  DATA->getMusic("Playing/play-1-10")->stop(); MapManager::LEVEL = 1; Player::LIVE = 3; });
	button->setPosition(screenWidth / 2 + screenWidth / 24, screenHight / 2);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	// Restart Button
	button = new GameButton();
	button->Init("Restart");
	button->setOnClick([]() { GSM->PopState(); GSM->PopState(); GSM->ChangeState(STATETYPES::PLAY); DATA->playSound("Mouse/click"); });
	button->setPosition(screenWidth / 2 - screenWidth / 8, screenHight / 2);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	// Help Button
	button = new GameButton();
	button->Init("Help");
	button->setOnClick([]() { GSM->ChangeState(STATETYPES::TUTORIAL); DATA->playSound("Mouse/click"); });
	button->setPosition(screenWidth / 2 + screenWidth / 8, screenHight / 2);
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
	sf::Texture* boardTexture = DATA->getTexture("Background Layers/Pause");
	m_board.setTexture(*boardTexture);
	m_board.setScale(ScaleBG, ScaleBG);
	m_board.setPosition(screenWidth / 2, screenHight / 2);
	m_board.setOrigin((sf::Vector2f)boardTexture->getSize() / 2.f);
}

void GSPause::Update(float deltaTime)
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
			}
			btn->NormalTexture(btn->getName());
		}
		btn->Update(deltaTime);
	}
}

void GSPause::Render(sf::RenderWindow* window)
{
	window->setView(window->getDefaultView());
	window->draw(m_background);
	m_parallelBG.Render(window);
	window->draw(m_board);
	for (auto btn : m_listButton)
	{
		btn->Render(window);
	}
}
