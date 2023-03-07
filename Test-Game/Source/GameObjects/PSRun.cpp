#include "PSRun.h"
#include "Player.h"

PSRun::PSRun(IPlayer* player)
{
	m_player = player;
	m_turnRight = Player::ISTURNRIGHT;
	m_isMove = Player::ISMOVE;
}

void PSRun::Init()
{
	m_animation = new Animation(*DATA->getTexture("Character/run"), sf::Vector2i(6, 1), 0.06f);
	//m_sound = DATA->getSound("Player/run");

	//m_sound->setVolume(20);

}

void PSRun::Update(float deltaTime)
{
	// m_isMove = Player::ISMOVE;
	
	m_animation->Update(deltaTime);
	if (m_player->getHitBox()->getDirection() == DIRECTION::DNULL)
	{
		//m_sound->stop();
		DATA->getSound("Player/run")->stop();
		m_isPlayed = false;
		m_player->changeNextState(FALL);
	}
	// JUMP
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		//m_sound->stop();
		DATA->getSound("Player/run")->stop();
		m_isPlayed = false;
		m_player->changeNextState(JUMP);
	}
	// FLOAT
	if (m_player->getHitBox()->getDirection() == DIRECTION::INSIDE)
	{
		// m_sound->stop();
		DATA->getSound("Player/run")->stop();
		m_isPlayed = false;
		m_player->changeNextState(FLOAT);
	}
	// MOVE or STAND
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		
		if (Player::ISTURNRIGHT)
		{
			Player::ISTURNRIGHT = false;
		}
		if (Player::ISMOVE)
		{
			if (!m_isPlayed)
			{
				// m_sound->play();
				DATA->playSound("Player/run");
				m_isPlayed = true;
			}
			m_player->getHitBox()->move(-m_player->getHitBox()->getVelocity().x * deltaTime, 0);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (!m_isPlayed)
		{
			// m_sound->play();
			DATA->playSound("Player/run");
			m_isPlayed = true;
		}

		if (Player::ISTURNRIGHT == false)
		{
			Player::ISTURNRIGHT = true;
		}
		if (Player::ISMOVE)
		{
			m_player->getHitBox()->move(m_player->getHitBox()->getVelocity().x * deltaTime, 0);
			if (!m_isPlayed)
			{
				DATA->playSound("Player/run");
				// m_sound->play();
				m_isPlayed = true;
			}
		}
	}
	else
	{
		DATA->getSound("Player/run")->stop();
		// m_sound->stop();
		m_isPlayed = false;
		m_player->changeNextState(IDLE);
	}
	if (!m_player->getHitBox()->isAlive()) m_player->changeNextState(IPState::DEATH);
	m_animation->setPosition(m_player->getHitBox()->getPosition());
}

void PSRun::Render(sf::RenderWindow* window)
{
	if (Player::ISTURNRIGHT) m_animation->setScale(ScaleCharacter, ScaleCharacter);
	else m_animation->setScale(-ScaleCharacter, ScaleCharacter);
	window->draw(*m_animation);
}
