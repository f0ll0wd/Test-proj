#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#pragma one
#include "Skeleton.h"
#include <SFML/Graphics.hpp>
class Player {
private:
  sf::Texture texture;
  sf::Texture arrowtexture;
  float bulletspeed;
  std::vector<sf::Sprite> bullets;
  sf::RectangleShape boundingRectangle;
  sf::Vector2i size;
  float speed;

public:
  std::optional<sf::Sprite> sprite;

public:
  Player();
  ~Player();

  void Initialize();
  void Load();
  void Update(float deltaTime, Skeleton skeleton);
  void Draw(sf::RenderWindow &);
};
