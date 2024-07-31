#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>
#include <PhysicalObject.hpp>
#include <list>
using std::list;

class Bullet : private PhysicalObject {
  private:
    sf::CircleShape sprite;
    int lifetime;

  public:
    Bullet(sf::Vector2f initial, sf::Vector2f target);
    static list<Bullet*> ObjectList;
    void render(sf::RenderWindow& window);
    void update();
    int getLifetime();
};

#endif
