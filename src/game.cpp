#include <RenderGroup.hpp>
#include <game.hpp>
#include <bullet.hpp>

#include <iostream>

using namespace std;

void Game::run(){
  sf::RenderWindow window(sf::VideoMode(640, 480), "TESTE");
  Player p;
  Bullet a(640.f, 480.f, 0.f, 0.f);
  Bullet b(0.f, 0.f, 640.f, 480.f);
  RenderGroup::Bullets.push_back(&b);
  RenderGroup::Bullets.push_back(&a);

  while(window.isOpen()){
    sf::Event event;

    while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed)
        window.close();

      p.handleEvent(event);
    }

    window.clear();

    p.render(window);

    for (auto const& c : RenderGroup::Bullets) {
      c->render(window);
    }

    window.display();
  }
}
