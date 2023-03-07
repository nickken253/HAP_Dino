#include "GSSettings.h"

GSSettings::GSSettings()
{
}

GSSettings::~GSSettings()
{
}

void GSSettings::Exit()
{
}

void GSSettings::Pause()
{
}

void GSSettings::Resume()
{
}

void GSSettings::Init()
{
	std::printf("Settings\n");
	GameButton* button;

	// Exit Button
	button = new GameButton();
	button->Init("Back");
	button->setOnClick([]() 
		{
			GSM->PopState();  
			DATA->playSound("Mouse/click"); 
		});
	button->setScale(0.8, 0.8);
	button->setPosition(screenWidth - (button->getSize() / 2.f ).x, (button->getSize() / 2.f).y);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	// Music Button
	button = new GameButton();
	button->Init("Volume_on");
	button->setOnClick([]() 
		{ 
			DATA->setAllowMusic(!DATA->getAllowMusic());
			if (DATA->getAllowMusic()) 
			{ 
				DATA->getMusic("Menu")->setVolume(100); 
				DATA->getMusic("Playing/play-1-10")->setVolume(100);
			} 
			else
			{
				DATA->getMusic("Menu")->setVolume(0);
				DATA->getMusic("Playing/play-1-10")->setVolume(0);
			}
			DATA->playSound("Mouse/click"); 
		});
	button->setScale(0.8, 0.8);
	// button->setPosition(screenWidth / 2 - screenWidth / 4.5, screenHight / 2 - screenHight / 5);
	button->setPosition(screenWidth / 2 - screenWidth / 12, screenHight / 2 + screenHight / 8);
	button->setOrigin(button->getSize() / 2.f);
	m_musicBtn = button;
	m_listButton.push_back(button);

	// Sound Button
	button = new GameButton();
	button->Init("Sound_on");
	button->setOnClick([]() 
		{ 
			DATA->setAllowSound(!DATA->getAllowSound()); 
			DATA->playSound("Mouse/click"); 
		});
	button->setScale(0.8, 0.8);
	//button->setPosition(screenWidth / 2 - screenWidth / 4.5, screenHight / 2 - screenHight / 10);
	button->setPosition(screenWidth / 2 + screenWidth / 12, screenHight / 2 + screenHight / 8);
	button->setOrigin(button->getSize() / 2.f);
	m_soundBtn = button;
	m_listButton.push_back(button);

	// BackGround
	sf::Texture* texture = DATA->getTexture("Background Layers/Hills Layer 01");
	m_background.setTexture(*texture);
	m_background.setScale(3, 3);
	m_background.setPosition(screenWidth / 2, screenHight / 2);
	m_background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_parallelBG.Init();

	// Title
	sf::Texture* boardTexture = DATA->getTexture("Background Layers/Settings_mini");
	m_board.setTexture(*boardTexture);
	m_board.setScale(ScaleBG, ScaleBG);
	m_board.setPosition(screenWidth / 2, screenHight / 2);
	m_board.setOrigin((sf::Vector2f)boardTexture->getSize() / 2.f);

	// TEXT
	m_sound.setString("SOUND: ON");
	m_sound.setFont(*DATA->getFont("PixelGameFont"));
	m_sound.setOrigin(m_sound.getGlobalBounds().width / 2.f, m_sound.getGlobalBounds().height / 2.f);
	m_sound.setScale(1.5, 1.5);
	m_sound.setPosition(screenWidth / 2, screenHight / 2 - screenHight / 12);
	m_sound.setOutlineColor(sf::Color::Black);
	m_sound.setOutlineThickness(1);

	m_music.setString("MUSIC: ON");
	m_music.setFont(*DATA->getFont("PixelGameFont"));
	m_music.setOrigin(m_music.getGlobalBounds().width / 2.f, m_music.getGlobalBounds().height / 2.f);
	m_music.setScale(1.5, 1.5);
	m_music.setPosition(screenWidth / 2, screenHight / 2 - screenHight / 6);
	m_music.setOutlineColor(sf::Color::Black);
	m_music.setOutlineThickness(1);
}

