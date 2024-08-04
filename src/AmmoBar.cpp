#include <constants.hpp>
#include <AmmoBar.hpp>

sf::RectangleShape AmmoBar::points[PLAYER_MAX_AMMO];

void AmmoBar::setAmmo(int ammo){
  if (ammo > PLAYER_MAX_AMMO) {
    ammo = PLAYER_MAX_AMMO;
  }

  if (ammo < PLAYER_MIN_AMMO) {
    ammo = PLAYER_MIN_AMMO;
  }

  for (int i = 0; i < PLAYER_MAX_AMMO; i++) {
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
  for (int i = 0; i < PLAYER_MAX_AMMO; i++){
    window.draw(points[i]);
  }
};
