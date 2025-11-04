#include "Bullets.h"
#include "Mymath.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

Bullets::Bullets() {}
Bullets::~Bullets() {}

void Bullets::Initialize(const sf::Vector2f &position,
                         const sf::Vector2f &target) {
  bullet->setPosition(position);
  direction = Mymath::myNorm(target - position);
}

void Bullets::Load() {
  if (texture.loadFromFile("../assets/WEAPON_arrow.png")) {
    bullet = sf::Sprite(texture);
    bullet->setTextureRect(sf::IntRect({12 * 64, 2 * 64}, {64, 64}));
  }
}

void Bullets::Update(float deltaTime) {
  bullet->setPosition(bullet->getPosition() + direction * speed * deltaTime);
}

void Bullets::Draw(sf::RenderWindow &window) { window.draw(*bullet); }
