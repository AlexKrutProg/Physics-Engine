#include <SFML/System.hpp>
#pragma once
template <typename T>
sf::Vector2<T> multiByElement(sf::Vector2<T>& a, sf::Vector2<T>& b)
{
    return sf::Vector2<T>(a.x*b.x,a.y*b.y);
}
