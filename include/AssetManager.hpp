#pragma once

#include <SFML/Graphics.hpp>

class AssetManager {
  public:
    static void loadAssets();

    static sf::Font gameFont;
    static sf::Texture background;
    static sf::Texture base;
    static sf::Texture player;
    static sf::Texture enemy;
};
