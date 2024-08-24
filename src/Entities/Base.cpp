#include <Constants.hpp>
#include <Entities/Base.hpp>
#include <AssetManager.hpp>

Base::Base()
:PhysicalObject
(
  0,
  BASE_RADIUS,
  sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2),
  sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2)
)
,health(BASE_MAX_HEALTH)
,shield(5)
,shieldRegenCooldownTimer(0)
,shieldRegenTimer(BASE_HEALTH_REGEN_TIMER)
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

  if (shieldRegenCooldownTimer >= 0)
  {
    shieldRegenCooldownTimer--;
    return;
  }

  if (shieldRegenTimer >= 0)
  {
    shieldRegenTimer--;
    return;
  } 

  heal(1);
  shieldRegenTimer = BASE_HEALTH_REGEN_TIMER;
}

void Base::render(sf::RenderWindow& window)
{
  window.draw(sprite);
}

void Base::takeDamage(int amount)
{
  if (shield > 0)
  {
    shield--;
  }
  else {
    health -= amount;
  }

  shieldRegenCooldownTimer = BASE_HEALTH_REGEN_COOLDOWN_TIMER;

  if (health < 0)
  {
    health = 0;
  }
}

int generateRandomNumber() {

    int randomNum = (rand() % 2) + 1;
    return randomNum;
}

void Base::heal(int amount)
{
  shield += amount;

  int randomSound = generateRandomNumber();

    switch(randomSound) {
        case 1:
            sound.setBuffer(AssetManager::bolha1);
            break;
        case 2:
            sound.setBuffer(AssetManager::bolha2);
            break;
    }

    sound.play();
  
  if (shield > 5)
  {
    shield = 5;
  }
}

int Base::getHealth()
{
  return health;
}
