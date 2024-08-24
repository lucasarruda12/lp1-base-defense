#pragma once

#include <SFML/Graphics.hpp>
#include <States/State.hpp>
#include <SFML/Audio.hpp>
#include <AssetManager.hpp>
#include <EntityManager.hpp>
#include <UserInterfaceManager.hpp>

class GameState : public State
{
  public:
    GameState();
    void render(sf::RenderWindow& window);
    void update();
    void processEvent(const sf::Event& event);
    int getDeathCounter(){ return entities.getEnemiesKilled(); }

  private:
    UserInterfaceManager ui;
    EntityManager entities;
    int gameTimer;
    sf::Sound sound;
};
