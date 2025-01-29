#include "Detection.h"

bool Detection::IsBoundsContain(sf::RectangleShape rect, sf::Vector2f point)
{
    return rect.getGlobalBounds().contains(point);
}
