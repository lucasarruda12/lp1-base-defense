#pragma once

#include <SFML/Graphics.hpp>
#include <map>
using std::map;

class AssetManager {
  public:
    static void loadAssets();
    static void freeAssets();

    static sf::Font gameFont;
};
