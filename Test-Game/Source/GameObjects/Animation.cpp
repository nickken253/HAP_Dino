#include "Animation.h"

Animation::Animation(sf::Texture& texture, sf::Vector2i frameNum, float frameTime)
{
	m_frameNum = frameNum;
	m_frameTime = frameTime;
	this->setTexture(texture);

	m_currentFrame = sf::Vector2i(0, 0);
	m_currentTime = 0.f;

	CaculateRectSize();
	CaculateRectUV();
	ApplyRect();
	this->setOrigin((sf::Vector2f)m_rectSize / 2.f);

	m_modeStopAtEndFrame = false;
}

void Animation::CaculateRectSize()
{
	m_rectSize = sf::Vector2i(this->getTexture()->getSize().x / m_frameNum.x, this->getTexture()->getSize().y / m_frameNum.y);
}

void Animation::CaculateRectUV()
{
	m_rectUV.x = m_currentFrame.x * m_rectSize.x;
	m_rectUV.y = m_currentFrame.y * m_rectSize.y;
}

void Animation::ApplyRect()
{
	m_rect = sf::IntRect(m_rectUV, m_rectSize);
	this->setTextureRect(m_rect);
}

void Animation::setModeEndFrame(bool stop)
{
	m_modeStopAtEndFrame = stop;
}

void Animation::Reset()
{
	m_currentFrame.x = 0;
	m_currentTime = 0.f;
}

void Animation::Update(float deltaTime)
{
	if (m_currentFrame.x == m_frameNum.x - 1 && m_modeStopAtEndFrame) return;

	m_currentTime += deltaTime;
	if (m_currentTime >= m_frameTime)
	{
		m_currentFrame.x++;
		if (m_currentFrame.x == m_frameNum.x)
		{
			m_currentFrame.x = 0;
		}
		CaculateRectUV();
		ApplyRect();
		m_currentTime -= m_frameTime;
	}
	
}

sf::Vector2i Animation::getCurrentFrame()
{
	return m_currentFrame;
}

sf::Vector2i Animation::getFrameNum()
{
	return m_frameNum;
}