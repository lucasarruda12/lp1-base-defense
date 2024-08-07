#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <entityManager.hpp>
#include <UserInterfaceManager.hpp>

#include <list>
using std::list;

class Game {
  public:
    Game();
    void run();

  private:
    static const sf::Time TimePerFrame;
    sf::RenderWindow window;
    UserInterfaceManager ui;
    EntityManager entities;
    int gameTimer;

    void processEvents();
    void render();
    void update();
    void handleGameOver();
};

#endif
