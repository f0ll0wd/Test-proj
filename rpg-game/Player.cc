#include "Player.h"
#include "Mymath.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

void Player::Initialize() {}

void Player::Load() {
  if (texture.loadFromFile(
          "../assets/Player/Textures/character_base_16x16.png")) {
    std::cout << "Loaded player successfully brooooooooooooooooooo"
              << std::endl;
  } else {
    std::cout << "Did not load player texture correctly!" << std::endl;
  }
  if (arrowtexture.loadFromFile("../assets/WEAPON_arrow.png")) {
    std::cout << "Loaded Arrow successfully brooooooooooooooooooo" << std::endl;
  } else {
    std::cout << "Did not load Arrow texture correctly!" << std::endl;
  }
  sprite = sf::Sprite(texture);
  sprite->setTextureRect(sf::IntRect({0, 0}, {16, 16}));
  sprite->setScale(sf::Vector2f(3.5f, 3.5f));
  sprite->setPosition({1820, 980});
}

void Player::Update(Skeleton skeleton) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
    std::cout << "up button pressed" << std::endl;
    sprite->move({0.f, -0.5f});
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
    std::cout << "down button pressed" << std::endl;
    sprite->move({0.f, +0.5f});
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
    std::cout << "left key button pressed" << std::endl;
    sprite->move({-0.5f, 0.f});
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
    std::cout << "right key button pressed" << std::endl;
    sprite->move({+0.5f, 0.f});
  }
  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
    sf::Sprite arr(arrowtexture, sf::IntRect({12 * 64, 2 * 64}, {64, 64}));
    bullets.push_back(arr);
    auto bull = --bullets.end();
    bull->setPosition(sprite->getPosition());
  }

  for (auto &bullet : bullets) {
    sf::Vector2f bulletdistance =
        skeleton.sprite->getPosition() - bullet.getPosition();
    bulletdistance = Mymath::myNorm(bulletdistance);
    bullet.setPosition(bullet.getPosition() + bulletdistance);
  }
}

void Player::Draw(sf::RenderWindow &window) {
  window.draw(*sprite);
  for (auto bullet : bullets) {
    window.draw(bullet);
  }
}
