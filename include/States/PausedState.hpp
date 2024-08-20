#pragma once

#include <SFML/Graphics.hpp>
#include <States/State.hpp>
#include <UIElements/Screen.hpp>

class PausedState : public State
{
  public:
    PausedState();
    void render(sf::RenderWindow& window);
    void update(){ return; };
    void processEvent(const sf::Event& event);

  private:
    bool drawn;
    Screen screen;
};
