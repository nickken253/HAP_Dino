#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	m_path = "../Data/";
	m_texturePath = m_path + "Textures/";
	m_fontPath = m_path + "Fonts/";
	m_soundPath = m_path + "Sounds/";
	m_isAllowMusic = true;
	m_isAllowSound = true;
}

ResourceManager::~ResourceManager()
{
	for (auto it : m_mapTexture)
	{
		if (it.second != nullptr)
		{
			delete it.second;
		}
	}
	m_mapTexture.clear();

	for (auto it : m_mapFont)
	{
		if (it.second != nullptr)
		{
			delete it.second;
		}
	}
	m_mapFont.clear();
}

void ResourceManager::addTexture(std::string name)
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(m_texturePath + name + ".png");

	auto it = m_mapTexture.find(name);
	if (it != m_mapTexture.end())
	{
		return;
	}

	m_mapTexture.insert(std::pair<std::string, sf::Texture*>(name, texture));
}

void ResourceManager::removeTexture(std::string name)
{
	auto it = m_mapTexture.find(name);
	if (it == m_mapTexture.end())
	{
		return;
	}
	if(it->second != nullptr) delete it->second;
	m_mapTexture.erase(it);
}

sf::Texture* ResourceManager::getTexture(std::string name)
{
	auto it = m_mapTexture.find(name);
	if (it != m_mapTexture.end())
	{
		return it->second;
	}
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(m_texturePath + name + ".png");
	m_mapTexture.insert(std::pair<std::string, sf::Texture*>(name, texture));
	return texture;
}

void ResourceManager::addFont(std::string name)
{
	sf::Font* font = new sf::Font();
	font->loadFromFile(m_fontPath + name + ".ttf");

	auto it = m_mapFont.find(name);
	if (it != m_mapFont.end())
	{
		return;
	}

	m_mapFont.insert(std::pair<std::string, sf::Font*>(name, font));
}

void ResourceManager::removeFont(std::string name)
{
	auto it = m_mapFont.find(name);
	if (it == m_mapFont.end())
	{
		return;
	}
	if (it->second != nullptr) delete it->second;
	m_mapFont.erase(it);
}

sf::Font* ResourceManager::getFont(std::string name)
{
	auto it = m_mapFont.find(name);
	if (it != m_mapFont.end())
	{
		return it->second;
	}
	sf::Font* font = new sf::Font();
	font->loadFromFile(m_fontPath + name + ".ttf");
	m_mapFont.insert(std::pair<std::string, sf::Font*>(name, font));
	return font;
}

void ResourceManager::addSound(std::string name)
{
	sf::Sound* sound = new sf::Sound();
	sf::SoundBuffer* buffer = new sf::SoundBuffer();
	buffer->loadFromFile(m_soundPath + name + ".wav");
	sound->setBuffer(*buffer);

	auto it = m_mapSound.find(name);
	if (it != m_mapSound.end())
	{
		return;
	}

	m_mapSound.insert(std::pair<std::string, sf::Sound*>(name, sound));
}

void ResourceManager::removeSound(std::string name)
{
	auto it = m_mapSound.find(name);
	if (it == m_mapSound.end())
	{
		return;
	}
	if (it->second != nullptr) delete it->second;
	m_mapSound.erase(it);
}

sf::Sound* ResourceManager::getSound(std::string name)
{
	auto it = m_mapSound.find(name);
	if (it != m_mapSound.end())
	{
		return it->second;
	}
	sf::Sound* sound = new sf::Sound();
	sf::SoundBuffer* buffer = new sf::SoundBuffer();
	buffer->loadFromFile(m_soundPath + name + ".wav");
	sound->setBuffer(*buffer);

	m_mapSound.insert(std::pair<std::string, sf::Sound*>(name, sound));
	return sound;
}

void ResourceManager::addMusic(std::string name)
{
	sf::Music* music = new sf::Music();
	music->openFromFile(m_soundPath + name + ".wav");

	auto it = m_mapMusic.find(name);
	if (it != m_mapMusic.end())
	{
		return;
	}

	m_mapMusic.insert(std::pair<std::string, sf::Music*>(name, music));
}

void ResourceManager::removeMusic(std::string name)
{
	auto it = m_mapMusic.find(name);
	if (it == m_mapMusic.end())
	{
		return;
	}
	if (it->second != nullptr) delete it->second;
	m_mapMusic.erase(it);
}

sf::Music* ResourceManager::getMusic(std::string name)
{
	auto it = m_mapMusic.find(name);
	if (it != m_mapMusic.end())
	{
		return it->second;
	}
	sf::Music* music = new sf::Music();
	music->openFromFile(m_soundPath + name + ".wav");
	m_mapMusic.insert(std::pair<std::string, sf::Music*>(name, music));
	return music;
}
void ResourceManager::playMusic(std::string name)
{
	if (m_isAllowMusic)
	{
		DATA->getMusic(name)->play();
	}
}
void ResourceManager::playSound(std::string name)
{
	if (m_isAllowSound)
	{
		DATA->getSound(name)->play();
	}
}
bool ResourceManager::getAllowMusic()
{
	return m_isAllowMusic;
}
bool ResourceManager::getAllowSound()
{
	return m_isAllowSound;
}
void ResourceManager::setAllowMusic(bool allow)
{
	m_isAllowMusic = allow;
}
void ResourceManager::setAllowSound(bool allow)
{
	m_isAllowSound = allow;
}