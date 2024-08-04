#include <constants.hpp>
#include <PhysicalObject.hpp>

void PhysicalObject::moveTowardsTarget(){
  sf::Vector2f dir(target.x - pos.x, target.y - pos.y);

  float magnitude = std::sqrt(dir.x * dir.x + dir.y * dir.y);

  dir.x = dir.x / magnitude ;
  dir.y = dir.y / magnitude;

  if (magnitude > speed) {
    pos.x += dir.x * speed;
    pos.y += dir.y * speed;
  } else {
    pos.x = target.x;
    pos.y = target.y;
  }
}

bool PhysicalObject::checkCollision(const PhysicalObject& other){
  sf::Vector2f dist(this->pos.x - other.pos.x, this->pos.y - other.pos.y);
  float sRad = this->radius + other.radius;

  if (dist.x * dist.x + dist.y * dist.y <= sRad*sRad){
    return true;
  } else {
    return false;
  }
}

sf::Vector2f PhysicalObject::getPosition(){
  return this->pos;
}

void PhysicalObject::setTarget(sf::Vector2f target){
  this->target = target;
}
