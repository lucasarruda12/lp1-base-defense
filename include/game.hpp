#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <player.hpp>
#include <enemy.hpp>
#include <bullet.hpp>
#include <list>
using std::list;

class Game {
  public:
    Game();
    void run();
    void processEvents();
    void render();
    void update();

  private:
    static const sf::Time TimePerFrame;
    sf::RenderWindow window;
    
    Player player;
    list<Bullet*> bullets;
    list<Enemy*> enemies;
};

#endif
