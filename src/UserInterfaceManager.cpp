#include <UserInterfaceManager.hpp>
#include <Constants.hpp>
#include <AssetManager.hpp>

// Montamos a interface do jogo com barrinhas.
// Os indicadores de vida, bala, vida da base são todos
// retângulos que são redimencionados ao longo do jogo.
UserInterfaceManager::UserInterfaceManager()
: playerHealthBar(
  PLAYER_MAX_HEALTH,      // Valor máximo da barra
  sf::Color::Red,         // Cor do indicador
  sf::Color::White,       // Cor do Outline
  UI_WIDTH,               // Largura da barrinha
  UI_HEIGHT,              // Tamanho da barrinha
  UI_TOP_MARGIN,          // Margem do topo
  UI_LEFT_MARGIN          // Margem da esquerda
)
,playerAmmoBar(
  PLAYER_MAX_AMMO,
  sf::Color::White,
  sf::Color::White,
  UI_WIDTH,
  UI_HEIGHT/2,
  UI_TOP_MARGIN + UI_HEIGHT + UI_AMMO_BAR_VERTICAL_OFFSET,
  UI_LEFT_MARGIN
)
,baseHealthBar(
  BASE_MAX_HEALTH,
  sf::Color::Red,
  sf::Color::Red,
  BASE_RADIUS*2,
  UI_HEIGHT/4,
  WINDOW_HEIGHT/2 + BASE_RADIUS + 10,
  WINDOW_WIDTH/2 - UI_WIDTH/3
)
,baseShieldBar(
  5,
  sf::Color::Blue,
  sf::Color::Blue,
  BASE_RADIUS*2,
  UI_HEIGHT/4,
  WINDOW_HEIGHT/2 + BASE_RADIUS + 20,
  WINDOW_WIDTH/2 - UI_WIDTH/3
)
,background()
,cursor()
,killCounter("0", AssetManager::gameFont)
{
  background.setTexture(AssetManager::background);
  cursor.setTexture(AssetManager::cursor);
  
  sf::FloatRect textBounds = killCounter.getLocalBounds();
  killCounter.setOrigin(textBounds.width/2.f, textBounds.height/2.f);
  killCounter.setPosition(sf::Vector2f(WINDOW_WIDTH - UI_LEFT_MARGIN, 20 + UI_TOP_MARGIN));
  killCounter.setFillColor(sf::Color::White);
}

void UserInterfaceManager::update(int playerHealth, int playerAmmo, int baseHealth, int baseShield, int killCount)
{
  playerHealthBar.setValue(playerHealth);
  playerAmmoBar.setValue(playerAmmo);
  baseHealthBar.setValue(baseHealth);
  baseShieldBar.setValue(baseShield);

  killCounter.setString(std::to_string(killCount));
}

void UserInterfaceManager::renderBehind(sf::RenderWindow& window)
{
  window.draw(background);
}

void UserInterfaceManager::renderFront(sf::RenderWindow& window)
{
  playerHealthBar.render(window);
  playerAmmoBar.render(window);
  baseHealthBar.render(window);
  baseShieldBar.render(window);

  sf::FloatRect textBounds = killCounter.getLocalBounds();
  killCounter.setOrigin(textBounds.width/2.f, textBounds.height/2.f);
  killCounter.setPosition(sf::Vector2f(WINDOW_WIDTH - UI_LEFT_MARGIN, 20 + UI_TOP_MARGIN));
  window.draw(killCounter);

  sf::Vector2i mousePos = sf::Mouse::getPosition(window);
  float mouse_x = mousePos.x - 16;
  float mouse_y = mousePos.y - 16;
  cursor.setPosition(mouse_x, mouse_y);

  window.draw(cursor);
}
