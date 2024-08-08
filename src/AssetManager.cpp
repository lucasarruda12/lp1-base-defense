#include <AssetManager.hpp>

sf::Font AssetManager::gameFont;

void AssetManager::loadAssets(){
  gameFont.loadFromFile("assets/Minecraftia-Regular.ttf");
}

