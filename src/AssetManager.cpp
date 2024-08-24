#include <AssetManager.hpp>

// Todas as texturas são carregadas no início da execução do programa
// (Tendo dado start no jogo ou não).

sf::Font AssetManager::gameFont;
sf::Texture AssetManager::background;
sf::Texture AssetManager::base;
sf::Texture AssetManager::player;
sf::Texture AssetManager::enemy;
sf::Texture AssetManager::cursor;
sf::Texture AssetManager::ammo;
sf::Texture AssetManager::healthPack;

sf::SoundBuffer AssetManager::piu1;
sf::SoundBuffer AssetManager::piu2;
sf::SoundBuffer AssetManager::piu3;

void AssetManager::loadAssets(){
  gameFont.loadFromFile("assets/Minecraftia-Regular.ttf");
  background.loadFromFile("assets/background.jpg");
  base.loadFromFile("assets/base.png");
  player.loadFromFile("assets/player.png");
  enemy.loadFromFile("assets/enemy.png");
  cursor.loadFromFile("assets/cursor.png");
  ammo.loadFromFile("assets/ammo.png");
  healthPack.loadFromFile("assets/healthpack.png");

  piu1.loadFromFile("assets/Audio/piu1.wav");
  piu2.loadFromFile("assets/Audio/piu2.wav");
  piu3.loadFromFile("assets/Audio/piu3.wav");
}

