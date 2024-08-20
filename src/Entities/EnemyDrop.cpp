#include <Constants.hpp>
#include <Entities/EnemyDrop.hpp>

EnemyDrop::EnemyDrop(sf::Vector2f position, EnemyDrop::Type new_type)
:PhysicalObject
(
  0,
  ENEMYDROP_HITBOX_RADIUS,
  position,
  position
)
,Expirable(
  ENEMYDROP_LIFETIME
  // Balas e Drops expiram. Existe um inteiro que conta os ticks
  // passados desde a criação dessas entidades. Quando o inteiro chega a um certo valor,
  // a entidade passa a ser expirada. A entitymanager checa todas as entidades expiráveis
  // a cada tick e remove as que já expiraram.
)
,sprite()
,type(new_type)
{
  if (new_type == EnemyDrop::Type::AmmoBox)
  {
    sprite.setFillColor(sf::Color::White);
  }

  if (new_type == EnemyDrop::Type::HealthPack)
  {
    sprite.setFillColor(sf::Color::Red);
  }
  
  sprite.setRadius(this->radius);
}

void EnemyDrop::update()
{
  age();
}

void EnemyDrop::render(sf::RenderWindow& window)
{
  this->sprite.setPosition(this->pos.x - this->radius, this->pos.y - this->radius);
  window.draw(this->sprite);
}
