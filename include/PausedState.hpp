#pragma once

#include <SFML/Graphics.hpp>
#include <State.hpp>

class PausedState : public State
{
  public:
    PausedState();
    void render(sf::RenderWindow& window);
    void update(){ return; };
    void processEvent(const sf::Event& event);

  private:
    bool drawn;
};
