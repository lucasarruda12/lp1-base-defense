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
  WINDOW_HEIGHT/2 + BASE_RADIUS + UI_BASE_HEALTH_VERTICAL_OFFSET,
  WINDOW_WIDTH/2 - UI_WIDTH/4
)
,background()
,cursor()
{
  background.setTexture(AssetManager::background);
  cursor.setTexture(AssetManager::cursor);
}

void UserInterfaceManager::update(int playerHealth, int playerAmmo, int baseHealth)
{
  playerHealthBar.setValue(playerHealth);
  playerAmmoBar.setValue(playerAmmo);
  baseHealthBar.setValue(baseHealth);
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
  
  sf::Vector2i mousePos = sf::Mouse::getPosition(window);
  float mouse_x = mousePos.x - 16;
  float mouse_y = mousePos.y - 16;
  cursor.setPosition(mouse_x, mouse_y);

  window.draw(cursor);
}
