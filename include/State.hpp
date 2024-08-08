#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

class State {
  public:
    enum States
    {
      GameState = 1,
      PausedState,
      GameOverState,
    };

  public:
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void update() = 0;
    virtual void processEvent(const sf::Event& event) = 0;
    void setStageChanger(std::function<void(State::States)> changer){
        stateChanger = changer;
    }

  protected:
    std::function<void(State::States)> stateChanger;
};
