#include <iostream>
#include <player.hpp>
#include <bullet.hpp>

Player::Player(){
  this->pos.x = 100.f;
  this->pos.y = 200.f;
  this->radius = 40;

  this->target.x = this->pos.x;
  this->target.y = this->pos.y;

  this->sprite.setRadius(this->radius);
  this->sprite.setFillColor(sf::Color::Cyan);
}

void Player::render(sf::RenderWindow& window){
  if (this->pos.x != this->target.x || this->pos.y != this->target.y)
    this->moveTowardsTarget();

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
        std::cout << "atirei" << std::endl;
        Bullet b(this->pos.x, this->pos.y, event.mouseButton.x, event.mouseButton.y);
      }
    }
}
