#pragma once

#include <SFML/Graphics.hpp>
#include <States/State.hpp>
#include <UIElements/Screen.hpp>

class GameOverState: public State
{
  public:
    GameOverState();
    void render(sf::RenderWindow& window);
    void update(){ return; };
    void processEvent(const sf::Event& event);

  private:
    bool drawn;
    Screen screen;
};
