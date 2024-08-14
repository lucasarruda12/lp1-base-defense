#pragma once

#include <SFML/Graphics.hpp>
#include <Entities/PhysicalObject.hpp>
#include <Entities/Bullet.hpp>

class Enemy : public PhysicalObject
{
  private:
    sf::CircleShape sprite;
    int shootTimer;

  public:
    Enemy(sf::Vector2f initial);
    void render(sf::RenderWindow& window);
    void update();
    Bullet* shoot(sf::Vector2f target);

    bool isAbleToShoot();
    void resetShootTimer();
};
