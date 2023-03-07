#include "Player.h"
#include "PSRun.h"
#include "PSJump.h"
#include "PSDead.h"
#include "PSIdle.h"
#include "PSFall.h"
#include "PSFloat.h"
#include "PSGoin.h"

Player::Player()
{
	m_nextState = IPState::SNULL;

	m_runState = new PSRun(this);
	m_jumpState = new PSJump(this);
	m_fallState = new PSFall(this);
	m_deathState = new PSDead(this);
	m_launchState;
	m_idleState = new PSIdle(this);
	m_goinState = new PSGoin(this);
	m_winningState;
	m_floatState = new PSFloat(this);
	
	m_currentState = m_fallState;
}
bool Player::ISTURNRIGHT = true;
bool Player::ISMOVE = true;
int Player::LIVE = 3;
Player::~Player()
{
	if (m_runState != nullptr)
	{
		delete m_runState;
	}
	if (m_jumpState != nullptr)
	{
		delete m_jumpState;
	}
	if (m_fallState != nullptr)
	{
		delete m_fallState;
	}
	if (m_deathState != nullptr)
	{
		delete m_deathState;
	}
	if (m_launchState != nullptr)
	{
		delete m_launchState;
	}
	if (m_snullState != nullptr)
	{
		delete m_snullState;
	}
	if (m_idleState != nullptr)
	{
		delete m_idleState;
	}
	if (m_goinState != nullptr)
	{
		delete m_goinState;
	}
	if (m_winningState != nullptr)
	{
		delete m_winningState;
	}
	if (m_floatState != nullptr)
	{
		delete m_winningState;
	}
}

void Player::changeNextState(IPState::STATE nextState)
{
	m_nextState = nextState;
}

void Player::Init(sf::Vector2f position)
{
	m_position = position;
	m_runState->Init();
	m_jumpState->Init();
	m_fallState->Init();
	m_deathState->Init();
	m_idleState->Init();
	m_floatState->Init();
	m_goinState->Init();

	/*
	m_launchState->Init();
	m_snullState->Init();
	m_landingState->Init();
	*/

	m_hitBox = new HitBox(sf::Vector2i(10 * ScaleCharacter, 16 * ScaleCharacter));
	m_hitBox->setPosition(m_position);
	m_hitBox->Init(sf::Vector2f(PRunVelocity, PJumpVelocity));
	m_hitBox->setTag(PLAYER);
}

void Player::Update(float deltaTime)
{
	performStateChange();
	m_currentState->Update(deltaTime);
}

void Player::Render(sf::RenderWindow* window)
{
	m_currentState->Render(window);
	window->draw(*m_hitBox);
}

HitBox* Player::getHitBox()
{
	return m_hitBox;
}

void Player::performStateChange()
{
	if (m_nextState != IPState::SNULL)
	{
		switch (m_nextState)
		{
		case IPState::RUN:
			m_currentState = m_runState;
			break;
		case IPState::JUMP:
			m_currentState = m_jumpState;
			break;
		case IPState::FALL:
			m_currentState = m_fallState;
			break;
		case IPState::WINNING:
			m_currentState = m_winningState;
			break;
		case IPState::DEATH:
			m_currentState = m_deathState;
			break;
		case IPState::LAUNCH:
			m_currentState = m_launchState;
			break;
		case IPState::IDLE:
			m_currentState = m_idleState;
			break;
		case IPState::GOIN:
			m_currentState = m_goinState;
			break;
		case IPState::FLOAT:
			m_currentState = m_floatState;
			break;
		default:
			break;
		}
		m_nextState = IPState::SNULL;
		m_currentState->getAnimation()->Reset();
	}
}