void GSSettings::Update(float deltaTime)
{
	m_parallelBG.Update(deltaTime);
	if (DATA->getAllowMusic())
	{
		m_music.setString("MUSIC: ON");
		if (m_musicBtn->getPosition().x - m_musicBtn->getGlobalBounds().width / 2 + 192 <= sf::Mouse::getPosition().x && m_musicBtn->getPosition().x + m_musicBtn->getGlobalBounds().width / 2 + 192 >= sf::Mouse::getPosition().x && m_musicBtn->getPosition().y - m_musicBtn->getGlobalBounds().height / 2 + 192 <= sf::Mouse::getPosition().y && m_musicBtn->getPosition().y + m_musicBtn->getGlobalBounds().height / 2 + 192 >= sf::Mouse::getPosition().y)
		{
			m_musicBtn->setTexture(DATA->getTexture("Buttons/Volume_on2"));
		}
		else m_musicBtn->setTexture(DATA->getTexture("Buttons/Volume_on"));
	}
	else
	{
		m_music.setString("MUSIC: OFF");
		if (m_musicBtn->getPosition().x - m_musicBtn->getGlobalBounds().width / 2 + 192 <= sf::Mouse::getPosition().x && m_musicBtn->getPosition().x + m_musicBtn->getGlobalBounds().width / 2 + 192 >= sf::Mouse::getPosition().x && m_musicBtn->getPosition().y - m_musicBtn->getGlobalBounds().height / 2 + 192 <= sf::Mouse::getPosition().y && m_musicBtn->getPosition().y + m_musicBtn->getGlobalBounds().height / 2 + 192 >= sf::Mouse::getPosition().y)
		{
			m_musicBtn->setTexture(DATA->getTexture("Buttons/Volume_off2"));
		}
		else m_musicBtn->setTexture(DATA->getTexture("Buttons/Volume_off"));
	}
	if (DATA->getAllowSound())
	{
		m_sound.setString("SOUND: ON");
		if (m_soundBtn->getPosition().x - m_soundBtn->getGlobalBounds().width / 2 + 192 <= sf::Mouse::getPosition().x && m_soundBtn->getPosition().x + m_soundBtn->getGlobalBounds().width / 2 + 192 >= sf::Mouse::getPosition().x && m_soundBtn->getPosition().y - m_soundBtn->getGlobalBounds().height / 2 + 192 <= sf::Mouse::getPosition().y && m_soundBtn->getPosition().y + m_soundBtn->getGlobalBounds().height / 2 + 192 >= sf::Mouse::getPosition().y)
		{
			m_soundBtn->setTexture(DATA->getTexture("Buttons/Sound_on2"));
		}
		else m_soundBtn->setTexture(DATA->getTexture("Buttons/Sound_on"));
	}
	else
	{
		m_sound.setString("SOUND: OFF");
		if (m_soundBtn->getPosition().x - m_soundBtn->getGlobalBounds().width / 2 + 192 <= sf::Mouse::getPosition().x && m_soundBtn->getPosition().x + m_soundBtn->getGlobalBounds().width / 2 + 192 >= sf::Mouse::getPosition().x && m_soundBtn->getPosition().y - m_soundBtn->getGlobalBounds().height / 2 + 192 <= sf::Mouse::getPosition().y && m_soundBtn->getPosition().y + m_soundBtn->getGlobalBounds().height / 2 + 192 >= sf::Mouse::getPosition().y)
		{
			m_soundBtn->setTexture(DATA->getTexture("Buttons/Sound_off2"));
		}
		else m_soundBtn->setTexture(DATA->getTexture("Buttons/Sound_off"));
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
		}
		else
		{
			if (btn->isPlaySound() == true)
			{
				btn->setPlaySound(false);
			}
		}
		if (btn != m_musicBtn && btn != m_soundBtn)
		{
			if (btn->getPosition().x - btn->getGlobalBounds().width / 2 + 192 <= sf::Mouse::getPosition().x && btn->getPosition().x + btn->getGlobalBounds().width / 2 + 192 >= sf::Mouse::getPosition().x && btn->getPosition().y - btn->getGlobalBounds().height / 2 + 192 <= sf::Mouse::getPosition().y && btn->getPosition().y + btn->getGlobalBounds().height / 2 + 192 >= sf::Mouse::getPosition().y)
			{
				btn->BrightTexture(btn->getName());
			}
			else btn->NormalTexture(btn->getName());
		}
		btn->Update(deltaTime);
	}
}

void GSSettings::Render(sf::RenderWindow* window)
{
	window->draw(m_background);
	m_parallelBG.Render(window);
	window->draw(m_board);
	window->draw(m_sound);
	window->draw(m_music);
	for (auto btn : m_listButton)
	{
		btn->Render(window);
	}
}
