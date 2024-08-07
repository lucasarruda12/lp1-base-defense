#include <constants.hpp>

#include <game.hpp>
#include <bullet.hpp>
#include <enemy.hpp>

#include <iostream>

using namespace std;

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Application", sf::Style::Close)
, entities()
, ui()
, gameTimer(120*60)
{}


void Game::run(){
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  while(window.isOpen()){
    sf::Time elapsedTime = clock.restart();
    timeSinceLastUpdate += elapsedTime;
    
    // updates no estado do jogo e renderização acontecem a cada 1/60 segundos
    while(timeSinceLastUpdate > TimePerFrame){
      timeSinceLastUpdate -= TimePerFrame;
      processEvents();
      update();
      render();

      // Fecha a janela se o jogo acabou
      if (entities.checkGameOver()){
        window.close();
      }

      if (gameTimer == 0){
        window.close();
      }
    }
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
  gameTimer--;

  entities.updateAll();

  entities.spawnNewEnemies();
  entities.checkEnemyBulletCollision();
  entities.checkPlayerBulletCollision();
  entities.checkBaseBulletCollision();
  entities.checkPlayerAmmoBoxCollision();
  entities.checkEnemyBaseCollision();
  entities.checkBulletLifetime();
  entities.checkAmmoBoxLifetime();
  entities.makeEnemiesShoot();

  int playerHealth = entities.getPlayerHealth();
  int playerAmmo = entities.getPlayerAmmo();
  int baseHealth = entities.getBaseHealth();

  ui.update(playerHealth, playerAmmo, baseHealth);
}

void Game::render() {
  window.clear();

  entities.renderAll(window);
  ui.render(window);

  window.display();
}