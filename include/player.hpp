#pragma once

#include <SFML/Graphics.hpp>
#include <PhysicalObject.hpp>

class Player : public PhysicalObject
{ 
  private:
    sf::CircleShape sprite;
    int ammo;
    int health;

  public:
    Player();
    void render(sf::RenderWindow &window);
    void update();
    int getAmmo();
    void decreaseAmmo(int amount);
    void reload(int amount);
    void takeDamage();
    int getHealth();
};
