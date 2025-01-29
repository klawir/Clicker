#pragma once
#include "SFMLincludes.h"
#include "Mouse.h"
#include <vector>
#include <ctime>
#include "Spawner.h"
#include "Keyboard.h"
#include "Detection.h"

#define VIDEO_MODE_WIDTH 800
#define VIDEO_MODE_HEIGHT 600
#define FRAME_LIMIT 60
#define FONT_SIZE 42

class GameControler
{
private:
	sf::RenderWindow* _window;
	std::vector <sf::RectangleShape> _spawnedCubes;
	int _points;
	sf::Event _event;
	sf::Font _font;
	sf::Text _text;
	Mouse _mouse;
	Spawner* _spawner;
	void InitializeWindow();
	void InitializeUI();

public:
	GameControler();
	virtual ~GameControler();
	void ListenToEvents();
	void UpdateMousePosition();
	void UpdateText();
	void Update();
	void Render();
	void UpdateEnemies();
	void SpawnEnemies();
	void RenderText(sf::RenderTarget& target);
	void RenderEnemies(sf::RenderTarget& target);
	bool IsRunning();
};

