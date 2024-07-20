#include <iostream>
#include <player.hpp>

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
    }
}

void Player::moveTowardsTarget(){
  std::cout << this->pos_x << ", " << this->pos_y << std::endl;

  if (this->target_x > this->pos_x + 0.5)
    this->pos_x++;

  if (this->target_y > this->pos_y + 0.5)
    this->pos_y++;

  if (this->target_x < this->pos_x - 0.5)
    this->pos_x--;

  if (this->target_y < this->pos_y - 0.5)
    this->pos_y--;
}
