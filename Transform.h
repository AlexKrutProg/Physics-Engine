#ifndef BUBBLYENGINE_TRANSFORM_H
#define BUBBLYENGINE_TRANSFORM_H


#include <SFML/System.hpp>

class Transform {
private:
    sf::Vector2f position;
    float rotation;
    sf::Vector2f scale;
public:

    Transform();

    Transform(const sf::Vector2f& position, float rotation, const sf::Vector2f& scale);

    const sf::Vector2f& getPosition() const;

    float getRotation() const;

    const sf::Vector2f& getScale() const;

    void setPosition(const sf::Vector2f& position);

    void setRotation(float rotation);

    void setScale(const sf::Vector2f& scale);
};


#endif //SHOOTINGGALLERY_TRANSFORM_H
