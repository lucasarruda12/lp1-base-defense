#include <PhysicalObject.hpp>

void PhysicalObject::moveTowardsTarget(){
  if (this->target.x > this->pos.x + 0.5)
    this->pos.x++;

  if (this->target.y > this->pos.y + 0.5)
    this->pos.y++;

  if (this->target.x < this->pos.x - 0.5)
    this->pos.x--;

  if (this->target.y < this->pos.y - 0.5)
    this->pos.y--;
}
