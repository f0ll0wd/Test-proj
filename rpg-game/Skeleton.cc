#include "Skeleton.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include <locale>
#include <string>

Skeleton::Skeleton() : health(100) {}
Skeleton::~Skeleton() {}

void Skeleton::ChangeHealth(int hp) {
  health += hp;
  text->setString("Skeleton: " + std::to_string((int)(health)));
}

void Skeleton::Initialize() {

  boundingRectangle.setOutlineThickness(2.f);
  boundingRectangle.setOutlineColor(sf::Color::Red);
  boundingRectangle.setFillColor(sf::Color::Transparent);
  size = {64, 64};
}

void Skeleton::Load() {
  if (texture.loadFromFile("../assets/Player/Textures/BODY_skeleton.png")) {
    std::cout << "Loaded Skele texture" << std::endl;
    int Xindex = 5;
    int Yindex = 2;
    sprite = sf::Sprite(texture);
    sprite->setTextureRect(
        sf::IntRect({Xindex * size.x, Yindex * size.y}, {size.x, size.y}));
    sprite->setPosition({400, 500});

    boundingRectangle.setSize(
        {size.x * sprite->getScale().x, size.y * sprite->getScale().y});
  } else {
    std::cout << "Failed to load skele texture" << std::endl;
  }
  if (font.openFromFile("../assets/Fonts/JetBrainsMono-Bold.ttf")) {
    std::cout << "Font for skeleton loaded successfully" << std::endl;
    text = sf::Text(font);
    text->setFillColor(sf::Color::Red);
    text->setCharacterSize(12);
    text->setString("Skeleton: " + std::to_string((int)(health)));
  } else {
    std::cout << "Font for skeleton loaded successfully" << std::endl;
  }
}

void Skeleton::Update(float deltaTime) {
  if (health > 0) {
    boundingRectangle.setPosition(sprite->getPosition());
    text->setPosition(boundingRectangle.getPosition());
  }
}

void Skeleton::Draw(sf::RenderWindow &window) {
  if (health > 0) {
    window.draw(*sprite);
    window.draw(boundingRectangle);
    window.draw(*text);
  }
}
