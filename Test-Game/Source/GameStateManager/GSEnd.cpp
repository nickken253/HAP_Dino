#include "GSEnd.h"
#define POINT MapManager::LEVEL * LevelPoint + (Coin::COIN_COUNTING - OPERATOR->getStartCoin()) * CoinPoint
GSEnd::GSEnd()
{
}

GSEnd::~GSEnd()
{
}

void GSEnd::Exit()
{
}

void GSEnd::Pause()
{
}

void GSEnd::Resume()
{
}

void GSEnd::Init()
{
	std::printf("End\n");
	m_isPlayed = false;
	m_isBest = false;
	GameButton* button;
	m_tmpCoin = 0;
	m_tmpLevel = 0;
	m_tmpTotal = 0;
	m_currentTime = 0;
	// Home Button
	button = new GameButton();
	button->Init("Menu");
	button->setOnClick([]() 
		{ 
			GSM->PopState(); 
			GSM->PopState(); 
			DATA->playSound("Mouse/click");
			DATA->playMusic("Menu");  
			DATA->getMusic("Sad_ending")->stop(); 
			DATA->getMusic("Happy_ending")->stop();
			MapManager::LEVEL = 1; 
			Player::LIVE = 3;
			HSM->UpdateHighScore();
			HSM->writeFile();
		});
	button->setPosition(screenWidth / 2, screenHight / 2 + screenHight / 4.5);
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
	sf::Texture* boardTexture = DATA->getTexture("Background Layers/End");
	m_board.setTexture(*boardTexture);
	m_board.setScale(ScaleBG, ScaleBG);
	m_board.setPosition(screenWidth / 2, screenHight / 2);
	m_board.setOrigin((sf::Vector2f)boardTexture->getSize() / 2.f);

	// COIN COUNTING
	m_coinCounting.setString(std::to_string(0));
	m_coinCounting.setFont(*DATA->getFont("PixelGameFont"));
	m_coinCounting.setOrigin(m_coinCounting.getGlobalBounds().width / 2.f, m_coinCounting.getGlobalBounds().height / 2.f);
	m_coinCounting.setScale(1.5, 1.5);
	m_coinCounting.setPosition(screenWidth / 2 + screenWidth / 24, screenHight / 2 - screenHight / 9);
	m_coinCounting.setOutlineColor(sf::Color::Black);
	m_coinCounting.setOutlineThickness(1);

	// LEVEL
	m_level.setString(std::to_string(0));
	m_level.setFont(*DATA->getFont("PixelGameFont"));
	m_level.setOrigin(m_level.getGlobalBounds().width / 2.f, m_level.getGlobalBounds().height / 2.f);
	m_level.setScale(1.5, 1.5);
	m_level.setPosition(screenWidth / 2 + screenWidth / 24, screenHight / 2 - screenHight / 5);
	m_level.setOutlineColor(sf::Color::Black);
	m_level.setOutlineThickness(1);

	// TOTAL
	m_total.setString(std::to_string(0));
	m_total.setFont(*DATA->getFont("PixelGameFont"));
	m_total.setOrigin(m_total.getGlobalBounds().width / 2.f, m_total.getGlobalBounds().height / 2.f);
	m_total.setScale(1.5, 1.5);
	m_total.setPosition(screenWidth / 2 + screenWidth / 24, screenHight / 2 + screenHight / 14);
	m_total.setOutlineColor(sf::Color::Black);
	m_total.setOutlineThickness(1);

	HSM->setCurrentScore(POINT);
}

void GSEnd::Update(float deltaTime)
{
	m_parallelBG.Update(deltaTime);
	m_currentTime += deltaTime;
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
	/*m_coinCounting.setOrigin(m_coinCounting.getGlobalBounds().width / 2.f, m_coinCounting.getGlobalBounds().height / 2.f);
	m_level.setOrigin(m_level.getGlobalBounds().width / 2.f, m_level.getGlobalBounds().height / 2.f);
	m_total.setOrigin(m_total.getGlobalBounds().width / 2.f, m_total.getGlobalBounds().height / 2.f);*/
	if (m_currentTime >= 1.0f)
	{
		if (m_tmpLevel < MapManager::LEVEL)
		{
			m_tmpLevel++;
		}
		else
		{
			
			if (m_currentTime >= 2.5f)
			{
				
				if (m_tmpCoin < (Coin::COIN_COUNTING - OPERATOR->getStartCoin()))
				{
					m_tmpCoin++;
				}
			}
		}
	}
	Total = m_tmpLevel * LevelPoint + m_tmpCoin * CoinPoint;
	if (m_tmpTotal < Total)
	{
		m_tmpTotal++;
		if (m_tmpTotal != 0 && m_isPlayed == false)
		{
			DATA->playSound("Counting");
			DATA->getSound("Counting")->setLoop(true);
			m_isPlayed = true;
		}
	}
	else
	{
		DATA->getSound("Counting")->stop();
		m_isPlayed = false;
	}
	m_level.setString(std::to_string(m_tmpLevel));
	m_coinCounting.setString(std::to_string(m_tmpCoin));
	m_total.setString(std::to_string(m_tmpTotal));
	if (m_tmpTotal % 100 == 0 && m_tmpTotal != 0)
	{
		m_total.setScale(1.75, 1.75);
		m_total.setFillColor(sf::Color::Yellow);
	}
	else
	{
		m_total.setScale(1.5, 1.5);
		m_total.setFillColor(sf::Color::White);
	}
	if (m_tmpTotal == POINT && POINT > HSM->getBestScore())
	{
		if (m_isBest == false)
		{
			DATA->playSound("NewHighScore");
			m_isBest = true;
		}
		m_board.setTexture(*DATA->getTexture("Background Layers/End with High Score"));
	}
}

void GSEnd::Render(sf::RenderWindow* window)
{
	window->setView(window->getDefaultView());
	window->draw(m_background);
	m_parallelBG.Render(window);
	window->draw(m_board);
	window->draw(m_coinCounting);
	window->draw(m_level);
	window->draw(m_total);
	for (auto btn : m_listButton)
	{
		btn->Render(window);
	}
}
