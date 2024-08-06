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
  this->healthRegenTimer = BASE_HEALTH_REGEN_TIMER;
  this->healthRegenCooldownTimer = 0;

  this->sprite.setPosition(this->pos - sf::Vector2f(this->radius, this->radius));
}

void Base::update(){
  if (this->healthRegenCooldownTimer >= 0){
    this->healthRegenCooldownTimer--;
    return;
  }

  if (this->healthRegenTimer >= 0) {
    this->healthRegenTimer--;
    return;
  } 

  this->heal(1);
  this->healthRegenTimer = BASE_HEALTH_REGEN_TIMER;
}

void Base::render(sf::RenderWindow& window){
  window.draw(this->sprite);
}

void Base::takeDamage(int amount){
  this->health -= amount;
  this->healthRegenCooldownTimer = BASE_HEALTH_REGEN_COOLDOWN_TIMER;

  if (this->health < 0){
    this->health = 0;
  }
}

void Base::heal(int amount) {
  this->health += amount;

  if (this->health > BASE_MAX_HEALTH) {
    this->health = BASE_MAX_HEALTH;
  }
}

int Base::getHealth(){
  return this->health;
}
