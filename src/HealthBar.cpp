#include <HealthBar.hpp>

sf::RectangleShape HealthBar::points[10];

void HealthBar::setHealth(int health){
  if (health > 10) {
    health = 10;
  }

  if (health < 0) {
    health = 0;
  }

  for (int i = 0; i < 10; i++) {
      points[i].setSize(sf::Vector2f(15, 15));
      if (i < health) {
          points[i].setFillColor(sf::Color::Red);
          points[i].setOutlineColor(sf::Color::Red);
          points[i].setOutlineThickness(1.f);
      } else {
          points[i].setFillColor(sf::Color::Black);
          points[i].setOutlineColor(sf::Color::Red);
          points[i].setOutlineThickness(1.f);
      }
      points[i].setPosition(20 + 20 * i, 20);
  }
};

void HealthBar::render(sf::RenderWindow &window){
  for (int i = 0; i < 10; i++){
    window.draw(points[i]);
  }
};
