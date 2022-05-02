#include <SFML/System.hpp>

class Transform {
public:
    sf::Vector2f position;
    float rotation;
    sf::Vector2f scale;

    Transform();
};
