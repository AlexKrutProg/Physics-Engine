#include <SFML/System/Clock.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include "CleanManager.h"
#include "CollisionManager.h"
#include <random>

#pragma once

class Scene;

class GlobalInfo {
private:
    sf::Clock clock;
    float pixelsPerUnit;
    sf::Vector2f gravity;
    sf::RenderWindow window;
    CollisionManager collisionDetector;
    Scene& scene;
public:
    explicit GlobalInfo(Scene&);

    void onFrameDone();

    int getDeltaTime() const;

    float getPixelsPerUnit() const;

    const sf::Vector2f& getGravity() const;

    sf::RenderWindow& getWindow();

    CollisionManager& getCollisionDetector();

    Scene& getScene();

    static constexpr int screenW = (1280);
    static constexpr int screenH = (720);
    static constexpr float screenWidthInUnits = 20;
    static constexpr float screenHeightInUnits = screenH / (screenW / screenWidthInUnits);
};
