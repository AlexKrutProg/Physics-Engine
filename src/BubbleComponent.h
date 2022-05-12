#include "Engine/include/Component.h"
#include "Engine/include/PhysComponent.h"

class BubbleComponent : public Component {
private:
    std::weak_ptr<PhysComponent> physComponent;
    sf::Clock clock;
public:
    BubbleComponent(GameObject &);

    void update();
};


