#include "GameStateBase.h"
#include "GSIntro.h"
#include "GSMenu.h"
#include "GSPlay.h"
#include "GSEnd.h"
#include "GSAbout.h"
#include "GSLeaderBoard.h"
#include "GSSettings.h"
#include "GSTutorial.h"
#include "GSPause.h"

GameStateBase* GameStateBase::createState(STATETYPES state)
{
	GameStateBase* gs = nullptr;
	switch (state)
	{
	case INVALID:
		break;
	case INTRO:
		gs = new GSIntro();
		break;
	case MENU:
		gs = new GSMenu();
		break;
	case PLAY:
		gs = new GSPlay();
		break;
	case END:
		gs = new GSEnd();
		break;
	case ABOUT:
		gs = new GSAbout();
		break;
	case LEADERBOARD:
		gs = new GSLeaderBoard();
		break;
	case SETTING:
		gs = new GSSettings();
		break;
	case TUTORIAL:
		gs = new GSTutorial();
		break;
	case PAUSE:
		gs = new GSPause();
		break;
	default:
		break;
	}
	return gs;
}
