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
  sf::FloatRect textBounds = pausedText.getLocalBounds();
  pausedText.setOrigin(textBounds.width/2.f, textBounds.height/2.f);
  pausedText.setPosition(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2));
  pausedText.setFillColor(sf::Color::Red);
  window.draw(pausedText);

  pausedText.setString("voce matou X inimigos");
  pausedText.setCharacterSize(16);

  textBounds = pausedText.getLocalBounds();
  pausedText.setOrigin(textBounds.width/2.f, textBounds.height/2.f);

  pausedText.setFillColor(sf::Color::White);
  pausedText.setPosition(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 40));

  window.draw(pausedText);

  pausedText.setString("e sobreviveu X segundos");
  pausedText.setCharacterSize(16);
  textBounds = pausedText.getLocalBounds();
  pausedText.setOrigin(textBounds.width/2.f, textBounds.height/2.f);
  pausedText.setFillColor(sf::Color::White);
  pausedText.setPosition(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 80));
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
