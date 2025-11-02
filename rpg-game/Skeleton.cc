#include "Skeleton.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

void Skeleton::Initialize() {}

void Skeleton::Load() {
  if (texture.loadFromFile("../assets/Player/Textures/BODY_skeleton.png")) {
    std::cout << "Loaded Skele texture" << std::endl;
  } else {
    std::cout << "Failed to load skele texture" << std::endl;
  }
  sprite = sf::Sprite(texture);
  sprite->setTextureRect(sf::IntRect({5 * 64, 2 * 64}, {64, 64}));
  sprite->setPosition({400, 700});
}

void Skeleton::Update() {}

void Skeleton::Draw(sf::RenderWindow &window) { window.draw(*sprite); }
