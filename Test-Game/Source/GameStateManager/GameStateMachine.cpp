#include "GameStateMachine.h"
#include "GameStateBase.h"

GameStateMachine::GameStateMachine()
{
    m_activesState = nullptr;
    m_nextState = nullptr;
}

GameStateMachine::~GameStateMachine()
{
    while (!m_stateStack.empty())
    {
        delete m_stateStack.back();
        m_stateStack.pop_back();
    }
}

void GameStateMachine::ChangeState(GameStateBase* state)
{
    m_nextState = state;
}

void GameStateMachine::ChangeState(STATETYPES state)
{
    GameStateBase* gs = GameStateBase::createState(state);
    ChangeState(gs);
}

void GameStateMachine::PushState(STATETYPES state)
{
    GameStateBase* gs = GameStateBase::createState(state);
    if (!m_stateStack.empty())
    {
        m_stateStack.back()->Pause();
    }
    m_nextState = gs;
}

void GameStateMachine::PopState()
{
    if (!m_stateStack.empty())
    {
        m_stateStack.back()->Exit();
        m_stateStack.pop_back();
    }
    if (!m_stateStack.empty())
    {
        m_stateStack.back()->Resume();
    }
    m_activesState = m_stateStack.back();
}

void GameStateMachine::PerformStateChange()
{
    if (m_nextState != nullptr)
    {
        if (!m_stateStack.empty())
        {
            m_stateStack.back()->Exit();
        }
        m_stateStack.push_back(m_nextState);
        m_stateStack.back()->Init();
        m_activesState = m_nextState;
    }
    m_nextState = nullptr;
}

GameStateBase* GameStateMachine::currentState() const
{
    return m_activesState;
}

GameStateBase* GameStateMachine::nextState() const
{
    return m_nextState;
}

bool GameStateMachine::NeedToChangeState()
{
    return m_nextState != nullptr;
}

bool GameStateMachine::HasState()
{
    return m_stateStack.size() > 0;
}
