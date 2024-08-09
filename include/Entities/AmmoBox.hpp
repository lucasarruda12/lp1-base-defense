#pragma once

#include <SFML/Graphics.hpp>
#include <Entities/PhysicalObject.hpp>
#include <Entities/Expirable.hpp>

class AmmoBox
: public PhysicalObject
, public Expirable
{
  private:
    sf::CircleShape sprite;

  public:
    AmmoBox(sf::Vector2f position);
    void update();
    void render(sf::RenderWindow& window);
};
