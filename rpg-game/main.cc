#include "Player.h"
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

  Player player;
  Skeleton skeleton;
  //---------------------------------Initializing---------------------------------
  player.Initialize();
  skeleton.Initialize();
  //---------------------------------Initializing---------------------------------

  //------------------------------Loading------------------------------------------
  player.Load();
  skeleton.Load();
  //------------------------------Loading------------------------------------------

  //-----------------------------Bullet making----------------------------------

  sf::Texture arrow("../assets/WEAPON_arrow.png");
  std::vector<sf::Sprite> bullets;
  float bulletspeed = 0.5f;

  //-----------------------------Bullet making----------------------------------

  //------------------------Updating----------------------------------
  while (window.isOpen()) {
    while (std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }
    //------------------------Updating----------------------------------
    skeleton.Update();
    player.Update(skeleton);

    //------------------------Drawing------------------------------------
    window.clear(sf::Color::White);

    skeleton.Draw(window);
    player.Draw(window);

    window.display();
    //------------------------Drawing------------------------------------
  }
}
