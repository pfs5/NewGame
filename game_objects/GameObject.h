//
// Created by patrik on 14.01.17..
//

#ifndef NEWGAME_GAMEOBJECT_H
#define NEWGAME_GAMEOBJECT_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "../input/InputManager.h"

class GameObject {
public:
    virtual void input(InputManager *inputManager) = 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow *window) = 0;

    virtual void undo() = 0;
    virtual sf::Vector2f getPosition() = 0;

    virtual unsigned int getSizeX() = 0;
    virtual unsigned int getSizeY() = 0;

    std::string getLabel() {return _label;}

    virtual bool isVisible() {return false;}

protected:
    sf::Vector2f _position;
    std::string _label;
};


#endif //NEWGAME_GAMEOBJECT_H
