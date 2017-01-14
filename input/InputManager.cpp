//
// Created by patrik on 14.01.17..
//

#include <stddef.h>
#include "InputManager.h"

InputManager* InputManager::s_instance = NULL;

InputManager *InputManager::getInstance() {
    if (!s_instance) {
        s_instance = new InputManager;
    }
    return s_instance;
}

bool InputManager::left(int index) {
    switch (index) {
        case 0:
            return sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        case 1:
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        default:
            return false;
    }
}

bool InputManager::right(int index) {
    switch (index) {
        case 0:
            return sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        case 1:
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
        default:
            return false;
    }
}

bool InputManager::up(int index) {
    switch (index) {
        case 0:
            return sf::Keyboard::isKeyPressed(sf::Keyboard::W);
        case 1:
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        default:
            return false;
    }
}

bool InputManager::down(int index) {
    switch (index) {
        case 0:
            return sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        case 1:
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
        default:
            return false;
    }
}