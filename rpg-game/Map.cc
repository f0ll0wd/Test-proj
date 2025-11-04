#include "Map.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <functional>
#include <iostream>

Map::Map() : tileWidth(32), tileHeight(32), totalX(0), totalY(0) {}
Map::~Map() {}

void Map::Initialize() {}

void Map::Load() {
  if (texture.loadFromFile(
          "../assets/TileSheets/Tiles-SandstoneDungeons.png")) {
    std::cout << "Loaded Dunguon Tilesheet successfully" << std::endl;
    totalX = texture.getSize().x / tileWidth;
    totalY = texture.getSize().y / tileHeight;

    int IndexX = 4;
    int IndexY = 0;

    sprite = sf::Sprite(texture);
    sprite->setTextureRect(sf::IntRect(
        {IndexX * tileWidth, IndexY * tileHeight}, {tileWidth, tileHeight}));
    sprite->setScale({4, 4});
  } else {
    std::cout << "Did NOT LOAD Dunguon Tilesheet, FAILURE" << std::endl;
  }
}

void Map::Update(float deltaTime) {}

void Map::Draw(sf::RenderWindow &window) { window.draw(*sprite); }
