#include "FrameRate.h"
#include "Mymath.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

int main() {
  sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Sahpes");
  window.setFramerateLimit(240);
  FrameRate fps;

  Player player;
  Skeleton skeleton;
  //---------------------------------Initializing---------------------------------
  //---------------------------------Initializing---------------------------------
  player.Initialize();
  skeleton.Initialize();
  fps.Initialize();

  //------------------------------Loading------------------------------------------
  player.Load();
  skeleton.Load();
  fps.Load();
  //------------------------------Loading------------------------------------------

  //-----------------------------Bullet making----------------------------------

  sf::Texture arrow("../assets/WEAPON_arrow.png");
  std::vector<sf::Sprite> bullets;
  float bulletspeed = 0.5f;

  //-----------------------------Bullet making----------------------------------

  //------------------------Updating----------------------------------
  sf::Clock clock;
  while (window.isOpen()) {
    while (std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }
    //------------------------Updating----------------------------------

    sf::Time deltaTimer = clock.restart();
    double deltaTime = deltaTimer.asMicroseconds() / 1000.f;

    fps.Update(deltaTime);
    skeleton.Update(deltaTime);
    player.Update(deltaTime, skeleton);
    auto a = Mymath::CheckSpriteCollision(*skeleton.sprite, *player.sprite);

    //------------------------Drawing------------------------------------
    window.clear(sf::Color::White);

    skeleton.Draw(window);
    player.Draw(window);
    fps.Draw(window);

    window.display();
    //------------------------Drawing------------------------------------
  }
}
