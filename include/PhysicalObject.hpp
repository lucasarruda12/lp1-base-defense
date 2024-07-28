#ifndef PHYSICALOBJECT_HPP
#define PHYSICALOBJECT_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

class PhysicalObject{
  public:
    float speed; // TODO: should be protected
    float radius; // TODO: should be private

    sf::Vector2f pos;// TODO: should be protected
    sf::Vector2f target;// TODO: should be protected

    void moveTowardsTarget();
    bool checkCollision(const PhysicalObject& other);
};

#endif
