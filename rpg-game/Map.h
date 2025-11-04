#pragma one

#include "Tile.h"
#include <SFML/Graphics.hpp>
struct Map {
private:
  sf::Texture texture;
  Tile *maptiles;
  int tileWidth;
  int tileHeight;
  int totalX;
  int totalY;
  int Totaltiles;
  int mapNumbers[6]{
      4, 5, 3, 3, 29, 27,
  };

public:
public:
  Map();
  ~Map();

  void Initialize();
  void Load();
  void Update(float deltaTime);
  void Draw(sf::RenderWindow &);
};
