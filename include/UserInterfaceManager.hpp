#pragma once

#include <SFML/Graphics.hpp>
#include <UIElements/StatusBar.hpp>

class UserInterfaceManager
{
  private:
    StatusBar playerHealthBar;
    StatusBar playerAmmoBar;
    StatusBar baseHealthBar;
    StatusBar baseShieldBar;
    sf::Text killCounter;
    sf::Sprite background;
    sf::Sprite cursor;

  public:
    UserInterfaceManager();
    void update(int playerHealth, int playerAmmo, int baseHealth, int baseShield, int killCount);
    void renderBehind(sf::RenderWindow& window);
    void renderFront(sf::RenderWindow& window);
};
