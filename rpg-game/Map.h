#pragma one

#include "MapLoader.h"
#include "Tile.h"
#include <SFML/Graphics.hpp>
struct Map {
private:
  MapLoader *map;
  sf::Texture texture;
  Tile *maptiles;
  int totalX;
  int totalY;
  int Totaltiles;
  int *mm;

public:
  Map();
  ~Map();

  void memhandler();
  void Initialize();
  void Load(MapLoader &);
  void Update(float deltaTime);
  void Draw(sf::RenderWindow &);
};
