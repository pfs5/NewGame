//
// Created by patrik on 14.01.17..
//

#ifndef NEWGAME_CHARACTER_H
#define NEWGAME_CHARACTER_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameObject.h"

class Character : public GameObject {
public:
    Character(std::string name, sf::Vector2f initPosition);

    void input(InputManager *inputManager);

    void update();

    void draw(sf::RenderWindow *window);

    sf::Vector2f getPosition();

    unsigned int getSizeX() { return _sizeX; }

    unsigned int getSizeY() { return _sizeY; }

    // Collider methods
    void undo();

protected:
    unsigned int _sizeX;
    unsigned int _sizeY;

    // Drawing
    sf::Texture _charTexture;
    sf::Sprite _charSprite;

    // Movement
    enum Direction {
        Up, Down, Left, Right
    };
    Direction _direction;
    int _counter;           // sprite counter
    float _moveCounter;     // move sequence counter
    int _moveState;         // moving sprite select

    float _moveX;
    float _moveY;

    // Functions
    int getDirectionIndex(Direction dir) {
        switch (dir) {
            case Down:
                return 0;
            case Up:
                return 1;
            case Right:
                return 2;
            case Left:
                return 3;
        }
    }
};


#endif //NEWGAME_CHARACTER_H
