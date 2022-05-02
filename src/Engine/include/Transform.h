#include <SFML/System.hpp>
#pragma once
class Transform {
public:
    sf::Vector2f position;
    float rotation;
    sf::Vector2f scale;

    Transform();
};
