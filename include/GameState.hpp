#pragma once

#include <SFML/Graphics.hpp>
#include <State.hpp>

#include <entityManager.hpp>
#include <UserInterfaceManager.hpp>

class GameState : public State
{
  public:
    GameState();
    void run();

  private:
    UserInterfaceManager ui;
    EntityManager entities;
    int gameTimer;

    void render(sf::RenderWindow& window);
    void update();
    void processEvent(const sf::Event& event);
};
