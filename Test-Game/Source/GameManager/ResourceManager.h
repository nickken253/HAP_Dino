#pragma once
#include <map>
#include <list>
#include <vector>
#include <string>
#include "../gameConfig.h"
#include "../GameObjects/GameButton.h"
#include "../GameObjects/Animation.h"
#include "../GameObjects/TileMapBase.h"
#include "SFML/Audio.hpp"

#define DATA ResourceManager::GetInstance()
class ResourceManager : public CSingleton<ResourceManager>
{
public:
	ResourceManager();
	~ResourceManager();

	// Add Texture
	void addTexture(std::string name);
	void removeTexture(std::string name);
	sf::Texture* getTexture(std::string name);

	// Add Font
	void addFont(std::string name);
	void removeFont(std::string name);
	sf::Font* getFont(std::string name);

	// Add Sound
	void addSound(std::string name);
	void removeSound(std::string name);
	sf::Sound* getSound(std::string name);
	bool getAllowMusic(); 
	bool getAllowSound();
	void setAllowMusic(bool allow);
	void setAllowSound(bool allow);
	void playMusic(std::string name);
	void playSound(std::string name);

	// Add Music
	void addMusic(std::string name);
	void removeMusic(std::string name);
	sf::Music* getMusic(std::string name);
private:
	std::map<std::string, sf::Texture*> m_mapTexture;
	std::map<std::string, sf::Font*> m_mapFont;
	std::map<std::string, sf::Sound*> m_mapSound;
	std::map<std::string, sf::Music*> m_mapMusic;

	std::string m_path;
	std::string m_texturePath;
	std::string m_fontPath;
	std::string m_soundPath;

	bool m_isAllowMusic;
	bool m_isAllowSound;
};