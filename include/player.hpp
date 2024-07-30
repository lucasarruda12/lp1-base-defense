#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <bullet.hpp>
#include <PhysicalObject.hpp>
#include <RenderGroup.hpp>

class Player : private PhysicalObject{ 
  private:
    sf::CircleShape sprite;
    int ammo;

  public:
    Player();
    void render(sf::RenderWindow &window);
    void handleEvent(sf::Event &event);  // TODO: should be processEvents
    void update();
    sf::Vector2f getPos();
};
#endif
