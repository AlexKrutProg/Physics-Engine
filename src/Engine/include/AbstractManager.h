#include "Component.h"
#pragma once
class AbstractManager {
public:
    virtual void add(Component *);

    virtual void update();

    virtual void remove(Component *);
};
