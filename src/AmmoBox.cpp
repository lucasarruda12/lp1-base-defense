#include <AmmoBox.hpp>

AmmoBox::AmmoBox(sf::Vector2f position){
  this->radius = 3;
  this->speed = 0;
  this->pos = position;
  this->target = this->pos;

  this->sprite.setRadius(this->radius);
  this->sprite.setFillColor(sf::Color::Yellow);
}

void AmmoBox::render(sf::RenderWindow& window){
  this->sprite.setPosition(this->pos.x - this->radius, this->pos.y - this->radius);
  window.draw(this->sprite);
}
