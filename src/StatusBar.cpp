#include <StatusBar.hpp>
#include <constants.hpp>

StatusBar::StatusBar
(
  int n_maxValue,
  sf::Color n_fillColor,
  sf::Color n_outlineColor,
  int n_width,
  int n_height,
  int n_top_margin,
  int n_left_margin
)
:maxValue(n_maxValue)
,width(n_width)
,height(n_height)
{
  container.setSize(sf::Vector2f(n_width, n_height));
  container.setOutlineThickness(UI_OUTLINE_THICKNESS);
  container.setOutlineColor(n_outlineColor);
  container.setFillColor(WINDOW_BACKGROUND_COLOR);
  container.setPosition(n_left_margin, n_top_margin);

  bar.setSize(sf::Vector2f(width, height));
  bar.setFillColor(n_fillColor);
  bar.setPosition(n_left_margin, n_top_margin);
}

void StatusBar::setValue(int value)
{
  this->value = value;
  bar.setSize(sf::Vector2f((width/maxValue) * value, height));
}

void StatusBar::render(sf::RenderWindow& window)
{
  window.draw(container);
  window.draw(bar);
}