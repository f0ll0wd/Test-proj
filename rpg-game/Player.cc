#include "Player.h"
#include "Mymath.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

void Player::Initialize() {

  boundingRectangle.setOutlineThickness(2.f);
  boundingRectangle.setOutlineColor(sf::Color::Blue);
  boundingRectangle.setFillColor(sf::Color::Transparent);
  size = {16, 16};
}

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

  int Xindex = 0;
  int Yindex = 0;

  sprite = sf::Sprite(texture);
  sprite->setTextureRect(
      sf::IntRect({Xindex * size.x, Yindex * size.y}, {size.x, size.y}));
  sprite->setScale(sf::Vector2f(3.f, 3.f));
  sprite->setPosition({0, 0});

  boundingRectangle.setSize(
      {size.x * sprite->getScale().x, size.y * sprite->getScale().y});
  boundingRectangle.setPosition(sprite->getPosition());
}

void Player::Update(float deltaTime, Skeleton skeleton) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
    std::cout << "up button pressed" << std::endl;
    sprite->setPosition(sprite->getPosition() +
                        sf::Vector2f(0.f, -0.5f) * speed * deltaTime);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
    std::cout << "down button pressed" << std::endl;
    sprite->setPosition(sprite->getPosition() +
                        sf::Vector2f(0.f, +0.5f) * speed * deltaTime);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
    std::cout << "left key button pressed" << std::endl;
    sprite->setPosition(sprite->getPosition() +
                        sf::Vector2f(-0.5f, 0.f) * speed * deltaTime);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
    std::cout << "right key button pressed" << std::endl;
    sprite->setPosition(sprite->getPosition() +
                        sf::Vector2f(+0.5f, 0.f) * speed * deltaTime);
  }
  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
    sf::Sprite arr(arrowtexture, sf::IntRect({12 * 64, 2 * 64}, {64, 64}));
    bullets.push_back(arr);
    auto bull = --bullets.end();
    bull->setPosition(sprite->getPosition());
  }
  boundingRectangle.setPosition(sprite->getPosition());

  for (auto &bullet : bullets) {
    sf::Vector2f bulletdistance =
        skeleton.sprite->getPosition() - bullet.getPosition();
    bulletdistance = Mymath::myNorm(bulletdistance);
    bullet.setPosition(bullet.getPosition() + bulletdistance * deltaTime);
    Mymath::CheckSpriteCollision(*skeleton.sprite, bullet);
  }
}

void Player::Draw(sf::RenderWindow &window) {
  window.draw(boundingRectangle);
  window.draw(*sprite);
  for (auto bullet : bullets) {
    window.draw(bullet);
  }
}
