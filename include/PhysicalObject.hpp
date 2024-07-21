#ifndef PHYSICALOBJECT_HPP
#define PHYSICALOBJECT_HPP

#include <SFML/Graphics.hpp>

class PhysicalObject{
  public:
    int speed;

    float pos_x;
    float pos_y;

    float target_x;
    float target_y;

    void moveTowardsTarget();
};

#endif
