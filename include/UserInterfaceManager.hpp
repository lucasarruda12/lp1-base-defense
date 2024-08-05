#ifndef INCLUDE_USER_INTERFACE_MANAGER_HPP
#define INCLUDE_USER_INTERFACE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <StatusBar.hpp>

class UserInterfaceManager {
  private:
    StatusBar playerHealthBar;
    StatusBar playerAmmoBar;
    StatusBar baseHealthBar;

  public:
    UserInterfaceManager();
    void update(int playerHealth, int playerAmmo, int baseHealth);
    void render(sf::RenderWindow& window);
};

#endif