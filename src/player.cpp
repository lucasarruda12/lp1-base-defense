#include <iostream>
#include <player.hpp>
#include <bullet.hpp>

Player::Player(){
  this->pos_x = 100.f;
  this->pos_y = 200.f;
  this->radius = 40;

  this->target_x = this->pos_x;
  this->target_y = this->pos_y;

  this->sprite.setRadius(this->radius);
  this->sprite.setFillColor(sf::Color::Cyan);
}

void Player::render(sf::RenderWindow& window){
  if (this->pos_x != this->target_x || this->pos_y != this->target_y)
    this->moveTowardsTarget();

  this->sprite.setPosition(this->pos_x - radius, this->pos_y - radius);

  window.draw(this->sprite);
}

void Player::handleEvent(sf::Event &event){
  if (event.type == sf::Event::MouseButtonPressed){
      if (event.mouseButton.button == sf::Mouse::Right){
        this->target_x = event.mouseButton.x;
        this->target_y = event.mouseButton.y;
      }

      if (event.mouseButton.button == sf::Mouse::Left){
        std::cout << "atirei" << std::endl;
        Bullet b(this->pos_x, this->pos_y, event.mouseButton.x, event.mouseButton.y);
      }
    }
}
