#include <PhysicalObject.hpp>

void PhysicalObject::moveTowardsTarget(){
  if (this->target_x > this->pos_x + 0.5)
    this->pos_x++;

  if (this->target_y > this->pos_y + 0.5)
    this->pos_y++;

  if (this->target_x < this->pos_x - 0.5)
    this->pos_x--;

  if (this->target_y < this->pos_y - 0.5)
    this->pos_y--;
}
