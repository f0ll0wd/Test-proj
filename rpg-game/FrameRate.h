#pragma one

#include <SFML/Graphics.hpp>

class FrameRate {
private:
  sf::Font font;
  std::optional<sf::Text> text;
  double time;

public:
  FrameRate();
  ~FrameRate();

  void Initialize();
  void Load();
  void Update(double deltaTime);
  void Draw(sf::RenderWindow &);
};
