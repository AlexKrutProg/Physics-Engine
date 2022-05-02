#include "../Transform.h"

Transform::Transform()
        : position(1.0f, 1.0f), rotation(0.0f), scale(1.0f, 1.0f) {

}

Transform::Transform(const sf::Vector2f& position, float rotation, const sf::Vector2f& scale) : position(position),
                                                                                                rotation(rotation),
                                                                                                scale(scale) {}

const sf::Vector2f& Transform::getPosition() const {
    return position;
}

float Transform::getRotation() const {
    return rotation;
}

const sf::Vector2f& Transform::getScale() const {
    return scale;
}

void Transform::setPosition(const sf::Vector2f& position) {
    Transform::position = position;
}

void Transform::setRotation(float rotation) {
    Transform::rotation = rotation;
}

void Transform::setScale(const sf::Vector2f& scale) {
    Transform::scale = scale;
}
