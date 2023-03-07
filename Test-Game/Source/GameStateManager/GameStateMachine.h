#pragma once
#include "../GameManager/Singleton.h"
#include <list>
#include "../GameManager/HighScoreManager.h"
#define GSM GameStateMachine::GetInstance()
class GameStateBase;

enum STATETYPES
{
	INVALID = 0,
	INTRO,
	MENU,
	PLAY,
	END,
	ABOUT,
	SETTING,
	LEADERBOARD,
	TUTORIAL,
	PAUSE,

};
class GameStateMachine : public CSingleton<GameStateMachine>
{
public:
	GameStateMachine();
	~GameStateMachine();

	void ChangeState(GameStateBase* state);
	void ChangeState(STATETYPES state);
	void PushState(STATETYPES state);
	void PopState();

	void PerformStateChange();

	GameStateBase* currentState() const;
	GameStateBase* nextState() const;

	bool NeedToChangeState();
	bool HasState();

private:
	std::list<GameStateBase*> m_stateStack;
	GameStateBase* m_activesState;
	GameStateBase* m_nextState;
};
