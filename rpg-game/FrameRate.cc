#include "FrameRate.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

FrameRate::FrameRate() : time(0) {}
FrameRate::~FrameRate() {}

void FrameRate::Initialize() {}

void FrameRate::Load() {
  if (font.openFromFile("/usr/share/fonts/TTF/JetBrainsMono-Bold.ttf")) {
    std::cout << "Loaded font successfullly" << std::endl;
    text = sf::Text(font);
    text->setCharacterSize(21);
    text->setFillColor(sf::Color::Red);
  } else {
    std::cout << "Loaded font NOT successfullly" << std::endl;
  }
}

void FrameRate::Update(double deltaTime) {
  time += deltaTime;
  if (time >= 250.f) {
    text->setString(std::to_string((int)(1000.f / deltaTime)));
    time = 0;
  }
}

void FrameRate::Draw(sf::RenderWindow &window) { window.draw(*text); }
