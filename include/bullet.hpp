#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>
#include <PhysicalObject.hpp>
#include <list>
using std::list;

class Bullet : public PhysicalObject { // TODO: should be private
  private:
    sf::CircleShape sprite;// TODO: should be private
    int lifetime;

  public:
    static list<Bullet*> ObjectList; 
    static void updateAll();
    static void renderAll(sf::RenderWindow& window);
    Bullet(sf::Vector2f initial, sf::Vector2f target);
    void render(sf::RenderWindow& window);
    void update();
};

#endif
