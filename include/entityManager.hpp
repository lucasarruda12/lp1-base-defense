#ifndef INCLUDE_ENTITYMANAGER_HPP_
#define INCLUDE_ENTITYMANAGER_HPP_

#include <SFML/Graphics.hpp>
#include <bullet.hpp>
#include <player.hpp>
#include <enemy.hpp>
#include <list>
using std::list;

class EntityManager{
  private:
    Player player;
    list<Bullet*> bullets;
    list<Enemy*> enemies;
    int enemySpawnTimer;
    sf::Vector2f generateRandomEnemySpawn();

  public:
    EntityManager();
    void add(Enemy* enemy);
    void add(Bullet* bullet);

    void updateAll();
    void renderAll(sf::RenderWindow& window);
    void processPlayerEvents(sf::Event& event);
    void spawnNewEnemies();
    void checkEnemyBulletCollision();
    void checkBulletLifetime();
    void makeEnemiesShoot();
    void checkPlayerBulletCollision();

};

#endif // INCLUDE_ENTITYMANAGER_HPP
