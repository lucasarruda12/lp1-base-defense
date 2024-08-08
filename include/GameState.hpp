#pragma once

#include <SFML/Graphics.hpp>
#include <State.hpp>

#include <entityManager.hpp>
#include <UserInterfaceManager.hpp>

class GameState : public State
{
  public:
    GameState();
    State::States tipo = State::States::GameState;
    void render(sf::RenderWindow& window);
    void update();
    void processEvent(const sf::Event& event);

  private:
    UserInterfaceManager ui;
    EntityManager entities;
    int gameTimer;
};
