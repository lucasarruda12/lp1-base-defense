#include <PausedState.hpp>
#include <constants.hpp>
#include <AssetManager.hpp>

#include <iostream>

PausedState::PausedState()
:drawn(false)
{}

void PausedState::render(sf::RenderWindow& window)
{
  if (drawn) { return; }

  sf::RectangleShape rectangle;

  // Para causar o efeito de escurecer a tela
  rectangle.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
  rectangle.setFillColor(sf::Color(0,0,0, 100));
  rectangle.setPosition(0, 0);
  window.draw(rectangle);

  sf::Text pausedText("O jogo foi pausado", AssetManager::gameFont);
  pausedText.setCharacterSize(24);
  pausedText.setFillColor(sf::Color::Red);
  pausedText.setPosition(20, WINDOW_HEIGHT - 66);
  window.draw(pausedText);

  pausedText.setString("Aperte ESC para continuar");
  pausedText.setCharacterSize(16);
  pausedText.setFillColor(sf::Color::White);
  pausedText.setPosition(20, WINDOW_HEIGHT - 36);
  window.draw(pausedText);

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
