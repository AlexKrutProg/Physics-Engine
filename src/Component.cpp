#include "../include/Component.h"
#include "../include/GameObject.h"

Component::Component(GameObject& _gameObject) : gameObject(_gameObject) {}

GameObject& Component::getGameObject() {
    return gameObject;
}

Component::~Component() = default;