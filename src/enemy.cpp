#include <enemy.hpp>
#include <iostream>

Enemy::Enemy(sf::Vector2f initial, sf::Vector2f target){
  this->radius = 10;
  this->speed = 3;
  this->pos = initial;
  this->target = target;

  this->sprite.setRadius(this->radius);
  this->sprite.setFillColor(sf::Color::Red);
}

void Enemy::update(){
  this->moveTowardsTarget();
}

void Enemy::render(sf::RenderWindow& window){
  this->sprite.setPosition(this->pos.x - this->radius, this->pos.y - this->radius);
  window.draw(this->sprite);
}