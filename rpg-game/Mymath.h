#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#pragma one

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class Mymath {
public:
  static sf::Vector2f myNorm(sf::Vector2f bulldistance);
  static bool CheckSpriteCollision(sf::FloatRect sp1, sf::FloatRect sp2);
};
