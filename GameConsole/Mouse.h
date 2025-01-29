#pragma once
#include "SFMLincludes.h"

class Mouse
{
private:
	sf::Vector2i _position;
	sf::Vector2f _positionView;

public:
	void SetPosition(sf::RenderWindow& window);
	void SetViewPosition(sf::RenderWindow* window);

	bool IsLeftButtonPressed();
	sf::Vector2f GetPositionView();
};

