#include <constants.hpp>
#include <base.hpp>

#include <iostream>

Base::Base(){
  this->health = BASE_MAX_HEALTH;
  this->radius = 50;

  this->sprite.setRadius(this->radius);
  this->sprite.setOutlineThickness(5.f);
  this->sprite.setOutlineColor(sf::Color::White);
  this->sprite.setFillColor(sf::Color::Black);
  this->pos = sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
  this->target = this->pos;
  this->speed = 0;

  this->sprite.setPosition(this->pos - sf::Vector2f(this->radius, this->radius));
}

void Base::render(sf::RenderWindow& window){
  window.draw(this->sprite);
}
