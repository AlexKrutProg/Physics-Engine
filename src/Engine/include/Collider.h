

#include <vector>
#include <SFML/System.hpp>
#include <variant>

#pragma once
enum ColliderType {
    CIRCLE,
    RECTANGLE
};

class Collider {
private:
    ColliderType type;
    std::variant<float, sf::Vector2f> properties;
public:
    ColliderType getType();

    float getRadius();

    sf::Vector2f getSize();

    static Collider circleCollider(float radius);

    static Collider rectangleCollider(sf::Vector2f size);
};

