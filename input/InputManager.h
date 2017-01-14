//
// Created by patrik on 14.01.17..
//

#ifndef NEWGAME_INPUTMANAGER_H
#define NEWGAME_INPUTMANAGER_H


#include <SFML/Window/Keyboard.hpp>

class InputManager {
public:
    static InputManager *getInstance();

private:
    InputManager(){};
    static InputManager* s_instance;


public:
    bool left(int index);
    bool right(int index);
    bool up(int index);
    bool down(int index);
};


#endif //NEWGAME_INPUTMANAGER_H
