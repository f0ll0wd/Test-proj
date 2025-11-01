#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>

int main() {
  sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Sahpes");
  sf::Texture texture;
  if (texture.loadFromFile(
          "../assets/Player/Textures/character_base_16x16.png")) {
    std::cout << "Loaded player successfully" << std::endl;
  } else {
    std::cout << "Did not load player texture correctly!" << std::endl;
  }
  int Xindex = 0;
  int Yindex = 0;
  sf::Sprite standingplyr(texture, sf::IntRect({0, 0}, {16, 16}));
  sf::Sprite standingplyr2(texture, sf::IntRect({1 * 16, 3 * 16}, {16, 16}));
  sf::Sprite standingplyr3(texture, sf::IntRect({3 * 16, 2 * 16}, {16, 16}));
  standingplyr2.setPosition({160, 0});
  standingplyr3.setPosition({320, 0});
  standingplyr.scale({10, 10});
  standingplyr2.scale({10, 10});
  standingplyr3.scale({10, 10});

  while (window.isOpen()) {
    while (std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
      standingplyr.move({0.f, -0.5f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
      standingplyr.move({0.f, +0.5f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
      standingplyr.move({-0.5f, 0.f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
      standingplyr.move({+0.5f, 0.f});
    }

    window.clear(sf::Color::Black);
    window.draw(standingplyr);
    // window.draw(standingplyr2);
    // window.draw(standingplyr3);
    window.display();
  }
}
