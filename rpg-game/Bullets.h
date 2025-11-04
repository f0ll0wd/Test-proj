#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <optional>
#pragma one

#include <SFML/Graphics.hpp>

class Bullets {
private:
  sf::Texture texture;
  std::optional<sf::Sprite> bullet;
  sf::Vector2f direction;
  float speed = 0.5f;

public:
  Bullets();
  ~Bullets();

  inline const sf::FloatRect GetGlobalBounds() {
    return bullet->getGlobalBounds();
  };
  void Initialize(const sf::Vector2f &position, const sf::Vector2f &target);
  void Load();
  void Update(float deltaTime);
  void Draw(sf::RenderWindow &);
};
