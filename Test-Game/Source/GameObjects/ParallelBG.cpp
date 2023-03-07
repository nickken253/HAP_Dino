#include "ParallelBG.h"

void ParallelBG::Init()
{
	Layer* layer;
	std::string m_path = "/Background Layers/";

	// Layer 2
	layer = new Layer();
	layer->Init(m_path + "Hills Layer 02",50);
	m_layerBackGround.push_back(layer);

	// Layer 3
	layer = new Layer();
	layer->Init(m_path + "Hills Layer 03", 60);
	m_layerBackGround.push_back(layer);

	// Layer 4
	layer = new Layer();
	layer->Init(m_path + "Hills Layer 04", 100);
	m_layerBackGround.push_back(layer);

	// Layer 5
	layer = new Layer();
	layer->Init(m_path + "Hills Layer 05", 150);
	m_layerBackGround.push_back(layer);

	// Layer 6
	layer = new Layer();
	layer->Init(m_path + "Hills Layer 06", 200);
	m_layerBackGround.push_back(layer);

	
}

void ParallelBG::Update(float deltaTime)
{
	for (auto layer : m_layerBackGround)
	{
		layer->Update(deltaTime);
	}
}

void ParallelBG::Render(sf::RenderWindow* window)
{
	for (auto layer : m_layerBackGround)
	{
		layer->Render(window);
	}
}
