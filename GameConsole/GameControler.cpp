#include "GameControler.h"
#include <iostream>
#include <sstream>

void GameControler::InitializeWindow()
{
	sf::VideoMode videoMode;
	videoMode.width = VIDEO_MODE_WIDTH;
	videoMode.height = VIDEO_MODE_HEIGHT;

	_window = new sf::RenderWindow(
		videoMode,
		"Game",
		sf::Style::Titlebar |
		sf::Style::Close);

	_window->setFramerateLimit(FRAME_LIMIT);
}

void GameControler::InitializeUI()
{
	if (!_font.loadFromFile("Fonts/game_over.ttf"))
	{
		std::cout << "font doesn't exist";
	}

	_text.setFont(_font);
	_text.setCharacterSize(42);
	_text.setFillColor(sf::Color::White);
	_text.setString("NONE");
}

GameControler::GameControler()
{
	_points = 0;
	InitializeWindow();
	InitializeUI();
	_spawner = new Spawner(_window);
}

GameControler::~GameControler()
{

}

void GameControler::ListenToEvents()
{
	while (_window->pollEvent(_event))
	{
		switch (_event.type)
		{
			case sf::Event::Closed:
				_window->close();
				break;
			case sf::Event::KeyPressed:
				if (Keyboard::IsKeyPressed(_event, sf::Keyboard::Escape))
				{
					_window->close();
				}
				break;
		}
	}
}

void GameControler::UpdateMousePosition()
{
	_mouse.SetPosition(*this->_window);
	_mouse.SetViewPosition(_window);
}

void GameControler::UpdateText()
{
	std::stringstream stringStream;
	stringStream << "Points " << _points;
	_text.setString(stringStream.str());
}

void GameControler::Update()
{
	ListenToEvents(); 
	UpdateMousePosition();
	SpawnEnemies();
	UpdateText();
	UpdateEnemies();
}

void GameControler::Render()
{ 
	_window->clear(sf::Color::Black);
	RenderEnemies(*this->_window);
	RenderText(*this->_window);
	_window->display();
}

void GameControler::UpdateEnemies()
{
	for (int i = 0; i < _spawnedCubes.size(); i++)
	{
		_spawnedCubes[i].move(0.f, 1.f);

		if (_mouse.IsLeftButtonPressed() &&
			Detection::IsBoundsContain(_spawnedCubes[i], _mouse.GetPositionView()))
		{
			_spawnedCubes.erase(_spawnedCubes.begin() + i);
			_points++;
		}
	}
}

void GameControler::SpawnEnemies()
{
	if (_spawner->IsInCooldown())
	{
		_spawnedCubes.push_back(_spawner->Spawn());
	}
}

void GameControler::RenderEnemies(sf::RenderTarget& target)
{
	for (auto &i : _spawnedCubes)
	{
		target.draw(i);
	}
}

void GameControler::RenderText(sf::RenderTarget& target)
{
	target.draw(_text);
}

bool GameControler::IsRunning()
{
	return _window->isOpen();
}
