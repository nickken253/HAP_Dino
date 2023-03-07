#include "CollisionManager.h"

void CollisionManager::addObj(HitBox* hitBox)
{
    m_listObj.push_back(hitBox);
}

void CollisionManager::addMap(HitBox* hitBox)
{
	m_listMap.push_back(hitBox);
}

bool CollisionManager::checkCollision(HitBox* a, HitBox* b)
{
	sf::Vector2f otherPosition = a->getPosition();
	sf::Vector2f otherHalfSize = a->getHalfSize();
	sf::Vector2f thisPosition = b->getPosition();
	sf::Vector2f thisHalfSize = b->getHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX <= 0.0f && intersectY <= 0.0f)
	{
		
		return true;
	}
	//a->setDirection(DNULL);
	return false;
}
bool CollisionManager::checkCollision(HitBox* a, HitBox* b, sf::Vector2f& direction, float push)
{
	// a is player or monster
	// b is map

	sf::Vector2f otherPosition = a->getPosition();
	sf::Vector2f otherHalfSize = a->getHalfSize();
	sf::Vector2f thisPosition = b->getPosition();
	sf::Vector2f thisHalfSize = b->getHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	int maxx = 0;
	
	if (intersectX <= 0.0f && intersectY <= 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);
		if (intersectX < intersectY)
		{
			if (deltaY < 0.0f)
			{
				b->move(0.0f, -intersectY * (1.0f - push));
				a->move(0.0f, intersectY * push);

				direction.x = 0.0f;
				direction.y = -1.0f;
				indexx = std::max(2, indexx);
				if (indexx == 2) if (a->getDirection() != DIRECTION::INSIDE) a->setDirection(ABOVE);
			}
			else
			{
				b->move(0.0f, intersectY * (1.0f - push));
				a->move(0.0f, -intersectY * push);

				direction.x = 0.0f;
				direction.y = 1.0f;
				indexx = std::max(2, indexx);
				if (indexx == 2) a->setDirection(BELOW);
			}
		}
		else
		{
			if (deltaX >= 0.0f)
			{
				b->move(intersectX * (1.0f - push), 0.0f);
				a->move(-intersectX * push, 0.0f);

				direction.x = 1.0f;
				direction.y = 0.0f;
				indexx = std::max(1, indexx);
				if (indexx == 1) a->setDirection(RIGHT);
			}
			else
			{
				b->move(-intersectX * (1.0f - push), 0.0f);
				a->move(intersectX * push, 0.0f);

				direction.x = -1.0f;
				direction.y = 0.0f;
				indexx = std::max(1, indexx);
				if (indexx == 1) a->setDirection(LEFT);
			}

		}
		return true;
	}
	else indexx = 0;
	a->setDirection(DNULL);
	return false;
}
void CollisionManager::Move(HitBox* hitBox, float dx, float dy)
{
    hitBox->move(dx, dy);
}
sf::Vector2f CollisionManager::getPosition(HitBox* hitBox)
{
    return hitBox->getPosition();
}
sf::Vector2f CollisionManager::getHalfSize(HitBox* hitBox)
{
    return hitBox->getSize() / 2.0f;
}
void CollisionManager::Update()
{
    for (auto a : m_listObj)
    {
		for (auto b : m_listMap)
		{
			if (a->getTag() == PLAYER)
			{
				if (checkCollision(a, b) == false) 
					 a->setDirection(DIRECTION::DNULL);
				
				continue;
			}
		}
        for (auto b : m_listObj)
        {
            if (a->getTag() == b->getTag()) continue;
			
			if (checkCollision(a, b) == false)
			{
				continue;
			}

			// PLAYER WITH MONSTER CHECK
            if (a->getTag() == PLAYER && b->getTag() == MONSTER)
            {
				if (b->isAlive())
				{
					if (a->getPosition().y + a->getSize().y / 2 <= b->getPosition().y)
					{
						if(a->isAlive()) b->setAlive(false);
						continue;
					}
					else a->setAlive(false);
				}
            }
			
			// MAP WITH ENTITIES CHECK
			if (a->getTag() == PLAYER && b->getTag() == MAP)
			{
				if (a->isAlive()) checkCollision(a, b, m_direction, 1.0f);
			}
			if (a->getTag() == MONSTER && b->getTag() == MAP)
			{
				if (a->isAlive()) checkCollision(a, b, m_direction, 1.0f);
			}
			// PLAYER WITH COIN
			if (a->getTag() == PLAYER && b->getTag() == COIN)
			{
				b->setAlive(false);

			}

			// PLAYER WITH DOOR
			if (a->getTag() == PLAYER && b->getTag() == DOOR)
			{
				if (b->isAlive()) b->setAlive(false);
				a->setDirection(DIRECTION::GOIN);
			}

			// PLAYER WITH FAN
			if (a->getTag() == PLAYER && b->getTag() == FAN)
			{
				checkCollision(a, b, m_direction, 1.0f);
				b->setAlive(false);
			}

			// PLAYER WITH WIND
			if (a->getTag() == PLAYER && b->getTag() == WIND)
			{
				a->setDirection(DIRECTION::INSIDE);
				
			}

			// PLAYER WITH FALLING PLATFORM
			if (a->getTag() == PLAYER && b->getTag() == FALLINGPLATS)
			{				
				if (a->getPosition().y  <= b->getPosition().y)
				{	
					if(checkCollision(a, b, m_direction, 1.0f)) b->setAlive(false);
				}
			}
			// PLAYER WITH SAW OR THORN
			if (a->getTag() == PLAYER && (b->getTag() == SAW || b->getTag() == THORN))
			{
				a->setAlive(false);
			}

			// PLAYER WITH SAW OR PLATFORM
			if (a->getTag() == PLAYER && b->getTag() == PLATFORM)
			{
				if (a->getPosition().y <= b->getPosition().y)
				{
					if (checkCollision(a, b, m_direction, 1.0f))
					{
						b->setAlive(false);
					}
					//else a->setOnPlatform(false);
				}
			}
        }
    }
	for (auto it : m_listMap)
	{

	}
}
