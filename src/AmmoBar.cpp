#include <AmmoBar.hpp>

sf::RectangleShape AmmoBar::points[20];

void AmmoBar::setAmmo(int ammo){
  if (ammo > 20) {
    ammo = 20;
  }

  if (ammo < 0) {
    ammo = 0;
  }

  for (int i = 0; i < 20; i++) {
      points[i].setSize(sf::Vector2f(5, 15));
      if (i < ammo) {
          points[i].setFillColor(sf::Color::White);
          points[i].setOutlineColor(sf::Color::White);
          points[i].setOutlineThickness(1.f);
      } else {
          points[i].setFillColor(sf::Color::Black);
          points[i].setOutlineColor(sf::Color::White);
          points[i].setOutlineThickness(1.f);
      }
      points[i].setPosition(430 + 10 * i, 425);
  }
};

void AmmoBar::render(sf::RenderWindow &window){
  for (int i = 0; i < 20; i++){
    window.draw(points[i]);
  }
};
