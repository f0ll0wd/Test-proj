#include <SFML/Graphics/RectangleShape.hpp>
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
  sf::RectangleShape boundingRectangle;
  sf::Vector2i size;
  float speed = 2.0;

public:
  std::optional<sf::Sprite> sprite;

public:
  void Initialize();
  void Load();
  void Update(float deltaTime, Skeleton skeleton);
  void Draw(sf::RenderWindow &);
};
