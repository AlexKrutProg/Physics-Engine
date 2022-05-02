#include "GameObject.h"
#include "Component.h"
#include <SFML/Graphics.hpp>
#pragma once
class CameraComponent : public Component{
private:
    bool isMain;
    sf::View sfmlView;
public:
    explicit CameraComponent(GameObject &gameObject);
    void update();
    void setMain(bool);
};
