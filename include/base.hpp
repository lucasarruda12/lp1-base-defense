#ifndef INCLUDE_BASE_HPP
#define INCLUDE_BASE_HPP

#include <SFML/Graphics.hpp>

class Base {
  private:
    sf::RectangleShape sprite;
    int health;

  public:
    Base();
    void update();
    void render(sf::RenderWindow& window);
};

#endif
