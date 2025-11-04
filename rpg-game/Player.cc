#include "Player.h"
#include "Mymath.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>

Player::Player()
    : bulletspeed(0.5f), speed(2.0f), maxFireRate(200.f), FireRate(0.f) {}

Player::~Player() {}

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

void Player::Update(float deltaTime, Skeleton &skeleton,
                    sf::Vector2f &mousePos) {
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

  boundingRectangle.setPosition(sprite->getPosition());
  if (Mymath::CheckSpriteCollision(skeleton.sprite->getGlobalBounds(),
                                   sprite->getGlobalBounds())) {
    std::cout << "Collisoin player with skeletion" << std::endl;
  }

  FireRate += deltaTime;

  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
      FireRate >= maxFireRate) {
    bullets.push_back(Bullets());
    auto bull = --bullets.end();
    bull->Load();
    bull->Initialize(sprite->getPosition(), mousePos);
    FireRate = 0.f;
  }

  for (auto bullet = bullets.begin(); bullet != bullets.end(); bullet++) {
    bullet->Update(deltaTime);

    if (skeleton.health > 0) {
      std::cout << "Dont see this if skeleton dead if not shit bad cuh"
                << std::endl;
      if (Mymath::CheckSpriteCollision(skeleton.sprite->getGlobalBounds(),
                                       bullet->GetGlobalBounds())) {
        std::cout << "COllision bullet and skeletion" << std::endl;
        skeleton.ChangeHealth(-10);
        bullet = bullets.erase(bullet);
        --bullet;
      }
    }
  }
}

void Player::Draw(sf::RenderWindow &window) {
  window.draw(boundingRectangle);
  window.draw(*sprite);
  for (auto bullet : bullets) {
    bullet.Draw(window);
  }
}
