#include <Entities/Player.hpp>
#include <Constants.hpp>

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
{
  sprite.setRadius(PLAYER_HITBOX_RADIUS);
  sprite.setFillColor(sf::Color::Green);
}

void Player::update() { moveTowardsTarget(); }

void Player::render(sf::RenderWindow& window)
{
  sprite.setPosition(pos - sf::Vector2f(radius, radius));
  window.draw(sprite);
}

int Player::getHealth(){ return health; }

void Player::takeDamage()
{
  if (this->health > PLAYER_MIN_HEALTH)
  {
    this->health -= 1;
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
