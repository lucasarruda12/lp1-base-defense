#pragma once

#include <SFML/Graphics.hpp>
#include <UIElements/StatusBar.hpp>

class UserInterfaceManager
{
  private:
    StatusBar playerHealthBar;
    StatusBar playerAmmoBar;
    StatusBar baseHealthBar;

  public:
    UserInterfaceManager();
    void update(int playerHealth, int playerAmmo, int baseHealth);
    void render(sf::RenderWindow& window);
};
