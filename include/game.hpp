#pragma once

#include <SFML/Graphics.hpp>
#include <State.hpp>

class Game
{
  public:
    Game();
    ~Game();
    void changeState(State::States newState);
    void run();

  private:
    static const sf::Time TimePerFrame;
    sf::RenderWindow window;

    State* currentState;
    State* previousState;
};
