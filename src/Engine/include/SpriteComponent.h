#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Component.h"
#pragma once
class SpriteComponent : public Component {
private:
    sf::Sprite sprite;
    sf::Vector2f textureSize;
    sf::Vector2f getScaleToUnits(sf::Vector2f units) const;
public:
    explicit SpriteComponent(GameObject &gameObject1);

    SpriteComponent(GameObject &transform, const sf::Texture &texture);

    sf::Sprite &getSprite();

    void setTexture(const sf::Texture &texture);

    void update();

    void draw();
};

