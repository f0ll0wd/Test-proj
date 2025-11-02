#include <SFML/Graphics/RenderWindow.hpp>
#pragma one
#include "Skeleton.h"
#include <SFML/Graphics.hpp>
class Player {
private:
  sf::Texture texture;
  sf::Texture arrowtexture;
  float bulletspeed = 0.5f;
  std::vector<sf::Sprite> bullets;

public:
  std::optional<sf::Sprite> sprite;

public:
  void Initialize();
  void Load();
  void Update(Skeleton skeleton);
  void Draw(sf::RenderWindow &);
};
