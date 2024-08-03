#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>
#include <PhysicalObject.hpp>
#include <list>
using std::list;

class Bullet : public PhysicalObject {
  private:
    sf::CircleShape sprite;
    int lifetime;
    bool playerBullet;

  public:
    Bullet(sf::Vector2f initial, sf::Vector2f target, bool isPlayerBullet);
    void render(sf::RenderWindow& window);
    void update();
    int isExpired();
    bool isPlayerBullet();
};

#endif
