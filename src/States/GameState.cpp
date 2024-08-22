#include <Constants.hpp>

#include <States/GameState.hpp>
#include <Entities/Bullet.hpp>
#include <Entities/Enemy.hpp>
#include <AssetManager.hpp>

GameState::GameState()
: entities()
, ui()
, gameTimer(120*60)
{}

void GameState::processEvent(const sf::Event& event){
  if(event.type == sf::Event::KeyPressed)
  {
    if(event.key.code == sf::Keyboard::Space)
    {
      stateChanger(State::States::Paused);
      return;
    }
  }

  entities.processPlayerEvents(event);
}

void GameState::update() {
  gameTimer--;

  // O aumento da dificuldade do jogo com o tempo é feito
  // de acordo com o número de ticks que se passaram desde o início.

  if (gameTimer == 90*60) {
    entities.setEnemySpawnTimer(ENEMY_SPAWN_TIMER - 15);
    entities.setMaxEnemyCount(MAX_ENEMY_COUNT +1);
  }

  if (gameTimer == 60*60) {
    entities.setEnemySpawnTimer(ENEMY_SPAWN_TIMER - 30);
    entities.setMaxEnemyCount(MAX_ENEMY_COUNT +2);
  }

  if (gameTimer == 30*60) {
    entities.setEnemySpawnTimer(ENEMY_SPAWN_TIMER - 60);
    entities.setMaxEnemyCount(MAX_ENEMY_COUNT +3);
  }

  if(entities.checkGameOver())
  {
    stateChanger(State::States::GameOver);
    return;
  }

  if(gameTimer == 0)
  {
    stateChanger(State::States::GameOver);
    return;
  }

  entities.updateAll();

  entities.spawnNewEnemies();
  entities.checkEnemyBulletCollision();
  entities.checkPlayerBulletCollision();
  entities.checkBaseBulletCollision();
  entities.checkPlayerEnemyDropCollision();
  entities.checkEnemyBaseCollision();
  entities.checkBulletLifetime();
  entities.checkEnemyDropLifetime();
  entities.makeEnemiesShoot();

  int playerHealth = entities.getPlayerHealth();
  int playerAmmo = entities.getPlayerAmmo();
  int baseHealth = entities.getBaseHealth();
  int baseShield = entities.getBaseShield();

  ui.update(playerHealth, playerAmmo, baseHealth, baseShield);
}

void GameState::render(sf::RenderWindow& window) {
  window.clear();

  ui.renderBehind(window);
  entities.renderAll(window);
  ui.renderFront(window);

  window.display();
}
