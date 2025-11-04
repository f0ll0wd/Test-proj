#pragma one

#include <SFML/Graphics.hpp>
struct Map {
private:
  sf::Texture texture;
  std::optional<sf::Sprite> sprite;
  int tileWidth;
  int tileHeight;
  int totalX;
  int totalY;

public:
public:
  Map();
  ~Map();

  void Initialize();
  void Load();
  void Update(float deltaTime);
  void Draw(sf::RenderWindow &);
};
