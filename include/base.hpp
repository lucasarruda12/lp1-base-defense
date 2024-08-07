#ifndef INCLUDE_BASE_HPP
#define INCLUDE_BASE_HPP

#include <SFML/Graphics.hpp>
#include <PhysicalObject.hpp>

class Base : public PhysicalObject
{
  private:
    sf::CircleShape sprite;
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

#endif
