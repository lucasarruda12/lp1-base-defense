#include <game.hpp>
#include <bullet.hpp>

using namespace std;

void Game::run(){
  sf::RenderWindow window(sf::VideoMode(640, 480), "TESTE");
  Player p;
  Bullet b(0.f, 0.f, 640.f, 480.f);

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
