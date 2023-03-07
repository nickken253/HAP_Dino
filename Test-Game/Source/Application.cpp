#include "Application.h"
#include "GameStateManager/GameStateBase.h"

void Application::Run()
{
    Init();
    sf::Clock clock;
    float deltaTime = 0.f;  
    while (m_window->isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window->close();
        }
        Update(deltaTime);
        Render();
    }
}

Application::~Application()
{
	if (m_window != nullptr) delete m_window;
}

void Application::Init()
{
	m_window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHight), titleGame, sf::Style::Close);
    m_window->setFramerateLimit(60);
    m_window->setVerticalSyncEnabled(false);
    GSM->ChangeState(STATETYPES::INTRO);
    WConnect->setWindow(m_window);
}

void Application::Update(float deltaTime)
{
    OPERATOR->update(deltaTime);
    if (GameStateMachine::GetInstance()->NeedToChangeState())
    {
        GSM->PerformStateChange();
    }
    GSM->currentState()->Update(deltaTime);
}

void Application::Render()
{
    m_window->clear(sf::Color::White);
    // m_window->draw(m_sprite);
    GSM->currentState()->Render(m_window);
    m_window->display();
}
