#include "Engine/include/Scene.h"
#include "Engine/include/SpriteComponent.h"
#include "Engine/include/PhysComponent.h"
#include "BubbleComponent.h"
#include <random>
class Game {
private:
    sf::Texture bubbleTexture;
    Scene scene;
    sf::Texture backgroundTexture;

    void addBubble(const sf::Vector2f& position) {
        // создание объекта
        auto& newGameObject = scene.createGameObject();
        // добавление спрайта для данного объекта
        newGameObject.addComponent("Sprite", new SpriteComponent(newGameObject, bubbleTexture));
        // добавление физической компоненты
        newGameObject.addComponent("Physics",
                                   new PhysComponent(newGameObject, 0.5, true, true));
        const auto currentPhysComponent = newGameObject.getComponent<PhysComponent>("Physics");
        // добавление коллайдера
        currentPhysComponent.lock()->setCollider(Collider::circleCollider(0.45f));
        newGameObject.getTransform().position = position;
        newGameObject.addComponent("Bubble", new BubbleComponent(newGameObject));
    }

    void addWall(const sf::Vector2f& size, const sf::Vector2f& position) {
        auto& newGameObject = scene.createGameObject();
        newGameObject.addComponent("Physics",
                                   new PhysComponent(newGameObject, 0.0f, false, false));
        const auto currentPhysComponent = newGameObject.getComponent<PhysComponent>("Physics");
        currentPhysComponent.lock()->setCollider(Collider::rectangleCollider(size));
        newGameObject.getTransform().position = position;
    }

    void loadLevel() {
        backgroundTexture.loadFromFile("../../images/bg.png");
        backgroundTexture.setSmooth(true);
        scene.setBackground(backgroundTexture);
        bubbleTexture.loadFromFile("../../images/circle.png");
        bubbleTexture.setSmooth(true);
        auto& bubbleObject = scene.createGameObject();

        for (auto i = 0; i < 40; ++i)
            addBubble(sf::Vector2f(float(rand() % 30),float(rand() % 30)));

        const auto screenW = scene.getInfo().screenWidthInUnits;
        const auto screenH = scene.getInfo().screenHeightInUnits;
        addWall(sf::Vector2f(screenW, 0.5f),
                sf::Vector2f(screenW / 2,
                             screenH - 0.25f));
        addWall(sf::Vector2f(screenW, 0.5f),
                sf::Vector2f(screenW / 2, -0.75f));
        addWall(sf::Vector2f(0.5f, screenH),
                sf::Vector2f(-0.75f, screenH / 2));
        addWall(sf::Vector2f(0.5f, screenH),
                sf::Vector2f(screenW - 0.25f, screenH / 2));
    }

public:
    Game() : scene(std::bind(&Game::loadLevel, this)) {}

    void start() {
        scene.startGameLoop();
    }
};

int main() {
    srand(time(NULL));
    Game game;
    game.start();
    return 0;
}
