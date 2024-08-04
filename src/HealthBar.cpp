#include <constants.hpp>
#include <HealthBar.hpp>

sf::RectangleShape HealthBar::points[PLAYER_MAX_HEALTH];

void HealthBar::setHealth(int health){
  if (health > PLAYER_MAX_HEALTH) {
    health = PLAYER_MAX_HEALTH;
  }

  if (health < PLAYER_MIN_HEALTH) {
    health = PLAYER_MIN_HEALTH;
  }

  for (int i = 0; i < PLAYER_MAX_HEALTH; i++) {
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
      points[i].setPosition(430 + 20 * i, 450);
  }
};

void HealthBar::render(sf::RenderWindow &window){
  for (int i = 0; i < PLAYER_MAX_HEALTH; i++){
    window.draw(points[i]);
  }
};
