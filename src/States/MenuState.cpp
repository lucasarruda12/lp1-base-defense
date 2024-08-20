#include <States/MenuState.hpp>
#include <Constants.hpp>
#include <AssetManager.hpp>

MenuState::MenuState()
:drawn(false)
,screen("LP1 BASE DEFENSE", "press [SPACE] to start")
{}

void MenuState::render(sf::RenderWindow& window)
{
  // Essas telas só precisam ser desenhadas uma vez.
  if (drawn) { return; }
  window.clear();

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

void MenuState::processEvent(const sf::Event& event)
{
  if (event.type == sf::Event::KeyPressed)
  {
    if (event.key.code == sf::Keyboard::Space)
    {
      stateChanger(State::States::GameState);
    }
  }
}
