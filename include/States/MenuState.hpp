#pragma once

#include <SFML/Graphics.hpp>
#include <States/State.hpp>
#include <UIElements/Screen.hpp>

class MenuState : public State
{
  public:
    MenuState();
    void render(sf::RenderWindow& window);
    void update(){ return; };
    void processEvent(const sf::Event& event);

  private:
    bool drawn;
    Screen screen;
};
