#pragma once
#include "Singleton.h"
#include <iostream>
#include <fstream>
using namespace std;

#define OPERATOR OperationsManager::GetInstance()
class OperationsManager : public CSingleton<OperationsManager> {
public:
	void update(const float& deltaTime) {
		if (timeClickMouse > 0.0f) {
			timeClickMouse -= deltaTime;
		}
	}
	bool allowClickMouse() {
		return timeClickMouse <= 0.0f;
	}
	void setClick() {
		timeClickMouse = 0.2f;
	}
	void setStartCoin(int coin)
	{
		startCoin = coin;
	}
	int getStartCoin()
	{
		return startCoin;
	}
	bool resetMap = false;
	
private:
	float timeClickMouse = 0.0f;
	int startCoin;
};