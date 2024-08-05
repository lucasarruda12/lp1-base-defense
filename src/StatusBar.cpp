#include <StatusBar.hpp>
#include <constants.hpp>

StatusBar::StatusBar(
  int maxValue,
  sf::Color fillColor,
  sf::Color outlineColor,
  int width,
  int height,
  int top_margin,
  int left_margin
  ){
  this->maxValue = maxValue;
  this->width = width;
  this->height = height;

  container.setSize(sf::Vector2f(width, height));
  container.setOutlineThickness(UI_OUTLINE_THICKNESS);
  container.setOutlineColor(outlineColor);
  container.setFillColor(WINDOW_BACKGROUND_COLOR);
  container.setPosition(left_margin, top_margin);

  bar.setSize(sf::Vector2f(width, height));
  bar.setFillColor(fillColor);
  bar.setPosition(left_margin, top_margin);
}

void StatusBar::setValue(int value){
  this->value = value;

  bar.setSize(sf::Vector2f((width/maxValue) * value, height));
}

void StatusBar::render(sf::RenderWindow& window){
  window.draw(container);
  window.draw(bar);
}