#include <vector>
#include "AbstractManager.h"

class PhysComponent;

class CollisionManager : public AbstractManager {
private:
    std::vector<PhysComponent *> objects;

    static bool checkCollisions(PhysComponent *, PhysComponent *);

public:
    void add(Component *const);

    void update();

    void remove(Component *const);
};
