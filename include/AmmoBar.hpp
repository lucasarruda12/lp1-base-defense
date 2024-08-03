
#ifndef INCLUDE_AMMOBAR_HPP_
#define INCLUDE_AMMOBAR_HPP_

#include <SFML/Graphics.hpp>

class AmmoBar{
  private:
    static sf::RectangleShape points[20];

  public:
    static void setAmmo(int points);
    static void render(sf::RenderWindow &window);

};

#endif  // INCLUDE_AMMOBAR_HPP_
