#include "Skeleton.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

void Skeleton::Initialize() {

  boundingRectangle.setOutlineThickness(2.f);
  boundingRectangle.setOutlineColor(sf::Color::Red);
  boundingRectangle.setFillColor(sf::Color::Transparent);
  size = {64, 64};
}

void Skeleton::Load() {
  if (texture.loadFromFile("../assets/Player/Textures/BODY_skeleton.png")) {
    std::cout << "Loaded Skele texture" << std::endl;
  } else {
    std::cout << "Failed to load skele texture" << std::endl;
  }

  int Xindex = 5;
  int Yindex = 2;

  sprite = sf::Sprite(texture);
  sprite->setTextureRect(
      sf::IntRect({Xindex * size.x, Yindex * size.y}, {size.x, size.y}));
  sprite->setPosition({400, 700});

  boundingRectangle.setSize(
      {size.x * sprite->getScale().x, size.y * sprite->getScale().y});
  boundingRectangle.setPosition(sprite->getPosition());
}

void Skeleton::Update(float deltaTime) {}

void Skeleton::Draw(sf::RenderWindow &window) {
  window.draw(*sprite);
  window.draw(boundingRectangle);
}
