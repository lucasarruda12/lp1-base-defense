#include <constants.hpp>
#include <base.hpp>

Base::Base(){
  this->health = BASE_MAX_HEALTH;

  this->sprite.setOutlineThickness(5.f);
  this->sprite.setOutlineColor(sf::Color::White);
  this->sprite.setFillColor(sf::Color::Black);

  this->sprite.setSize(sf::Vector2f(BASE_WIDTH, BASE_HEIGHT));
  this->sprite.setPosition(WINDOW_WIDTH/2 - BASE_WIDTH/2, WINDOW_HEIGHT/2 - BASE_HEIGHT/2);
}

void Base::render(sf::RenderWindow& window){
  window.draw(this->sprite);
}
