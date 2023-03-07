#include "GSPlay.h"


GSPlay::GSPlay()
{
	view.setCenter(sf::Vector2f(0.0f, 0.0f));
	view.setSize(sf::Vector2f(ViewSizeWidht, ViewSizeHight));
}

GSPlay::~GSPlay()
{
}

void GSPlay::Exit()
{
}

void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}

void GSPlay::Init()
{
	std::printf("Play Game\n");
	// Player::LIVE = 3;
	GameButton* button;
	if(Player::LIVE == 3) OPERATOR->setStartCoin(Coin::COIN_COUNTING);
	DATA->getMusic("Menu")->stop();
	// INIT MAP
	
	switch (MapManager::LEVEL)
	{
	case 1:
		m_map = new Map01();
		m_map->Init();
		break;
	case 2:
		m_map = new Map02();
		m_map->Init();
		break;
	case 3:
		m_map = new Map03();
		m_map->Init();
		break;
	case 4:
		m_map = new Map04();
		m_map->Init();
		break;
	case 5:
		m_map = new Map05();
		m_map->Init();
		break;
	case 6:
		m_map = new Map06();
		m_map->Init();
		break;
	default:
		m_map = new MapEnd();
		m_map->Init();
		break;
	}
	m_map->getViewPosition();

	// Exit Button
	{
		button = new GameButton();
		button->Init("Pause2");
		button->setOnClick([]() {GSM->ChangeState(STATETYPES::PAUSE); DATA->playSound("Mouse/click"); });
		// button->setSize(sf::Vector2f(21, 22));
		// button->setScale(0.8, 0.8);
		// button->setSize(sf::Vector2f(21.0f, 22.0f));
		button->setPosition( (button->getSize() / 2.f).x, (button->getSize() / 2.f).y);
		button->setOrigin(button->getSize() / 2.f);
		button->setFillColor(sf::Color::Transparent);
		PauseBtn = button;
		m_listButton.push_back(button);
	}

	// COIN DECOR
	coinDecor.setTexture(*DATA->getTexture("Coin/coin"));
	coinDecor.setOrigin(coinDecor.getGlobalBounds().width / 2.f, coinDecor.getGlobalBounds().height / 2.f);
	// coinDecor.setScale(3, 3);
	coinDecor.setPosition(screenWidth - 50, 50);

	// COIN COUNTING
	m_coinCounting.setString(std::to_string(Coin::COIN_COUNTING));
	m_coinCounting.setFont(*DATA->getFont("PixelGameFont"));
	m_coinCounting.setOrigin(m_coinCounting.getGlobalBounds().width / 2.f, m_coinCounting.getGlobalBounds().height / 2.f);
	
	m_coinCounting.setScale(0.5, 0.5);
	m_coinCounting.setPosition(coinDecor.getPosition().x - 60, coinDecor.getPosition().y - 10);
	m_coinCounting.setOutlineColor(sf::Color::Black);
	m_coinCounting.setOutlineThickness(2);

	
	// 
	button2 = new GameButton();
	button2->Init("Pause2");
	button2->setScale(0.2f, 0.2f);
}

void GSPlay::Update(float deltaTime)
{
	if (MapManager::RESETMAP == true)
	{
		
		switch (MapManager::LEVEL)
		{
		case 1:
			m_map = new Map01();
			m_map->Init();
			break;
		case 2:
			m_map = new Map02();
			m_map->Init();
			break;
		case 3:
			m_map = new Map03();
			m_map->Init();
			break;
		case 4:
			m_map = new Map04();
			m_map->Init();
			break;
		case 5:
			m_map = new Map05();
			m_map->Init();
			break;
		case 6:
			m_map = new Map06();
			m_map->Init();
			break;
		default:
			m_map = new MapEnd();
			m_map->Init();
			break;
		}
		
		MapManager::RESETMAP = false;
	}
	m_map->Update(deltaTime);
	
	button2->setPosition(m_map->getViewPosition().x - ViewSizeWidht / 2 + button2->getSize().x / 10, m_map->getViewPosition().y - ViewSizeHight / 2 + button2->getSize().y / 10);
	for (auto btn : m_listButton)
	{
		btn->Update(deltaTime);
	}
	coinDecor.setPosition(m_map->getViewPosition().x + ViewSizeWidht / 2 - 15, m_map->getViewPosition().y - ViewSizeHight / 2 + 15);
	// COIN
	m_coinCounting.setString(std::to_string(Coin::COIN_COUNTING));
	m_coinCounting.setOrigin(m_coinCounting.getGlobalBounds().width / 2.f, m_coinCounting.getGlobalBounds().height / 2.f);
	m_coinCounting.setPosition(coinDecor.getPosition().x - 35, coinDecor.getPosition().y - 5);

	// LIVE
	for (int i = 0; i < 3; i++)
	{
		if (i + 1 <= Player::LIVE)
		{
			m_live[i].setTexture(DATA->getTexture("Heart/full2"));
		}
		else m_live[i].setTexture(DATA->getTexture("Heart/empty2"));
		// m_live[i].setOrigin()
		m_live[i].setSize(sf::Vector2f(20, 18));
		m_live[i].setOrigin(m_live[i].getSize() / 2.0f);
		m_live[i].setPosition(sf::Vector2f(m_map->getViewPosition().x + (i - 1) * 25, m_map->getViewPosition().y - ViewSizeHight / 2 + 15));
	}

	for (auto btn : m_listButton)
	{
		if (btn->getPosition().x - btn->getGlobalBounds().width / 2 + 192 <= sf::Mouse::getPosition().x && btn->getPosition().x + btn->getGlobalBounds().width / 2 + 192 >= sf::Mouse::getPosition().x && btn->getPosition().y - btn->getGlobalBounds().height / 2 + 192 <= sf::Mouse::getPosition().y && btn->getPosition().y + btn->getGlobalBounds().height / 2 + 192 >= sf::Mouse::getPosition().y)
		{
			if (btn->isPlaySound() == false)
			{
				btn->setPlaySound(true);
				DATA->playSound("Mouse/hover");

			}
			if (btn == PauseBtn)
			{
				button2->setTexture(DATA->getTexture("Buttons/Pause2_bold"));
			}
		}
		else
		{
			if (btn->isPlaySound() == true)
			{
				btn->setPlaySound(false);

			}
			if (btn == PauseBtn)
			{
				button2->setTexture(DATA->getTexture("Buttons/Pause2"));
			}
		}
		btn->Update(deltaTime);
	}
}

void GSPlay::Render(sf::RenderWindow* window)
{
	m_map->Render(window);
	window->draw(coinDecor);
	window->draw(m_coinCounting);
	button2->Render(window);
	for (auto it : m_live)
	{
		window->draw(it);
	}
	for (auto btn : m_listButton)
	{
		btn->Render(window);
	}
}
