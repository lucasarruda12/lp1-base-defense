#pragma once

#include <SFML/Graphics.hpp>
#include <Entities/PhysicalObject.hpp>
#include <SFML/Audio.hpp>

class Base : public PhysicalObject
{
  private:
    sf::Sprite sprite;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    
    int health;
    int shield;
    int shieldRegenTimer;
    int shieldRegenCooldownTimer;

  public:
    Base();
    void update();
    void render(sf::RenderWindow& window);

    int getHealth();
    int getShield() { return this->shield; }
    void takeDamage(int amount);
    void heal(int amount);
};
