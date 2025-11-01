#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode({800, 600}), "Sahpes");
  sf::CircleShape shape(100.f);

  while (window.isOpen()) {
    while (std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }
    window.clear(sf::Color::Black);
    window.draw(shape);
    window.display();
  }
}
