#include <bullet.hpp>
#include <list>
using std::list;

list<Bullet*> Bullet::ObjectList;

Bullet::Bullet(sf::Vector2f initial, sf::Vector2f target){
  this->radius = 3;
  this->speed = 15;
  this->pos = initial;
  
  sf::Vector2f newTarget(target.x - initial.x, target.y - initial.y);

  float magnitude = sqrt(newTarget.x * newTarget.x + newTarget.y * newTarget.y);

  newTarget.x = (newTarget.x/magnitude)*1000 + target.x;
  newTarget.y = (newTarget.y/magnitude)*1000 + target.y;

  this->target = newTarget;

  this->lifetime = 0.5*60;

  this->sprite.setRadius(this->radius);
  this->sprite.setFillColor(sf::Color::White);

  Bullet::ObjectList.push_back(this);
}

void Bullet::update(){
  this->lifetime--;
  this->moveTowardsTarget();
}

void Bullet::render(sf::RenderWindow& window){
  this->sprite.setPosition(this->pos.x - this->radius, this->pos.y - this->radius);
  window.draw(this->sprite);
}

int Bullet::getLifetime(){
  return this->lifetime;
}