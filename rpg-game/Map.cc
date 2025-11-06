#include "Map.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

Map::Map() : totalX(0), totalY(0) {}
Map::~Map() {}

void Map::Initialize() {}

void Map::Load(MapLoader &m) {
  map = &m;
  if (texture.loadFromFile(map->filevars[0].second)) {
    std::cout << "Loaded Dunguon Tilesheet successfully" << std::endl;
    totalX = texture.getSize().x / std::stoi(map->filevars[2].second);
    totalY = texture.getSize().y / std::stoi(map->filevars[3].second);
    Totaltiles = totalX * totalY;

    maptiles = new Tile[Totaltiles];

    int IndexX = 0;
    int IndexY = 0;

    for (int x = 0; x < Totaltiles; x++) {
      maptiles[x].id = x;
      maptiles[x].Ttexture = &texture;
      std::cout << "Map loaded texture address: " << &texture
                << ", Tiles item texture pointer address: "
                << maptiles[x].Ttexture << std::endl;
      maptiles[x].sprite = sf::Sprite(*maptiles[x].Ttexture);
      if (IndexX < totalX) {
        maptiles[x].sprite->setTextureRect(
            sf::IntRect({IndexX * std::stoi(map->filevars[2].second),
                         IndexY * std::stoi(map->filevars[3].second)},
                        {std::stoi(map->filevars[2].second),
                         std::stoi(map->filevars[3].second)}));
        maptiles[x].sprite->setScale({std::stof(map->filevars[4].second),
                                      std::stof(map->filevars[5].second)});
        ++IndexX;
      } else if (IndexX == totalX) {
        IndexX = 0;
        ++IndexY;
        maptiles[x].id = x;
        maptiles[x].sprite->setTextureRect(
            sf::IntRect({IndexX * std::stoi(map->filevars[2].second),
                         IndexY * std::stoi(map->filevars[3].second)},
                        {std::stoi(map->filevars[2].second),
                         std::stoi(map->filevars[3].second)}));
        maptiles[x].sprite->setScale({std::stof(map->filevars[4].second),
                                      std::stof(map->filevars[5].second)});
        ++IndexX;
      }
    }

  } else {
    std::cout << "Did NOT LOAD Dunguon Tilesheet, FAILURE" << std::endl;
  }
  mm = new int[std::stoi(map->filevars[6].second) *
               std::stoi(map->filevars[7].second)]();
  std::istringstream a(map->filevars[9].second);
  std::string mmt;
  int cc = 0;
  while (a >> mmt) {
    if (std::isdigit(*--mmt.end())) {
      mm[cc] = stoi(mmt);
      ++cc;
    } else {
      mmt.pop_back();
      mm[cc] = stoi(mmt);
      ++cc;
    }
  }
}

void Map::Update(float deltaTime) {}

void Map::Draw(sf::RenderWindow &window) {
  for (int y = 0; y < std::stoi(map->filevars[7].second); y++) {
    for (int x = 0; x < std::stoi(map->filevars[6].second); x++) {
      int i = x + y * std::stoi(map->filevars[6].second);
      maptiles[mm[i]].sprite->setPosition(
          sf::Vector2f(x * std::stoi(map->filevars[2].second) *
                           maptiles[mm[i]].sprite->getScale().x,
                       y * std::stoi(map->filevars[3].second) *
                           maptiles[mm[i]].sprite->getScale().y));
      window.draw(*maptiles[mm[i]].sprite);
    }
  }
}

void Map::memhandler() {
  delete[] maptiles;
  delete[] mm;
};
