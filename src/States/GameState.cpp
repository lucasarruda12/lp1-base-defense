#include <Constants.hpp>

#include <States/GameState.hpp>
#include <Entities/Bullet.hpp>
#include <Entities/Enemy.hpp>

GameState::GameState()
: entities()
, ui()
, gameTimer(120*60)
{}

void GameState::processEvent(const sf::Event& event){
  if(event.type == sf::Event::KeyPressed)
  {
    if(event.key.code == sf::Keyboard::Escape)
    {
      stateChanger(State::States::Paused);
      return;
    }
  }

  entities.processPlayerEvents(event);
}

void GameState::update() {
  gameTimer--;

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
