#include <constants.hpp>
#include <AmmoBox.hpp>

AmmoBox::AmmoBox(sf::Vector2f position)
:PhysicalObject
(
  0,
  AMMOBOX_HITBOX_RADIUS,
  position,
  position
)
,lifetime(AMMOBOX_LIFETIME)
,sprite()
{
  sprite.setRadius(this->radius);
  sprite.setFillColor(sf::Color(150,75,0,255));
}

void AmmoBox::update()
{
  this->lifetime--;
}

bool AmmoBox::isExpired()
{
  return this->lifetime <= 0;
}

void AmmoBox::render(sf::RenderWindow& window)
{
  this->sprite.setPosition(this->pos.x - this->radius, this->pos.y - this->radius);
  window.draw(this->sprite);
}
