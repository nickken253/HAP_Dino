#pragma once
#include "SFML/Graphics.hpp"

class Animation : public sf::Sprite
{
public:

	Animation(sf::Texture &texture, sf::Vector2i frameNum, float frameTime);
	void Update(float deltaTime);
	void CaculateRectSize();
	void CaculateRectUV();
	void ApplyRect();
	void setModeEndFrame(bool stop);
	void Reset();
	sf::Vector2i getCurrentFrame();
	sf::Vector2i getFrameNum();

private:
	sf::Vector2i m_frameNum;
	sf::Vector2i m_currentFrame;
	
	float m_currentTime;
	float m_frameTime;

	sf::Vector2i m_rectSize;
	sf::Vector2i m_rectUV;
	sf::IntRect m_rect;

	bool m_modeStopAtEndFrame;
	// bool m_turnRight;
};