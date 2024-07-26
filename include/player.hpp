#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <bullet.hpp>
#include <PhysicalObject.hpp>
#include <RenderGroup.hpp>

class Player : private PhysicalObject{ 
  private:
    float radius;
    sf::CircleShape sprite;


  public:
    Player();
    void render(sf::RenderWindow &window);
    void handleEvent(sf::Event &event);
    void update();
};
#endif
