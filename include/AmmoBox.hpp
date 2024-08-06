#ifndef INCLUDE_AMMO_HPP_
#define INCLUDE_AMMO_HPP_

#include <SFML/Graphics.hpp>
#include <PhysicalObject.hpp>

class AmmoBox : public PhysicalObject {
  private:
    sf::CircleShape sprite;
    int lifetime;
    
  public:
    AmmoBox(sf::Vector2f position);
    void update();
    void render(sf::RenderWindow& window);

    bool isExpired();
};

#endif // INCLUDE_AMMO_HPP_
