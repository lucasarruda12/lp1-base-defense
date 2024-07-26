#ifndef INCLUDE_HEALTHBAR_HPP_
#define INCLUDE_HEALTHBAR_HPP_

#include <SFML/Graphics.hpp>

class HealthBar{
  private:
    static sf::CircleShape points[10];

  public:
    static void setHealth(int points);
    static void render(sf::RenderWindow &window);
      
};

#endif  // INCLUDE_HEALTHBAR_HPP_