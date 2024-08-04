#include <constants.hpp>
#include <bullet.hpp>

Bullet::Bullet(sf::Vector2f initial, sf::Vector2f target, bool isPlayerBullet){
  this->radius = BULLET_HITBOX_RADIUS;
  this->speed = BULLET_SPEED;
  this->pos = initial;
  
  sf::Vector2f newTarget(target.x - initial.x, target.y - initial.y);

  float magnitude = sqrt(newTarget.x * newTarget.x + newTarget.y * newTarget.y);

  newTarget.x = (newTarget.x/magnitude)*1000 + target.x;
  newTarget.y = (newTarget.y/magnitude)*1000 + target.y;

  this->target = newTarget;
  this->playerBullet = isPlayerBullet;
  this->lifetime = BULLET_LIFETIME;

  this->sprite.setRadius(this->radius);

  if (isPlayerBullet){
    this->sprite.setFillColor(sf::Color::White);
    this->speed += 5;
    this->lifetime -= 20;
  } else {
    this->sprite.setFillColor(sf::Color::Yellow);
  }
}

void Bullet::update(){
  this->lifetime--;
  this->moveTowardsTarget();
}

void Bullet::render(sf::RenderWindow& window){
  this->sprite.setPosition(this->pos.x - this->radius, this->pos.y - this->radius);
  window.draw(this->sprite);
}

int Bullet::isExpired(){
  return this->lifetime <= 0;
}

bool Bullet::isPlayerBullet(){
  return this->playerBullet;
}
