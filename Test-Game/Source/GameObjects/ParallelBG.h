#pragma once
#include "Layer.h"

class ParallelBG
{
public:
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	std::list<Layer*> m_layerBackGround;
};