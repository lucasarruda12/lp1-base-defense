#include <bullet.hpp>
#include <iostream>

Bullet::Bullet(float initial_pos_x, float initial_pos_y, float target_pos_x, float target_pos_y){
  std::cout << "fui atirada" << std::endl;

  this->pos_x = initial_pos_x;
  this->pos_y = initial_pos_y;
  this->radius = 10.f;

  this->target_x = target_pos_x;
  this->target_y = target_pos_y;

  this->sprite.setRadius(this->radius);
  this->sprite.setFillColor(sf::Color::Cyan);

  std::cout << this->pos_x << std::endl;
}


void Bullet::render(sf::RenderWindow& window){
  if (this->pos_x != this->target_x || this->pos_y != this->target_y)
    this->moveTowardsTarget();

  this->sprite.setPosition(this->pos_x - radius, this->pos_y - radius);

  window.draw(this->sprite);
}
