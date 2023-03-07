#pragma once
#include "../GameManager/Singleton.h"
#define HSM HighScoreManager::GetInstance()
class HighScoreManager : public CSingleton<HighScoreManager>
{
public:
	HighScoreManager();
	void setCurrentScore(int score);
	int getCurrentScore();
	void UpdateHighScore();
	int getBestScore();

	void readFile();
	void writeFile();

	void printfScore();

	int* getHighScore();
	int getNum();
private:
	int m_currentScore;
	int m_highScore[10];
	int m_num;
};