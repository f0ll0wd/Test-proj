#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#pragma one

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <optional>

class Skeleton {
private:
  sf::Texture texture;

  sf::Font font;
  std::optional<sf::Text> text;

public:
  std::optional<sf::Sprite> sprite;
  sf::RectangleShape boundingRectangle;
  sf::Vector2i size;

  int health;

public:
  Skeleton();
  ~Skeleton();

  void ChangeHealth(int hp);
  void Initialize();
  void Load();
  void Update(float deltaTime);
  void Draw(sf::RenderWindow &);
};
