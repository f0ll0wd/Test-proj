#pragma one
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <optional>

struct Tile {
  int id = -1;
  sf::Texture *Ttexture = nullptr;
  std::optional<sf::Sprite> sprite;
};
