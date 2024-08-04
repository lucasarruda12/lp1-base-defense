#include <player.hpp>
#include <constants.hpp>

Player::Player(){
  this->pos.x = PLAYER_SPAWN_X;
  this->pos.y = PLAYER_SPAWN_Y;
  this->radius = PLAYER_HITBOX_RADIUS;
  this->speed = PLAYER_SPEED;
  this->ammo = PLAYER_MAX_AMMO;

  this->target.x = this->pos.x;
  this->target.y = this->pos.y;

  this->sprite.setRadius(this->radius);
  this->sprite.setFillColor(sf::Color::Green);
  this->health = PLAYER_MAX_HEALTH;
}

void Player::update(){
  if (this->pos.x != this->target.x || this->pos.y != this->target.y)
    this->moveTowardsTarget();
}

void Player::render(sf::RenderWindow& window){
  this->sprite.setPosition(this->pos.x - radius, this->pos.y - radius);
  window.draw(this->sprite);
}

int Player::getHealth(){
  return this->health;
}

void Player::takeDamage(){
  if (this->health > PLAYER_MIN_HEALTH){
    this->health -= 1;
  }
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

  if (this->ammo > PLAYER_MAX_AMMO){
    this->ammo = PLAYER_MAX_AMMO;
  }
}
