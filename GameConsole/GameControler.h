#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <ctime>

class GameControler
{
private:
	sf::RenderWindow* _window;
	sf::Event event;
	sf::VideoMode videoMode;

	int _points;
	sf::RectangleShape _enemy;
	std::vector <sf::RectangleShape> _enemies;

	sf::Vector2i _mousePosition;
	sf::Vector2f _mousePositionView;

	float _enemySpawnTimer;
	float _enemySpawnTimerLimit;
	int _maxEnemies;

	void InitializeWindow();

public:
	GameControler();
	virtual ~GameControler();
	void PollEvents();
	void UpdateMousePosition();
	void Update();
	void Render();
	void InitializeEnemies();
	void SpawnEnemy();
	void UpdateEnemies();
	void RenderEnemies();
	bool IsRunning();
};

