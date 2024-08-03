#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <PhysicalObject.hpp>
#include <HealthBar.hpp>

class Player : public PhysicalObject{ 
  private:
    sf::CircleShape sprite;
    int ammo;
    int health;

  public:
    Player();
    void render(sf::RenderWindow &window);
    void update();
    int getAmmo();
    void decreaseAmmo(int ammount);
    void takeDamage();
    int getHealth();
};

#endif
