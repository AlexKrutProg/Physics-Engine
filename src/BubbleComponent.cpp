#include "BubbleComponent.h"
#include "Engine/include/GlobalInfo.h"

BubbleComponent::BubbleComponent(GameObject& obj) :
        Component(obj),
        physComponent(obj.getComponent<PhysComponent>("Physics")) {
    physComponent.lock()->addImpulse(
            sf::Vector2f((float) (rand() % 10 - 5), (float) (rand() % 10 - 5)));
    clock.restart();
}

void BubbleComponent::update() {
    if (clock.getElapsedTime().asSeconds() > 1.0f) {

        physComponent.lock()->update();
        clock.restart();
    }
}