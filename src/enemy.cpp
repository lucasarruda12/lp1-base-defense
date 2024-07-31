#include "enemy.hpp"
#include "bullet.hpp"

#include <iostream>

#include <list>
using std::list;

list<Enemy*> Enemy::ObjectList;

Enemy::Enemy(sf::Vector2f pos){
  this->radius = 10;
  this->speed = 3;
  this->shootTimer = 60;
  this->pos = pos;

  this->target = sf::Vector2f(640/2, 480/2);

  this->sprite.setRadius(this->radius);
  this->sprite.setFillColor(sf::Color::Red);

  Enemy::ObjectList.push_back(this);
}

void Enemy::updateAll(sf::Vector2f playerPosition){
  auto it = Enemy::ObjectList.begin();

  while(it != Enemy::ObjectList.end()){
    Enemy* enemy = *it;

    enemy->moveTowardsTarget();

    it++;
  }
}

void Enemy::renderAll(sf::RenderWindow& window){
  auto it = Enemy::ObjectList.begin();

  while(it != Enemy::ObjectList.end()){
    Enemy* enemy = *it;

    enemy->sprite.setPosition(enemy->pos.x - enemy->radius, enemy->pos.y - enemy->radius);
    window.draw(enemy->sprite);

    it++;
  }
}
