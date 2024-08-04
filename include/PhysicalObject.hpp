#ifndef PHYSICALOBJECT_HPP
#define PHYSICALOBJECT_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

class PhysicalObject{
  protected:
    float speed; // TODO: should be protected
    float radius; // TODO: should be private

    sf::Vector2f pos;// TODO: should be protected
    sf::Vector2f target;// TODO: should be protected

  public:
    void setTarget(sf::Vector2f target);
    void moveTowardsTarget();
    bool checkCollision(const PhysicalObject& other);
    bool checkCollisionWithBase();
    sf::Vector2f getPosition();
};

#endif
