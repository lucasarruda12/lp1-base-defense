#include <HealthBar.hpp>

sf::CircleShape HealthBar::points[10];

void HealthBar::setHealth(int health){
  if (health > 10) {
    health = 10;
  }

  if (health < 0) {
    health = 0;
  }

  for (int i = 0; i < 10; i++) {
      points[i].setRadius(10);
      if (i < health) {
          points[i].setFillColor(sf::Color::Green);
      } else {
          points[i].setFillColor(sf::Color::Red);
      }
      points[i].setPosition(400 + 20 * i, 20);
  }
};

void HealthBar::render(sf::RenderWindow &window){
  for (int i = 0; i < 10; i++){
    window.draw(points[i]);
  }
};