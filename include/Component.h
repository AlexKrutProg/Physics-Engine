#include <memory>
#include "Transform.h"

class GameObject;

class Component {
public:
    Component(GameObject*);
    GameObject* getGameObject();
    virtual void update();
    virtual void draw();
    virtual ~Component();

protected:
    GameObject* gameObject;
};