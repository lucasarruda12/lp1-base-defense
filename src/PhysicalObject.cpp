#include <PhysicalObject.hpp>

void PhysicalObject::moveTowardsTarget(){
  sf::Vector2f dir(target.x - pos.x, target.y - pos.y);

  float distance = std::sqrt(dir.x * dir.x + dir.y * dir.y);

  dir.x = dir.x / distance;
  dir.y = dir.y / distance;

  if (distance > speed) {
    pos.x += dir.x * speed;
    pos.y += dir.y * speed;
  } else {
    pos.x = target.x;
    pos.y = target.y;
  }
}
