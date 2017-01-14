//
// Created by patrik on 14.01.17..
//

#ifndef NEWGAME_PLAYABLECHARACTER_H
#define NEWGAME_PLAYABLECHARACTER_H


#include "Character.h"

class PlayableCharacter : public Character {
public:
    PlayableCharacter(std::string name, sf::Vector2f initPosition);
    PlayableCharacter(std::string name, sf::Vector2f initPosition, int playerIndex);
    void input(InputManager *inputManager);
    bool isVisible();
protected:
    int _playerIndex;

    bool _left;
    bool _right;
    bool _up;
    bool _down;
};


#endif //NEWGAME_PLAYABLECHARACTER_H
