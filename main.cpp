#include <iostream>
#include <SFML/Graphics.hpp>
#include "settings/settings.h"
#include "game_objects/Map.h"
#include "input/InputManager.h"
#include "game_objects/Character.h"
#include "game_objects/PlayableCharacter.h"

using namespace std;

// Global variables
Map *gameMap;                               // current map
Character *mainCharacter;                   // main character
std::vector<GameObject *> gameObjects;      // game objects
sf::RenderWindow *window;                   // main window
sf::View *view;                             // current view
InputManager *inputManager;                 // input manager

void Setup() {
    // Setup input manager
    inputManager = InputManager::getInstance();

    // Setup window
    sf::Vector2i centerWindow(sf::VideoMode::getDesktopMode().width / 2 - settings::width / 2, sf::VideoMode::getDesktopMode().height / 2 - settings::height / 2);
    window = new sf::RenderWindow(sf::VideoMode(settings::width, settings::height), settings::title, sf::Style::Titlebar | sf::Style::Close);
    window->setPosition(centerWindow);

    // Setup view
    view = new sf::View(sf::FloatRect(0, 0, settings::width, settings::height));
    window->setView(*view);

    // Load map
    gameMap = new Map("map1");

    // Load test characters
    PlayableCharacter *c1 = new PlayableCharacter("char1", {300, 300}, 0);
    PlayableCharacter *c2 = new PlayableCharacter("char2", {350, 350}, 1);

    gameObjects.push_back(c1);
    gameObjects.push_back(c2);

}

void Input() {
    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->input(inputManager);
    }
}

void Update() {
    sf::Vector2f viewPosition = {0, 0};
    int objCounter = 0;

    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->update();

        if (gameObjects[i]->isVisible()) {
            viewPosition += gameObjects[i]->getPosition();
            objCounter ++;
        }
    }

    viewPosition.x /= objCounter;
    viewPosition.y /= objCounter;

    // Update view
    view->setCenter(viewPosition);
    window->setView(*view);
}

void Draw() {
    // Draw background map
    gameMap->drawBottom(*window);

    // Draw game objects
    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->draw(window);
    }

    // Draw top map
//    gameMap->drawTop(*window);
}


int main(int argc, char *argv[]) {
    std::cerr << argv[0] << std::endl;
    Setup();

    sf::Clock clock;
    sf::Time accumulator = sf::Time::Zero;
    sf::Time ups = sf::seconds(1.f / settings::ups);

    while (window->isOpen()) {
        sf::Event event;

        // Event loop
        while (window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window->close();
            }
        }

        window->clear();

        Input();

        while (accumulator > ups) {
            accumulator -= ups;
            Update();
        }

        Draw();
        window->display();

        accumulator += clock.restart();
    }

    return 0;
}