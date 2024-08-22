#pragma once

#include <SFML/Graphics.hpp>

class StatusBar
{
  private:
    sf::RectangleShape container;
    sf::RectangleShape bar;
    float value;
    int maxValue;
    int width;
    int height;

  public:
    StatusBar(
      float maxValue,
      sf::Color fillColor,
      sf::Color outlineColor,
      int top_margin,
      int left_margin,
      int width,
      int height
    );
    void setValue(float value);
    void render(sf::RenderWindow &window);
};
