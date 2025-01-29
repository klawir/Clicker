#include "Mouse.h"

void Mouse::SetPosition(sf::RenderWindow& window)
{
	_position = sf::Mouse::getPosition(window);
}

void Mouse::SetViewPosition(sf::RenderWindow* window)
{
	_positionView = window->mapPixelToCoords(_position);
}

bool Mouse::IsLeftButtonPressed()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

sf::Vector2f Mouse::GetPositionView()
{
	return _positionView;
}
