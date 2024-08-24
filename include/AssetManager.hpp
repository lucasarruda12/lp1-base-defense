#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetManager {
  public:
    static void loadAssets();

    static sf::Font gameFont;
    static sf::Texture background;
    static sf::Texture base;
    static sf::Texture player;
    static sf::Texture enemy;
    static sf::Texture cursor;
    static sf::Texture ammo;
    static sf::Texture healthPack;

    static sf::SoundBuffer piu1;
    static sf::SoundBuffer piu2;
    static sf::SoundBuffer piu3;

    static sf::SoundBuffer pow1;
    static sf::SoundBuffer pow2;

    static sf::SoundBuffer bolha1;
    static sf::SoundBuffer bolha2;
};
