#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

class PhysicalObject
{
  protected:
    float speed;
    float radius;

    sf::Vector2f pos;
    sf::Vector2f target;

  public:
    PhysicalObject(
      float n_speed,
      float n_radius,
      sf::Vector2f n_pos,
      sf::Vector2f n_target
    );

    void setTarget(sf::Vector2f target);
    void moveTowardsTarget();
    bool checkCollision(const PhysicalObject& other);
    sf::Vector2f getPosition();

    // Aritimética de vetores
    float CalculateVectorMagnitude(sf::Vector2f v);
    sf::Vector2f CalculateUnitVector(sf::Vector2f v);
    sf::Vector2f CalculateUnitVector(sf::Vector2f v, float mag);
};
