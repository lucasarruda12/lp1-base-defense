#include <iostream>

#include <player.hpp>

Player::Player(){
  this->pos.x = 100.f;
  this->pos.y = 200.f;
  this->radius = 10;
  this->speed = 10;

  this->target.x = this->pos.x;
  this->target.y = this->pos.y;

  this->sprite.setRadius(this->radius);
  this->sprite.setFillColor(sf::Color::Green);
}

void Player::update(){
  if (this->pos.x != this->target.x || this->pos.y != this->target.y)
    this->moveTowardsTarget();
}

void Player::render(sf::RenderWindow& window){
  this->sprite.setPosition(this->pos.x - radius, this->pos.y - radius);
  window.draw(this->sprite);
}

void Player::handleEvent(sf::Event &event){
  if (event.type == sf::Event::MouseButtonPressed){
    if (event.mouseButton.button == sf::Mouse::Right){
      this->target.x = event.mouseButton.x;
      this->target.y = event.mouseButton.y;
    }

    if (event.mouseButton.button == sf::Mouse::Left){
      sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

      Bullet* b = new Bullet(this->pos, mousePos);
    }
  }
}
