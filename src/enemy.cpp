#include <constants.hpp>
#include <enemy.hpp>
#include <iostream>

Enemy::Enemy(sf::Vector2f initial){
  this->radius = ENEMY_HITBOX_RADIUS;
  this->speed = ENEMY_SPEED;
  this->pos = initial;
  this->target = sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
  this->shootTimer = ENEMY_SHOOTTIMER;

  this->sprite.setRadius(this->radius);
  this->sprite.setFillColor(sf::Color::Red);
}

void Enemy::update(){
  this->shootTimer -= 1;
  this->moveTowardsTarget();
}

bool Enemy::isAbleToShoot(){
  return this->shootTimer <= 0;
}

void Enemy::resetShootTimer(){
  this->shootTimer = ENEMY_SHOOTTIMER;
}

void Enemy::render(sf::RenderWindow& window){
  this->sprite.setPosition(this->pos.x - this->radius, this->pos.y - this->radius);
  window.draw(this->sprite);
}
