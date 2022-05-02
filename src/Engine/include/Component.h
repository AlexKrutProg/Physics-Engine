#include <memory>
#include "Transform.h"
#pragma once
class GameObject;

class Component {
protected:
    GameObject &gameObject;
public:
    Component(GameObject &gameObject);

    GameObject &getGameObject();

    virtual void update();

    virtual void draw();

    virtual ~Component();
};
