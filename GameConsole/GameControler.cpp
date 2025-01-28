#include "GameControler.h"
#include <iostream>

void GameControler::InitializeWindow()
{
	videoMode.width = 800;
	videoMode.height = 600;

	_window = new sf::RenderWindow(
		videoMode,
		"Game",
		sf::Style::Titlebar |
		sf::Style::Close);

	_window->setFramerateLimit(60);
}

GameControler::GameControler()
{
	_points = 0;
	_enemySpawnTimerLimit = 100.f;
	_enemySpawnTimer = _enemySpawnTimerLimit;
	_maxEnemies = 5;

	InitializeWindow();
	InitializeEnemies();
}

GameControler::~GameControler()
{

}

void GameControler::PollEvents()
{
	while (_window->pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				_window->close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					_window->close();
				}
				break;
		}
	}

}

void GameControler::UpdateMousePosition()
{
	_mousePosition = sf::Mouse::getPosition(*this->_window);
	_mousePositionView = _window->mapPixelToCoords(_mousePosition);
}

void GameControler::Update()
{
	PollEvents(); 
	UpdateMousePosition();
	UpdateEnemies();
}

void GameControler::Render()
{ 
	_window->clear(sf::Color(100, 100, 50, 50));
	RenderEnemies();
	_window->display();
}

void GameControler::InitializeEnemies()
{
	_enemy.setPosition(10.f, 10.f);
	_enemy.setSize(sf::Vector2f(50.f, 50.f));
	//_enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	_enemy.setFillColor(sf::Color::Blue);
	_enemy.setOutlineColor(sf::Color::Red);
	_enemy.setOutlineThickness(1.f);
}

void GameControler::SpawnEnemy()
{
	_enemy.setPosition
	(
		static_cast<float>(rand() % static_cast<int>(_window->getSize().x - _enemy.getSize().x)),
		0.f
	);

	_enemy.setFillColor(sf::Color::Green);
	_enemies.push_back(_enemy);
}

void GameControler::UpdateEnemies()
{
	if (_enemies.size() < _maxEnemies)
	{
		if (_enemySpawnTimer >= _enemySpawnTimerLimit)
		{
			SpawnEnemy();
			_enemySpawnTimer = 0.f;
		}
		else
		{
			_enemySpawnTimer += 1.f;
		}
	}

	for (int i = 0; i < _enemies.size(); i++)
	{
		_enemies[i].move(0.f, 1.f);

		if (sf::Mouse::isButtonPressed((sf::Mouse::Left)))
		{
			if (_enemies[i].getGlobalBounds().contains(_mousePositionView))
			{
				_enemies.erase(_enemies.begin() + i);
			}
		}
	}
}

void GameControler::RenderEnemies()
{
	for (auto &i : _enemies)
	{
		_window->draw(i);
	}
}

bool GameControler::IsRunning()
{
	return _window->isOpen();
}
