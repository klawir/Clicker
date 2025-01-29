#pragma once
#include "SFMLincludes.h"
#include <vector>
#include "Mouse.h"

class Spawner
{
private:
	float _currectTime;
	float _timerLimit; 
	unsigned int _windowSizeX;
	sf::RectangleShape _objectToSpawn;
	int _limit;

public:
	Spawner(sf::RenderWindow* window);
	sf::RectangleShape Spawn();
	bool IsInCooldown();
};

