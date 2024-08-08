#include <PausedState.hpp>

PausedState::PausedState()
:pausedText()
,font()
{
  font.loadFromFile("assets/Minecraftia-Regular.ttf");
  pausedText.setFont(font);
}

void PausedState::render(sf::RenderWindow& window){
  window.clear();
  window.draw(pausedText);
  window.display();
}

void PausedState::processEvent(const sf::Event& event){
  if (event.type == sf::Event::MouseButtonPressed)
  {
    stateChanger(State::States::GameState);
  }
}