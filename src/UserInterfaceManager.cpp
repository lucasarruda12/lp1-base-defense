#include <UserInterfaceManager.hpp>

UserInterfaceManager::UserInterfaceManager()
: playerHealthBar(
  PLAYER_MAX_HEALTH,
  sf::Color::Red,
  sf::Color::White,
  UI_WIDTH,
  UI_HEIGHT,
  UI_TOP_MARGIN,
  UI_LEFT_MARGIN
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
  UI_WIDTH/2,
  UI_HEIGHT/4,
  WINDOW_HEIGHT/2 + BASE_RADIUS + UI_BASE_HEALTH_VERTICAL_OFFSET,
  WINDOW_WIDTH/2 - UI_WIDTH/4
)
{}

void UserInterfaceManager::update(int playerHealth, int playerAmmo, int baseHealth)
{
  playerHealthBar.setValue(playerHealth);
  playerAmmoBar.setValue(playerAmmo);
  baseHealthBar.setValue(baseHealth);
}

void UserInterfaceManager::render(sf::RenderWindow& window)
{
  playerHealthBar.render(window);
  playerAmmoBar.render(window);
  baseHealthBar.render(window);
}