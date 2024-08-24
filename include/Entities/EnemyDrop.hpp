#pragma once

#include <SFML/Graphics.hpp>
#include <Entities/PhysicalObject.hpp>
#include <Entities/Expirable.hpp>

class EnemyDrop
: public PhysicalObject
, public Expirable
{
  public:
    enum Type {
      AmmoBox,
      HealthPack
    };

  public:
    EnemyDrop(sf::Vector2f position, EnemyDrop::Type new_type);
    void update();
    void render(sf::RenderWindow& window);

    EnemyDrop::Type getType() { return this->type; }

  private:
    sf::Sprite sprite;
    EnemyDrop::Type type;
};
