#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#pragma one
#include "Bullets.h"
#include "Skeleton.h"
#include <SFML/Graphics.hpp>
class Player {
private:
  sf::Texture texture;
  sf::Texture arrowtexture;
  float bulletspeed;
  std::vector<Bullets> bullets;
  sf::RectangleShape boundingRectangle;
  sf::Vector2i size;
  float speed;
  float maxFireRate;
  float FireRate;

public:
  std::optional<sf::Sprite> sprite;

public:
  Player();
  ~Player();

  void Initialize();
  void Load();
  void Update(float deltaTime, Skeleton &skeleton, sf::Vector2f &mousePos);
  void Draw(sf::RenderWindow &);
};
