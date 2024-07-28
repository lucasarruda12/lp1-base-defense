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

void Bullet::updateAll(){
  auto it = Bullet::ObjectList.begin();

  while(it != Bullet::ObjectList.end()){
    Bullet* bullet = *it;
    bullet->lifetime--;

    bullet->moveTowardsTarget();

    if (bullet->lifetime <= 0){
      it = Bullet::ObjectList.erase(it);
      delete bullet;
    } else {
      it++;
    }

  }
}

void Bullet::renderAll(sf::RenderWindow& window){
  auto it = Bullet::ObjectList.begin();

  while(it != Bullet::ObjectList.end()){
    Bullet* bullet = *it;

    bullet->sprite.setPosition(bullet->pos.x - bullet->radius, bullet->pos.y - bullet->radius);
    window.draw(bullet->sprite);

    it++;
  }
}
