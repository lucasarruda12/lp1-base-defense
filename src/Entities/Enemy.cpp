#include <Constants.hpp>
#include <Entities/Enemy.hpp>
#include <AssetManager.hpp>

Enemy::Enemy(sf::Vector2f initial)
:PhysicalObject
(
  ENEMY_SPEED,
  ENEMY_HITBOX_RADIUS,
  initial,
  sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2)
)
,shootTimer(ENEMY_SHOOTTIMER)
,sprite()
{
  sprite.setTexture(AssetManager::enemy);
}

bool Enemy::isAbleToShoot()
{
  return shootTimer <= 0;
}

Bullet* Enemy::shoot(sf::Vector2f target)
{
  Bullet* b = new Bullet(pos, target, false);
  resetShootTimer();
  return b;
}

void Enemy::resetShootTimer()
{
  shootTimer = ENEMY_SHOOTTIMER;
}

void Enemy::update()
{
  shootTimer -= 1;
  moveTowardsTarget();
}

void Enemy::render(sf::RenderWindow& window)
{
  sprite.setPosition(pos - sf::Vector2f(radius + 6, radius + 7));
  window.draw(sprite);
}
