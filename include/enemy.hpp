#ifndef INCLUDE_ENEMY_HPP_
#define INCLUDE_ENEMY_HPP_

#include <SFML/Graphics.hpp>
#include "PhysicalObject.hpp"
#include <list>
using std::list;

class Enemy : private PhysicalObject {
  private:
    sf::CircleShape sprite;// TODO: should be private

  public:
    Enemy(sf::Vector2f pos);
    static list<Enemy *> ObjectList;
    static void updateAll(sf::Vector2f playerPosition);
    static void renderAll(sf::RenderWindow& window);
};

#endif
