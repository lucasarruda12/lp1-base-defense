#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player{
  private:
    float pos_x;
    float pos_y;
    float radius;

    float target_x;
    float target_y;

    sf::CircleShape sprite;


  public:
    Player();
    void render(sf::RenderWindow &window);
    void handleEvent(sf::Event &event);
    void moveTowardsTarget();
};
#endif
