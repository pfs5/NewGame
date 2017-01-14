//
// Created by patrik on 14.01.17..
//

#include <iostream>
#include "PlayableCharacter.h"
#include "../settings/settings.h"

PlayableCharacter::PlayableCharacter(std::string name, sf::Vector2f initPosition)
        : PlayableCharacter(name, initPosition, 0) {
}

PlayableCharacter::PlayableCharacter(std::string name, sf::Vector2f initPosition, int playerIndex)
        : Character(name, initPosition) {
    _playerIndex = playerIndex;

    _left = false;
    _right = false;
    _up = false;
    _down = false;
}

void PlayableCharacter::input(InputManager *inputManager) {
    _moveX = 0;
    _moveY = 0;
    bool moving = false;
    bool changedDir = false;

    if (inputManager->left(_playerIndex)) {
        _moveX = -settings::game_speed;
        moving = true;

        if (!_left) {
            _direction = Left;
        }
        _left = true;
    } else {
        _left = false;
    }

    if (inputManager->right(_playerIndex)) {
        _moveX = settings::game_speed;
        moving = true;

        if (!_right) {
            _direction = Right;
        }
        _right = true;
    } else {
        _right = false;
    }

    if (inputManager->up(_playerIndex)) {
        _moveY = -settings::game_speed;
        moving = true;

        if (!_up) {
            _direction = Up;
        }
        _up = true;
    } else {
        _up = false;
    }

    if (inputManager->down(_playerIndex)) {
        _moveY = settings::game_speed;
        moving = true;

        if (!_down) {
            _direction = Down;
        }
        _down = true;
    } else {
        _down = false;
    }

    if (!moving) {
        _moveState = 0;
        _counter = 0;
    } else if (_moveState == 0) {
        _moveState = 1;
    }
}

bool PlayableCharacter::isVisible() {
    return true;
}
