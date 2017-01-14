//
// Created by patrik on 14.01.17..
//

#include "Character.h"
#include "../settings/settings.h"
#include <iostream>

Character::Character(std::string name, sf::Vector2f initPosition) {
    _label = name;

    // Load sprite
    std::string path = settings::project_path + std::string("resources/sprites/") + name + settings::sprite_ext;

    // Load texture
    if (!_charTexture.loadFromFile(path)) {
        std::cerr << "Failed to load character \"" + name + "\"." << std::endl;
        return;
    }

    // Init sprite
    _sizeX = _charTexture.getSize().x / 3;
    _sizeY = _charTexture.getSize().y / 4;

    _charSprite.setTexture(_charTexture);
    _charSprite.setScale(settings::scale, settings::scale);
    _charSprite.setTextureRect(sf::IntRect(1 * _sizeX, 0, _sizeX, _sizeY));
    _charSprite.setPosition(initPosition.x * settings::scale, (initPosition.y - (_sizeY - _sizeX)) * settings::scale);

    _direction = Down;
    _moveState = 0;
    _counter = 0;

    _moveX = 0;
    _moveY = 0;

    std::cerr << "Successfully loaded character \"" + name + "\"." << std::endl;
}

void Character::input(InputManager *inputManager) {
}

void Character::update() {
    // Alternate sprite
    if (_counter++ > settings::game_speed * 2) {
        _moveState *= -1;
        _counter = 0;
    }
    _charSprite.setTextureRect(sf::IntRect((1 - _moveState) * _sizeX, getDirectionIndex(_direction) * _sizeY, _sizeX, _sizeY));
    _charSprite.move(_moveX, _moveY);
}

void Character::draw(sf::RenderWindow *window) {
    window->draw(_charSprite);
}

sf::Vector2f Character::getPosition() {
    return _charSprite.getPosition();
}

void Character::undo() {

}
