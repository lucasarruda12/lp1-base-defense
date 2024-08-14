#pragma once

#include <SFML/Graphics.hpp>
#include <Entities/Bullet.hpp>
#include <Entities/Player.hpp>
#include <Entities/Enemy.hpp>
#include <Entities/EnemyDrop.hpp>
#include <Entities/Base.hpp>

#include <list>
using std::list;

class EntityManager
{
  private:
    Player player;
    Base base;
    list<Bullet*> bullets;
    list<Enemy*> enemies;
    list<EnemyDrop*> EnemyDrops;

    int enemySpawnTimer;
    int maxEnemyCount;

    sf::Vector2f generateRandomEnemySpawn();
    int generateRandomInt(int from, int to);

  public:
    EntityManager();
    ~EntityManager();

    void add(Enemy* enemy);
    void add(Bullet* bullet);
    void add(EnemyDrop* EnemyDrop);

    void updateAll();
    void renderAll(sf::RenderWindow& window);
    void processPlayerEvents(const sf::Event& event);
    void spawnNewEnemies();
    void makeEnemiesShoot();

    void checkEnemyBulletCollision();
    void checkBulletLifetime();
    void checkEnemyDropLifetime();
    void checkPlayerBulletCollision();
    void checkPlayerEnemyDropCollision();
    void checkEnemyBaseCollision();
    void checkBaseBulletCollision();
    bool checkGameOver();

    int getPlayerHealth() { return player.getHealth(); }
    int getPlayerAmmo() { return player.getAmmo(); }
    int getBaseHealth() { return base.getHealth(); }
};
