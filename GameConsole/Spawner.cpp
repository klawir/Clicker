#include "Spawner.h"

Spawner::Spawner(sf::RenderWindow* window)
{
	_limit = 5;
	_windowSizeX = window->getSize().x;
	_timerLimit = 100.f;
	_currectTime = _timerLimit;

	_objectToSpawn.setPosition(10.f, 10.f);
	_objectToSpawn.setSize(sf::Vector2f(50.f, 50.f));
	//_enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	_objectToSpawn.setFillColor(sf::Color::Blue);
	_objectToSpawn.setOutlineColor(sf::Color::Red);
	_objectToSpawn.setOutlineThickness(1.f);
}

sf::RectangleShape Spawner::Spawn()
{
	_objectToSpawn.setPosition
	(
		static_cast<float>(rand() % static_cast<int>(_windowSizeX - _objectToSpawn.getSize().x)),
		0.f
	);

	_objectToSpawn.setFillColor(sf::Color::Green);

	return _objectToSpawn;
}

bool Spawner::IsInCooldown()
{
	if (_currectTime >= _timerLimit)
	{
		_currectTime = 0.f;
		return true;
	}
	else
	{
		_currectTime += 1.f;
		return false;
	}
}
