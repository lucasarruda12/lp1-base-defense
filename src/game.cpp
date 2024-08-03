#include <game.hpp>
#include <bullet.hpp>
#include <HealthBar.hpp>
#include <enemy.hpp>

#include <iostream>

using namespace std;

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: window(sf::VideoMode(640, 480), "SFML Application", sf::Style::Close)
, entities()
{}


void Game::run(){
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  while(window.isOpen()){
    sf::Time elapsedTime = clock.restart();
    timeSinceLastUpdate += elapsedTime;

    // Dar update no estado do jogo só a cada 1/60 segundos
    while(timeSinceLastUpdate > TimePerFrame){
      timeSinceLastUpdate -= TimePerFrame;
      processEvents();
      update();
    }

    // Renderizar o tempo todo
    render();
  }
}

void Game::processEvents(){
   sf::Event event;
   while(window.pollEvent(event)){
     if (event.type == sf::Event::Closed){
       window.close();
     }

    entities.processPlayerEvents(event);
   }
}

void Game::update() {
  entities.updateAll();
  entities.spawnNewEnemies();
  entities.checkEnemyBulletCollision();
  entities.checkBulletLifetime();
  entities.makeEnemiesShoot();
}

void Game::render() {
  window.clear();

  entities.renderAll(window);

  window.display();
}

