#include <Entities/Player.hpp>
#include <Constants.hpp>
#include <AssetManager.hpp>
#include <Entities/PhysicalObject.hpp>

Player::Player()
:PhysicalObject(
  PLAYER_SPEED,
  PLAYER_HITBOX_RADIUS,
  sf::Vector2f(PLAYER_SPAWN_X, PLAYER_SPAWN_Y),
  sf::Vector2f(PLAYER_SPAWN_X, PLAYER_SPAWN_Y)
)
,ammo(PLAYER_MAX_AMMO)
,health(PLAYER_MAX_HEALTH)
,sprite()
,hitbox()
{
  hitbox.setRadius(PLAYER_HITBOX_RADIUS);
  hitbox.setFillColor(sf::Color::Green);

  sprite.setTexture(AssetManager::player);
  sprite.setScale(0.05, 0.05);
  sprite.setPosition(pos - sf::Vector2f(radius + 14, radius + 15));
}

void Player::update() { moveTowardsTarget(); }

void Player::render(sf::RenderWindow& window)
{
  hitbox.setPosition(pos - sf::Vector2f(radius, radius));
  window.draw(hitbox);

  sprite.setPosition(pos - sf::Vector2f(radius + 14, radius + 15));
  window.draw(sprite);
}

Bullet* Player::shoot(sf::Vector2f target)
{
  Bullet* b = new Bullet(pos, target, true);
  decreaseAmmo(1);
  return b;
}

int Player::getHealth(){ return health; }

void Player::takeDamage()
{
  if (this->health > PLAYER_MIN_HEALTH)
  {
    this->health -= 1;
  }
}

void Player::heal(int amount)
{
  this->health += amount;
  
  if (this->health > PLAYER_MAX_HEALTH)
  {
    this->health = PLAYER_MAX_HEALTH;
  }
}

int Player::getAmmo(){ return ammo; }

void Player::decreaseAmmo(int amount)
{
  this->ammo -= amount;

  if (this->ammo < 0)
  {
    this->ammo = 0;
  }
}

void Player::reload(int amount)
{
  this->ammo += amount;

  if (this->ammo > PLAYER_MAX_AMMO)
  {
    this->ammo = PLAYER_MAX_AMMO;
  }
}
