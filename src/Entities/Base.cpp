#include <Constants.hpp>
#include <Entities/Base.hpp>
#include <AssetManager.hpp>

Base::Base()
:PhysicalObject
(
  BASE_RADIUS,
  50,
  sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2),
  sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2)
)
,health(BASE_MAX_HEALTH)
,healthRegenCooldownTimer(0)
,healthRegenTimer(BASE_HEALTH_REGEN_TIMER)
,sprite()
{
  sprite.setTexture(AssetManager::base);
  sprite.setPosition(pos - sf::Vector2f(radius, radius));
}

void Base::update()
{
  // A base recupera vida desde que não tenha tomado dano
  // por um período de tempo.

  // Escolhemos implementar isso com dois inteiros. Um que
  // guarda o número de ticks desde que a última vez que a base tomou dano
  // e outro que guarda o número de ticks até a próxima cura.

  // Se ambos são zero, a base recupera vida.

  // Se a base toma dano, o cooldown timer volta pro máximo.

  // Se ela se cura, o regen timer volta pro máximo.

  if (healthRegenCooldownTimer >= 0)
  {
    healthRegenCooldownTimer--;
    return;
  }

  if (healthRegenTimer >= 0)
  {
    healthRegenTimer--;
    return;
  } 

  heal(1);
  healthRegenTimer = BASE_HEALTH_REGEN_TIMER;
}

void Base::render(sf::RenderWindow& window)
{
  window.draw(sprite);
}

void Base::takeDamage(int amount)
{
  health -= amount;
  healthRegenCooldownTimer = BASE_HEALTH_REGEN_COOLDOWN_TIMER;

  if (health < 0)
  {
    health = 0;
  }
}

void Base::heal(int amount)
{
  health += amount;

  if (health > BASE_MAX_HEALTH)
  {
    health = BASE_MAX_HEALTH;
  }
}

int Base::getHealth()
{
  return health;
}
