#pragma once

#include <SFML/Graphics.hpp>
#include <Entities/PhysicalObject.hpp>

class Base : public PhysicalObject
{
  private:
    sf::Sprite sprite;
    int health;
    int healthRegenTimer;
    int healthRegenCooldownTimer;

  public:
    Base();
    void update();
    void render(sf::RenderWindow& window);

    int getHealth();
    void takeDamage(int amount);
    void heal(int amount);
};
