#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <math.h>
#include <vector>

int main() {
  sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Sahpes");

  //---------------------texture LOading--------------------------------
  sf::Texture texture;
  if (texture.loadFromFile(
          "../assets/Player/Textures/character_base_16x16.png")) {
    std::cout << "Loaded player successfully" << std::endl;
  } else {
    std::cout << "Did not load player texture correctly!" << std::endl;
  }
  sf::Texture sketexture;
  if (sketexture.loadFromFile("../assets/Player/Textures/BODY_skeleton.png")) {
    std::cout << "Loaded Skele texture" << std::endl;
  } else {
    std::cout << "Failed to load skele texture" << std::endl;
  }
  sf::Sprite skeleton(sketexture, sf::IntRect({5 * 64, 2 * 64}, {64, 64}));

  sf::Sprite standingplyr(texture, sf::IntRect({0, 0}, {16, 16}));
  sf::Sprite standingplyr2(texture, sf::IntRect({1 * 16, 3 * 16}, {16, 16}));
  sf::Sprite standingplyr3(texture, sf::IntRect({3 * 16, 2 * 16}, {16, 16}));

  //---------------------texture LOading--------------------------------

  //-----------------------------Bullet making----------------------------------

  sf::Texture arrow("../assets/WEAPON_arrow.png");
  std::vector<sf::Sprite> bullets;
  standingplyr.setPosition({1820, 980});
  float bulletspeed = 0.5f;

  //-----------------------------Bullet making----------------------------------

  standingplyr2.setPosition({160, 0});
  standingplyr3.setPosition({320, 0});
  standingplyr.scale({3.5f, 3.5f});
  standingplyr2.scale({10, 10});
  standingplyr3.scale({10, 10});
  skeleton.setPosition({400, 700});

  //------------------------Updating----------------------------------

  while (window.isOpen()) {
    while (std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }
    //------------------------Updating----------------------------------

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
      std::cout << "up button pressed" << std::endl;
      standingplyr.move({0.f, -0.5f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
      std::cout << "down button pressed" << std::endl;
      standingplyr.move({0.f, +0.5f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
      std::cout << "left key button pressed" << std::endl;
      standingplyr.move({-0.5f, 0.f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
      std::cout << "right key button pressed" << std::endl;
      standingplyr.move({+0.5f, 0.f});
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
      sf::Sprite arr(arrow, sf::IntRect({12 * 64, 2 * 64}, {64, 64}));
      bullets.push_back(arr);
      auto bull = --bullets.end();
      bull->setPosition(standingplyr.getPosition());
    }

    for (auto &bullet : bullets) {
      sf::Vector2f bulletdistance =
          skeleton.getPosition() - bullet.getPosition();
      bulletdistance = bulletdistance.normalized();
      bullet.setPosition(bullet.getPosition() + bulletdistance);
    }

    //------------------------Drawing------------------------------------

    window.clear(sf::Color::White);
    window.draw(skeleton);
    window.draw(standingplyr);
    for (auto bullet : bullets) {
      window.draw(bullet);
    }
    // window.draw(standingplyr2);
    // window.draw(standingplyr3);
    window.display();

    //------------------------Drawing------------------------------------
  }
}
