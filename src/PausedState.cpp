#include <PausedState.hpp>
#include <constants.hpp>

#include <iostream>

PausedState::PausedState()
:drawn(false)
{}

void PausedState::render(sf::RenderWindow& window)
{
  if (drawn) { return; }

  sf::RectangleShape rectangle;

  rectangle.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
  rectangle.setFillColor(sf::Color(0,0,0, 100));
  rectangle.setPosition(0, 0);
  window.draw(rectangle);
  window.display();

  drawn = true;
}

void PausedState::processEvent(const sf::Event& event)
{
  if (event.type == sf::Event::KeyPressed)
  {
    if (event.key.code == sf::Keyboard::Escape)
    {
      stateChanger(State::States::Previous);
    }
  }
}