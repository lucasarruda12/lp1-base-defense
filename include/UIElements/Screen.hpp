#pragma once

#include <SFML/Graphics.hpp>
#include <string>
using std::string;

class Screen {
  public:
    Screen(const string& title, const string& subtitle);
    Screen(const string& title, const string& subtitle1, const string& subtitle2);

    void render(sf::RenderWindow& window);

  private:
    sf::Text title;
    sf::Text subtitle1;
    sf::Text subtitle2;
};