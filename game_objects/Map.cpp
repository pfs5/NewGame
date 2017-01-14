//
// Created by patrik on 13.01.16..
//

#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "Map.h"
#include "../settings/settings.h"

unsigned short Map::getColorData(unsigned int color) {
    switch (color) {
        case 255:
            return 1;           // collision
        default:
            return 0;           // no data

    }
}

Map::Map(std::string name) {
    loadMap(name);
}

void Map::loadMap(std::string name) {
    std::string pathTop = settings::project_path + std::string("resources/maps/") + name + std::string("_top") + settings::map_ext;
    std::string pathBottom = settings::project_path + std::string("resources/maps/") + name + std::string("_bottom") + settings::map_ext;

    // Load texture
    if (!_mapTextureTop.loadFromFile(pathTop)) {
        std::cerr << "Failed to load top map \"" + name + "\"." << std::endl;
        return;
    }
    if (!_mapTextureBottom.loadFromFile(pathBottom)) {
        std::cerr << "Failed to load top map \"" + name + "\"." << std::endl;
        return;
    }

    // Init sprite
    _mapSpriteTop.setTexture(_mapTextureTop);
    _mapSpriteTop.setScale(settings::scale, settings::scale);

    _mapSpriteBottom.setTexture(_mapTextureBottom);
    _mapSpriteBottom.setScale(settings::scale, settings::scale);

    loadMapData(name);

    std::cerr << "Successfully loaded map \"" + name + "\"." << std::endl;
}

void Map::loadMapData(std::string name) {
    std::string pathData = settings::project_path + std::string("resources/maps/") + name + std::string("_data") +
                           settings::map_ext;
    sf::Image image;
    if (!image.loadFromFile(pathData)) {
        std::cerr << "Failed to load data map \"" + name + "\"." << std::endl;
    }

//    //Create data map
//    sf::Vector2u size = image.getSize();
//    for (unsigned int y = 0; y < size.y; y += settings::base) {
//        std::vector<unsigned short> row;
//        for (unsigned int x = 0; x < size.x; x += Settings::BASE()) {
//            // TODO
//            sf::Color pixel = image.getPixel(x, y);
//            row.push_back(Map::getColorData(pixel.toInteger()));
//            std::cout << pixel.toInteger() << std::endl;
//        }
//        _mapData.push_back(row);
//    }
}

void Map::drawTop(sf::RenderWindow &window) {
    window.draw(_mapSpriteTop);
}

void Map::drawBottom(sf::RenderWindow &window) {
    window.draw(_mapSpriteBottom);
}


bool Map::checkCollision(sf::Vector2f pos1, sf::Vector2f pos2) {

}