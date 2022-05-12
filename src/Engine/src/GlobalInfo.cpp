#include "../include/GlobalInfo.h"

GlobalInfo::GlobalInfo()
        : gravity(0.0, 5.0f),
          pixelsPerUnit(screenW/screenWidthInUnits),
          window(sf::VideoMode(screenW, screenH),
                 "Engine", sf::Style::Close)
           {
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    clock.restart();
}


sf::RenderWindow &GlobalInfo::getWindow() {
    return window;
}

const sf::Vector2f &GlobalInfo::getGravity() const {
    return gravity;
}

float GlobalInfo::getPixelsPerUnit() const {
    return pixelsPerUnit;
}

int GlobalInfo::getDeltaTime() const {
    return clock.getElapsedTime().asMilliseconds();
}

void GlobalInfo::onFrameDone() {

    clock.restart();
}

CollisionManager &GlobalInfo::getCollisionDetector() {
    return collisionDetector;
}
