#include "GSIntro.h"

GSIntro::GSIntro()
{
	m_curruntTime = 0.f;
	m_opacity = 255;
}

GSIntro::~GSIntro()
{
}

void GSIntro::Exit()
{
}

void GSIntro::Pause()
{
}

void GSIntro::Resume()
{
}

void GSIntro::Init()
{
	sf::Texture* texture = DATA->getTexture("LOGO XANH");
	std::printf("Intro\n");
	m_Logo.setTexture(*texture);
	m_Logo.setPosition(screenWidth / 2, screenHight / 2);
	m_Logo.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	DATA->getMusic("Intro")->play();
}

void GSIntro::Update(float deltaTime)
{
	m_curruntTime += deltaTime;
	if (m_curruntTime <= 5.f)
	{
		if (m_curruntTime <= 2.5f)
		{
			m_opacity = 255 * m_curruntTime / 2.5f;
		}
		else if (m_curruntTime <= 5.f)
		{
			m_opacity = 255 - 255 * m_curruntTime / 2.5f;
		}
		
	}
	else
	{
		GameStateMachine::GetInstance()->ChangeState(STATETYPES::MENU);
	}
	m_Logo.setColor(sf::Color(255, 255, 255, m_opacity));
}

void GSIntro::Render(sf::RenderWindow* window)
{
	// DATA->getSound("Intro")->play();
	window->draw(m_Logo);
}
