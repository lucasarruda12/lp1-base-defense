#include <States/GameOverState.hpp>
#include <Constants.hpp>
#include <AssetManager.hpp>

GameOverState::GameOverState()
:drawn(false)
{}

void GameOverState::render(sf::RenderWindow& window)
{
  if (drawn) { return; }

  sf::RectangleShape rectangle;

  // Para causar o efeito de escurecer a tela
  rectangle.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
  rectangle.setFillColor(sf::Color(0,0,0, 100));
  rectangle.setPosition(0, 0);
  window.draw(rectangle);

  // As posições dos textos foram 100% no olhómetro.
  // Não pode mudar o texto de jeito nenhum!!
  sf::Text pausedText("Fim de Jogo!", AssetManager::gameFont);
  pausedText.setCharacterSize(80);
  pausedText.setFillColor(sf::Color::Red);
  pausedText.setPosition(20, WINDOW_HEIGHT - 80);
  window.draw(pausedText);

  pausedText.setString("Voce matou X inimigos");
  pausedText.setCharacterSize(16);
  pausedText.setFillColor(sf::Color::White);
  pausedText.setPosition(20, WINDOW_HEIGHT - 72);
  window.draw(pausedText);

  pausedText.setString("E sobreviveu X segundos");
  pausedText.setCharacterSize(16);
  pausedText.setFillColor(sf::Color::White);
  pausedText.setPosition(20, WINDOW_HEIGHT - 36);
  window.draw(pausedText);
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
