#include <AssetManager.hpp>

// Todas as texturas são carregadas no início da execução do programa
// (Tendo dado start no jogo ou não).

sf::Font AssetManager::gameFont;
sf::Texture AssetManager::background;
sf::Texture AssetManager::base;
sf::Texture AssetManager::player;
sf::Texture AssetManager::enemy;

void AssetManager::loadAssets(){
  gameFont.loadFromFile("assets/Starborn.ttf");
  background.loadFromFile("assets/background.jpg");
  base.loadFromFile("assets/base.png");
  player.loadFromFile("assets/player.png");
  enemy.loadFromFile("assets/enemy.png");
}

