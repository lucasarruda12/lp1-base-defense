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

bool PhysicalObject::checkCollisionWithBase(){
  // Se o x do inimigo está entre base.x - raio do inimigo e base.x + tamanho da base - raio do inimigo
  // E se o y do inimigo está entre base.y - raio do inimigo e base.y + tamanho da base - raio do inimigo
  
  float base_x = WINDOW_WIDTH/2 - BASE_WIDTH/2;
  float base_y = WINDOW_HEIGHT/2 - BASE_HEIGHT/2;

  bool isInsideBase_x = base_x < this->pos.x & this->pos.x < base_x + BASE_WIDTH;
  bool isInsideBase_y = base_y < this->pos.y & this->pos.y < base_y + BASE_HEIGHT;

  return isInsideBase_x & isInsideBase_y;
}

sf::Vector2f PhysicalObject::getPosition(){
  return this->pos;
}

void PhysicalObject::setTarget(sf::Vector2f target){
  this->target = target;
}
