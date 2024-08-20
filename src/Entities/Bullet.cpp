#include <Constants.hpp>
#include <Entities/Bullet.hpp>

Bullet::Bullet(sf::Vector2f initial, sf::Vector2f target, bool isPlayerBullet)
:PhysicalObject(
  BULLET_SPEED,
  BULLET_HITBOX_RADIUS,
  initial,
  target
)
,Expirable(
  BULLET_LIFETIME 
  // Balas e Drops expiram. Existe um inteiro que conta os ticks
  // passados desde a criação dessas entidades. Quando o inteiro chega a um certo valor,
  // a entidade passa a ser expirada. A entitymanager checa todas as entidades expiráveis
  // a cada tick e remove as que já expiraram.
)
,playerBullet(isPlayerBullet)
,sprite()
{
  sprite.setRadius(BULLET_HITBOX_RADIUS);

  if (isPlayerBullet)
  {
    sprite.setFillColor(sf::Color::White);
    speed += 5;
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
  age();
  moveTowardsTarget();
}

void Bullet::render(sf::RenderWindow& window)
{
  this->sprite.setPosition(pos - sf::Vector2f(radius, radius));
  window.draw(this->sprite);
}

bool Bullet::isPlayerBullet()
{
  return this->playerBullet;
}
