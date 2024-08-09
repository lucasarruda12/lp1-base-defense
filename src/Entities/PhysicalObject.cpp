#include <Constants.hpp>
#include <Entities/PhysicalObject.hpp>

PhysicalObject::PhysicalObject(
  float n_speed,
  float n_radius,
  sf::Vector2f n_pos,
  sf::Vector2f n_target
)
:speed(n_speed)
,radius(n_radius)
,pos(n_pos)
,target(n_target)
{}

void PhysicalObject::moveTowardsTarget()
{
  sf::Vector2f dir(target.x - pos.x, target.y - pos.y);

  float magnitude = CalculateVectorMagnitude(dir);
  dir = CalculateUnitVector(dir, magnitude);

  if (magnitude > speed)
  {
    pos.x += dir.x * speed;
    pos.y += dir.y * speed;
  }
  else 
  {
    pos.x = target.x;
    pos.y = target.y;
  }
}

bool PhysicalObject::checkCollision(const PhysicalObject& other)
{
  sf::Vector2f dist(this->pos.x - other.pos.x, this->pos.y - other.pos.y);
  float sRad = this->radius + other.radius;

  return dist.x * dist.x + dist.y * dist.y <= sRad*sRad;
}

sf::Vector2f PhysicalObject::getPosition()
{
  return this->pos;
}

void PhysicalObject::setTarget(sf::Vector2f target)
{
  this->target = target;
}


float PhysicalObject::CalculateVectorMagnitude(sf::Vector2f v)
{
  return std::sqrt(v.x * v.x + v.y * v.y);
}

sf::Vector2f PhysicalObject::CalculateUnitVector(sf::Vector2f v)
{
  float mag = CalculateVectorMagnitude(v);

  return sf::Vector2f(v/mag);
}

sf::Vector2f PhysicalObject::CalculateUnitVector(sf::Vector2f v, float mag)
{
  return v/mag;
}
