#include <States/GameOverState.hpp>
#include <Constants.hpp>
#include <AssetManager.hpp>
#include <string>

GameOverState::GameOverState(int deathCounter)
:drawn(false)
,screen("Game Over", "You killed " + std::to_string(deathCounter) + " enemies")
{}

void GameOverState::render(sf::RenderWindow& window)
{
  // Essas telas só precisam ser desenhadas uma vez.
  if (drawn) { return; }

  // Para causar o efeito de escurecer a tela
  sf::RectangleShape rectangle;
  rectangle.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
  rectangle.setFillColor(sf::Color(0,0,0, 100));
  rectangle.setPosition(0, 0);
  window.draw(rectangle);

  screen.render(window);
  window.display();
  drawn = true;
}

void GameOverState::processEvent(const sf::Event& event)
{
  if (event.type == sf::Event::KeyPressed)
  {
    if (event.key.code == sf::Keyboard::Escape)
    {
      stateChanger(State::States::GameState);
    }
  }
}
