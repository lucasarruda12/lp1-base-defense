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
    void processEvents();
    void render();
    void update();

  private:
    static const sf::Time TimePerFrame;
    sf::RenderWindow window;
    UserInterfaceManager ui;
    EntityManager entities;
};

#endif
