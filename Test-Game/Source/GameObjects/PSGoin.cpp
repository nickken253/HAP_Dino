#include "PSGoin.h"
#include "Player.h"

PSGoin::PSGoin(IPlayer* player)
{
	m_player = player;
	m_isMove = Player::ISMOVE;
}

void PSGoin::Init()
{
	m_animation = new Animation(*DATA->getTexture("Character/goin"), sf::Vector2i(8, 1), 0.2f);
	m_animation->setModeEndFrame(true);
}

void PSGoin::Update(float deltaTime)
{
	// m_isMove = Player::ISMOVE;
	if (m_animation->getCurrentFrame().x != m_animation->getFrameNum().x - 1)
	{
	}
	else
	{
		//m_player->changeNextState(STATE::IDLE);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_player->changeNextState(STATE::RUN);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_player->changeNextState(STATE::RUN);
	}
	m_animation->Update(deltaTime);
	m_animation->setPosition(m_player->getHitBox()->getPosition());
	// m_animation->setPosition(m_player->getHitBox()->getPosition());
}

void PSGoin::Render(sf::RenderWindow* window)
{
	if (Player::ISTURNRIGHT) m_animation->setScale(ScaleCharacter, ScaleCharacter);
	else m_animation->setScale(-ScaleCharacter, ScaleCharacter);
	window->draw(*m_animation);
}
