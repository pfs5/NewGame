//
// Created by patrik on 13.01.17..
//

#ifndef NEWGAME_SETTINGS_H
#define NEWGAME_SETTINGS_H

#include <string>

/*
 * Game base ~ 16x16 pixels
 */
namespace settings {
    // Window
    const unsigned int height = 700;
    const unsigned int width = 700;
    const std::string title = "New game";

    // Game loop
    const unsigned int ups = 60;
    const unsigned int scale = 2;
    const float game_speed = 4.f;

    // Files
    const std::string project_path = "/home/patrik/Source/C++/NewGame/";
    const std::string map_ext = ".png";
    const std::string sprite_ext = ".png";
}
#endif //NEWGAME_SETTINGS_H
