#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <bullet.hpp>
#include <PhysicalObject.hpp>

class Player : private PhysicalObject{ 
  private:
    sf::CircleShape sprite;
    int ammo;

  public:
    Player();
    void render(sf::RenderWindow &window);
    void update();
    void setTarget(sf::Vector2f target);
    sf::Vector2f getPosition();
    int getAmmo();
    void decreaseAmmo(int ammount);
};
#endif
