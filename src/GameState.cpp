#include <constants.hpp>

#include <GameState.hpp>
#include <bullet.hpp>
#include <enemy.hpp>

#include <iostream>

using namespace std;

GameState::GameState()
: entities()
, ui()
, gameTimer(120*60)
{}

void GameState::processEvent(const sf::Event& event){
  entities.processPlayerEvents(event);
}

void GameState::update() {
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

void GameState::render(sf::RenderWindow& window) {
  window.clear();

  entities.renderAll(window);
  ui.render(window);

  window.display();
}