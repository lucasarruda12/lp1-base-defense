#include <bullet.hpp>
#include <iostream>

Bullet::Bullet(float initial_pos_x, float initial_pos_y, float target_pos_x, float target_pos_y){
  std::cout << "fui atirada" << std::endl;

  this->pos.x = initial_pos_x;
  this->pos.y = initial_pos_y;
  this->radius = 10.f;
  this->speed = 1;

  this->target.x = target_pos_x;
  this->target.y = target_pos_y;

  this->sprite.setRadius(this->radius);
  this->sprite.setFillColor(sf::Color::Cyan);
}


void Bullet::render(sf::RenderWindow& window){
  if (this->pos.x != this->target.x || this->pos.y != this->target.y)
    this->moveTowardsTarget();

  this->sprite.setPosition(this->pos.x - radius, this->pos.y - radius);

  window.draw(this->sprite);
}
