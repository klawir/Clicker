#include "Keyboard.h"

bool Keyboard::IsKeyPressed(sf::Event event, sf::Keyboard::Key key)
{
    return event.key.code == key;
}
