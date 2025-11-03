#include <SFML/Graphics/RenderWindow.hpp>
#pragma one

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <optional>

class Skeleton {
private:
  sf::Texture texture;

public:
  std::optional<sf::Sprite> sprite;
  sf::RectangleShape boundingRectangle;
  sf::Vector2i size;

public:
  Skeleton();
  ~Skeleton();

  void Initialize();
  void Load();
  void Update(float deltaTime);
  void Draw(sf::RenderWindow &);
};
