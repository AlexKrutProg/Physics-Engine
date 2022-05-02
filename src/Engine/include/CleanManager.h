#include <stack>
#include "AbstractManager.h"
#include "GameObject.h"
#pragma once
class CleanManager {
private:
    std::forward_list<GameObject> &gameObjects;
public:
    CleanManager(std::forward_list<GameObject> &arg);

    void afterUpdate();
};
