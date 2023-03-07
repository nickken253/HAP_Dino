#include "HighScoreManager.h"
#include <algorithm>
#include <fstream>
HighScoreManager::HighScoreManager()
{
	m_currentScore = 0;
	m_num = 10;
	for (int i = 0; i < m_num; i++)
	{
		m_highScore[i] = 0;
	}
}
void HighScoreManager::setCurrentScore(int score)
{
	m_currentScore = score;
}
int HighScoreManager::getCurrentScore()
{
	return m_currentScore;
}
void HighScoreManager::UpdateHighScore()
{
	int score = m_currentScore;
	for (int i = 0; i < m_num; i++)
	{
		if (score > m_highScore[i])
		{
			std::swap(score, m_highScore[i]);
		}
	}
	std::sort(m_highScore, m_highScore + m_num, [](int a, int b) {return a < b; });
}
int HighScoreManager::getBestScore()
{
	return m_highScore[m_num - 1];
}

void HighScoreManager::readFile()
{
	std::fstream input;
	input.open("Score.data", std::ios::binary | std::ios::in);
	input.read((char*)m_highScore, sizeof(m_highScore));
	input.close();
}
void HighScoreManager::writeFile()
{
	std::fstream output;
	output.open("Score.data", std::ios::binary | std::ios::out);
	output.write((char*)m_highScore, sizeof(m_highScore));
	output.close();
}

void HighScoreManager::printfScore()
{
	for (int i = 0; i < m_num; i++)
	{
		// std::printf("%d ", m_highScore[i]);
	}
	printf("\n");
}

int* HighScoreManager::getHighScore()
{
	return m_highScore;
}
int HighScoreManager::getNum()
{
	return m_num;
}