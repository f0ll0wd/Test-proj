#include "Mymath.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <iostream>
#include <math.h>

sf::Vector2f Mymath::myNorm(sf::Vector2f bulldistance) {
  float mag = std::sqrt(bulldistance.x * bulldistance.x + bulldistance.y +
                        bulldistance.y);
  sf::Vector2f need;
  need.x = bulldistance.x / mag;
  need.y = bulldistance.y / mag;
  return need;
}

bool Mymath::CheckSpriteCollision(sf::FloatRect sp1, sf::FloatRect sp2) {
  if (sp1.findIntersection(sp2)) {
    return true;
  } else {
    return false;
  }

  // sf::Vector2f sp1size({64, 64});
  // sf::Vector2f upperleft = sp1.getPosition();
  // sf::Vector2f upperright(
  //     {upperleft.x + (sp1.getScale().x * sp1size.x), upperleft.y});
  // sf::Vector2f bottomleft(
  //     {upperleft.x, upperleft.y + (sp1.getScale().y * sp1size.y)});
  // sf::Vector2f bottomright({upperleft.x + (sp1.getScale().x * sp1size.x),
  //                           upperleft.y + (sp1.getScale().y * sp1size.y)});
  //
  // sf::Vector2f sp2size({16, 16});
  // sf::Vector2f upperleft2 = sp2.getPosition();
  // sf::Vector2f upperright2(
  //     {upperleft2.x + (sp2.getScale().x * sp2size.x), upperleft2.y});
  // sf::Vector2f bottomleft2(
  //     {upperleft2.x, upperleft2.y + (sp2.getScale().y * sp2size.y)});
  // sf::Vector2f bottomright2({upperleft2.x + (sp2.getScale().x * sp2size.x),
  //                            upperleft2.y + (sp2.getScale().y * sp2size.y)});
  // // std::cout << "Sprite1 Scale X: " << sp1.getScale().x
  // //           << ", Y: " << sp1.getScale().y << std::endl;
  // // std::cout << "Corner getting Scale * 16: " << sp1.getScale().x * 16
  // //           << std::endl;
  // // std::cout << "Sprite1: all corners clockwise: " << upperleft.x << ","
  // //           << upperleft.y << " | " << upperright.x << "," << upperright.y
  // //           << " | " << bottomright.x << "," << bottomright.y << " | "
  // //           << bottomleft.x << "," << bottomleft.y << std::endl;
  // // std::cout << "Sprite2 Scale X: " << sp1.getScale().x
  // //           << ", Y: " << sp1.getScale().y << std::endl;
  // // std::cout << "Sprite2: all corners clockwise: " << upperleft2.x << ","
  // //           << upperleft2.y << " | " << upperright2.x << "," <<
  // upperright2.y
  // //           << " | " << bottomright2.x << "," << bottomright2.y << " | "
  // //           << bottomleft2.x << "," << bottomleft2.y << std::endl;
  //
  // if ((upperright.x > upperleft2.x && upperleft.x < upperright2.x) &&
  //     (upperleft.y < bottomright2.y && bottomleft.y > upperright2.y)) {
  //   std::cout << "Collision happened" << std::endl;
  //   return true;
  // } else {
  //   return false;
  // }
}
