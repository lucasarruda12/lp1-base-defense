#include <constants.hpp>
#include <bullet.hpp>

Bullet::Bullet(sf::Vector2f initial, sf::Vector2f target, bool isPlayerBullet)
:PhysicalObject(
  BULLET_SPEED,
  BULLET_HITBOX_RADIUS,
  initial,
  target
)
,playerBullet(isPlayerBullet)
,lifetime(BULLET_LIFETIME)
,sprite()
{
  sprite.setRadius(BULLET_HITBOX_RADIUS);

  if (isPlayerBullet)
  {
    sprite.setFillColor(sf::Color::White);
    speed += 5;
    lifetime -= 20;
  } 
  else
  {
    sprite.setFillColor(sf::Color::Yellow);
  }

  sf::Vector2f newTarget = target - initial;
  this->target = CalculateUnitVector(newTarget)*1000.f + target;
}

void Bullet::update()
{
  this->lifetime--;
  this->moveTowardsTarget();
}

void Bullet::render(sf::RenderWindow& window)
{
  this->sprite.setPosition(pos - sf::Vector2f(radius, radius));
  window.draw(this->sprite);
}

bool Bullet::isExpired()
{
  return this->lifetime <= 0;
}

bool Bullet::isPlayerBullet()
{
  return this->playerBullet;
}
