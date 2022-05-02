#include <memory>
#include "Transform.h"

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
