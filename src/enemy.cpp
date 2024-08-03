#include <enemy.hpp>
#include <iostream>

Enemy::Enemy(sf::Vector2f initial){
  this->radius = 10;
  this->speed = 1;
  this->pos = initial;
  this->target = sf::Vector2f(640/2, 480/2);
  this->shootTimer = 0;

  this->sprite.setRadius(this->radius);
  this->sprite.setFillColor(sf::Color::Red);
}

void Enemy::update(){
  this->shootTimer += 1;
  this->moveTowardsTarget();
}

bool Enemy::isAbleToShoot(){
  return this->shootTimer >= 60;
}

void Enemy::resetShootTimer(){
  this->shootTimer = 0;
}

void Enemy::render(sf::RenderWindow& window){
  this->sprite.setPosition(this->pos.x - this->radius, this->pos.y - this->radius);
  window.draw(this->sprite);
}
