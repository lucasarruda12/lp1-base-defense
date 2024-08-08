#pragma once

#include <SFML/Graphics.hpp>
#include <PhysicalObject.hpp>

class Enemy : public PhysicalObject
{
    private:
    sf::CircleShape sprite;
    int shootTimer;

  public:
    Enemy(sf::Vector2f initial);
    void render(sf::RenderWindow& window);
    void update();
    bool isAbleToShoot();
    void resetShootTimer();
};
