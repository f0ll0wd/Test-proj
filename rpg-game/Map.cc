#include "Map.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
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
    Totaltiles = totalX * totalY;

    maptiles = new Tile[Totaltiles];

    int IndexX = 0;
    int IndexY = 0;

    for (int x = 0; x < 63; x++) {
      maptiles[x].id = x;
      maptiles[x].Ttexture = &texture;
      std::cout << "Map loaded texture address: " << &texture
                << ", Tiles item texture pointer address: "
                << maptiles[x].Ttexture << std::endl;
      maptiles[x].sprite = sf::Sprite(*maptiles[x].Ttexture);
      if (IndexX < 9) {
        maptiles[x].sprite->setTextureRect(
            sf::IntRect({IndexX * tileWidth, IndexY * tileHeight},
                        {tileWidth, tileHeight}));
        maptiles[x].sprite->setScale({4, 4});
        // maptiles[x].sprite->setPosition(
        //     sf::Vector2f(IndexX * tileWidth * 4, IndexY * tileHeight * 4));
        ++IndexX;
      } else if (IndexX == 9) {
        IndexX = 0;
        ++IndexY;
        maptiles[x].id = x;
        maptiles[x].sprite->setTextureRect(
            sf::IntRect({IndexX * tileWidth, IndexY * tileHeight},
                        {tileWidth, tileHeight}));
        maptiles[x].sprite->setScale({4, 4});
        // maptiles[x].sprite->setPosition(
        //     sf::Vector2f(IndexX * tileWidth * 4, IndexY * tileHeight * 4));
        ++IndexX;
      }
    }

  } else {
    std::cout << "Did NOT LOAD Dunguon Tilesheet, FAILURE" << std::endl;
  }
}

void Map::Update(float deltaTime) {}

void Map::Draw(sf::RenderWindow &window) {
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 2; x++) {
      int i = x + y * 2;
      maptiles[mapNumbers[i]].sprite->setPosition(
          sf::Vector2f(x * tileWidth * 4, y * tileHeight * 4));
      window.draw(*maptiles[mapNumbers[i]].sprite);
    }
  }
}
