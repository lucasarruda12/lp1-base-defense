#pragma once

#include <SFML/Graphics.hpp>
#include <State.hpp>

class Game
{
  public:
    Game();
    void run();

  private:
    static const sf::Time TimePerFrame;
    sf::RenderWindow window;

    State* currentState;
    State* previousState;
};
