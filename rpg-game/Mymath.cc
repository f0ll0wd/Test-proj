#include "Mymath.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <math.h>

sf::Vector2f Mymath::myNorm(sf::Vector2f bulldistance) {
  float mag = std::sqrt(bulldistance.x * bulldistance.x + bulldistance.y +
                        bulldistance.y);
  sf::Vector2f need;
  need.x = bulldistance.x / mag;
  need.y = bulldistance.y / mag;
  return need;
}
