#ifndef INCLUDE_ENEMY_HPP_
#define INCLUDE_ENEMY_HPP_

#include <SFML/Graphics.hpp>
#include <PhysicalObject.hpp>

class Enemy : public PhysicalObject {
    private:
    sf::CircleShape sprite;
    int lifetime;

  public:
    Enemy(sf::Vector2f initial, sf::Vector2f target);
    void render(sf::RenderWindow& window);
    void update();
};

#endif  // INCLUDE_ENEMY_HPP