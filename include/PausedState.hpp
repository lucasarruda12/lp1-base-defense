#pragma once

#include <SFML/Graphics.hpp>
#include <State.hpp>

class PausedState : public State
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