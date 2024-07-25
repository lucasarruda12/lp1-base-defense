#include <PhysicalObject.hpp>

void PhysicalObject::moveTowardsTarget(){
  if (this->target.x > this->pos.x + 0.5)
    this->pos.x = this->pos.x + this->speed;

  if (this->target.y > this->pos.y + 0.5)
    this->pos.y = this->pos.y + this->speed;

  if (this->target.x < this->pos.x - 0.5)
    this->pos.x = this->pos.x - this->speed;

  if (this->target.y < this->pos.y - 0.5)
    this->pos.y = this->pos.y - this->speed;
}
