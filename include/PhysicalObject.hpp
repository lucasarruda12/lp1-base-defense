#ifndef PHYSICALOBJECT_HPP
#define PHYSICALOBJECT_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

class PhysicalObject{
  public:
    float speed;

    sf::Vector2f pos;
    sf::Vector2f target;

    void moveTowardsTarget();
};

#endif
