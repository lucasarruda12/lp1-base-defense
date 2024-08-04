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
}

void Player::render(sf::RenderWindow& window){
  this->sprite.setPosition(this->pos.x - radius, this->pos.y - radius);
  window.draw(this->sprite);
}

void Player::takeDamage(){
  if (this->health > 0){
    this->health -= 1;
  }
}

int Player::getHealth(){
  return this->health;
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

void Player::reload(int ammount){
  this->ammo += ammount;

  if (this->ammo > 20){
    this->ammo = 20;
  }
}
