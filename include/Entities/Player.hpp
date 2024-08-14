#pragma once

#include <SFML/Graphics.hpp>
#include <Entities/PhysicalObject.hpp>
#include <Entities/Bullet.hpp>

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
    Bullet* shoot(sf::Vector2f target);

    int getAmmo();
    void decreaseAmmo(int amount);
    void reload(int amount);
    void takeDamage();
    void heal(int ammount);
    int getHealth();
};
