#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>
#include <PhysicalObject.hpp>

class Bullet : public PhysicalObject { // TODO: should be private
  public:
    sf::CircleShape sprite;// TODO: should be private

    Bullet(float initial_pos_x, float initial_pos_y, float target_pos_x, float target_pos_y);
    void render(sf::RenderWindow& window);
    void update();
};

#endif
