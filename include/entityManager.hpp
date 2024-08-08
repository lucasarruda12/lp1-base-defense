#pragma once

#include <SFML/Graphics.hpp>
#include <bullet.hpp>
#include <player.hpp>
#include <enemy.hpp>
#include <AmmoBox.hpp>
#include <base.hpp>

#include <list>
using std::list;

class EntityManager
{
  private:
    Player player;
    Base base;
    list<Bullet*> bullets;
    list<Enemy*> enemies;
    list<AmmoBox*> ammoBoxes;
    int enemySpawnTimer;
    int maxEnemyCount;
    sf::Vector2f generateRandomEnemySpawn();

  public:
    EntityManager();
    ~EntityManager();
    void add(Enemy* enemy);
    void add(Bullet* bullet);

    void updateAll();
    void renderAll(sf::RenderWindow& window);
    void processPlayerEvents(const sf::Event& event);
    void spawnNewEnemies();
    void checkEnemyBulletCollision();
    void checkBulletLifetime();
    void checkAmmoBoxLifetime();
    void makeEnemiesShoot();
    void checkPlayerBulletCollision();
    void checkPlayerAmmoBoxCollision();
    void checkEnemyBaseCollision();
    void checkBaseBulletCollision();
    
    bool checkGameOver();

    int getPlayerHealth();
    int getPlayerAmmo();
    int getBaseHealth();

    int generateRandomInt(int from, int to);
};
