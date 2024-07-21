#ifndef PHYSICALOBJECT_HPP
#define PHYSICALOBJECT_HPP

#include <SFML/Graphics.hpp>

class PhysicalObject{
  public:
    int speed;

    sf::Vector2f pos;
    sf::Vector2f target;

    void moveTowardsTarget();
};

#endif
