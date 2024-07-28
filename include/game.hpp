#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <player.hpp>

class Game {
  public:
    Game();
    void run();
    void processEvents();
    void render();
    void update();

  private:
    static const sf::Time TimePerFrame;
    Player player;
    sf::RenderWindow window;
};

#endif
