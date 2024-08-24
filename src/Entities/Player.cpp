#include <Entities/Player.hpp>
#include <Constants.hpp>
#include <AssetManager.hpp>
#include <Entities/PhysicalObject.hpp>

#include <iostream>

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
,sound()
{
  hitbox.setRadius(PLAYER_HITBOX_RADIUS);
  hitbox.setFillColor(sf::Color::Green);

  sprite.setTexture(AssetManager::player);
  sprite.setPosition(pos - sf::Vector2f(radius, radius));
}

void Player::update() { moveTowardsTarget(); }

void Player::render(sf::RenderWindow& window)
{
  sprite.setPosition(pos - sf::Vector2f(radius + 4, radius + 4));
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

int generateRandomNumber() {

    int randomNum = (rand() % 3) + 1;
    return randomNum;
}

void Player::decreaseAmmo(int amount)
{
  this->ammo -= amount;

  if (this->ammo < 0)
  {
    this->ammo = 0;
  }

  int randomSound = generateRandomNumber();

    switch(randomSound) {
        case 1:
            sound.setBuffer(AssetManager::piu1);
            break;
        case 2:
            sound.setBuffer(AssetManager::piu2);
            break;
        case 3:
            sound.setBuffer(AssetManager::piu3);
            break;
    }

    sound.play();
}



void Player::reload(int amount)
{
  this->ammo += amount;

  if (this->ammo > PLAYER_MAX_AMMO)
  {
    this->ammo = PLAYER_MAX_AMMO;
  }
}
