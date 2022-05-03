#include <memory>
#include "Transform.h"
#pragma once
class GameObject;

class Component {
protected:
    GameObject &gameObject;
public:
    explicit Component(GameObject &gameObject);

    GameObject &getGameObject();

    virtual void update();

    virtual void draw();

    virtual ~Component();
};
