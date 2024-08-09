#pragma once

#include <SFML/Graphics.hpp>
#include <PhysicalObject.hpp>
#include <Expirable.hpp>

class Bullet
: public PhysicalObject
, public Expirable
{
  private:
    sf::CircleShape sprite;
    bool playerBullet;

  public:
    Bullet(sf::Vector2f initial, sf::Vector2f target, bool isPlayerBullet);
    void render(sf::RenderWindow& window);
    void update();
    bool isPlayerBullet();
};
