#ifndef INCLUDE_AMMO_HPP_
#define INCLUDE_AMMO_HPP_

#include <SFML/Graphics.hpp>
#include <PhysicalObject.hpp>

class AmmoBox : public PhysicalObject {
  private:
    sf::CircleShape sprite;
    
  public:
    AmmoBox(sf::Vector2f position);
    void render(sf::RenderWindow& window);
};

#endif // INCLUDE_AMMO_HPP_
