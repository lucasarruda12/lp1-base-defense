#include <game.hpp>

using namespace std;

void Game::run(){
  sf::RenderWindow window(sf::VideoMode(640, 480), "TESTE");
  Player p;

  while(window.isOpen()){
    sf::Event event;

    while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed)
        window.close();

      p.handleEvent(event);
    }

    window.clear();

    p.render(window);

    window.display();
  }
}
