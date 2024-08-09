#pragma once

#include <SFML/Graphics.hpp>

class AssetManager {
  public:
    static void loadAssets();
    static void freeAssets();

    static sf::Font gameFont;
};
