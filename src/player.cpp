#include <player.hpp>

Player::Player(){
  this->pos.x = 100.f;
  this->pos.y = 200.f;
  this->radius = 10;
  this->speed = 10;
  this->ammo = 20;

  this->target.x = this->pos.x;
  this->target.y = this->pos.y;

  this->sprite.setRadius(this->radius);
  this->sprite.setFillColor(sf::Color::Green);
  this->health = 10;
}

void Player::update(){
  if (this->pos.x != this->target.x || this->pos.y != this->target.y)
    this->moveTowardsTarget();

  HealthBar::setHealth(this->health);
}

void Player::render(sf::RenderWindow& window){
  this->sprite.setPosition(this->pos.x - radius, this->pos.y - radius);
  window.draw(this->sprite);

  HealthBar::render(window);
}

void Player::takeDamage(){
  this->health -= 1;
}

int Player::getAmmo(){
  return this->ammo;
}

void Player::decreaseAmmo(int ammount){
  this->ammo -= ammount;

  if (this->ammo < 0) {
    this->ammo = 0;
  }
}
