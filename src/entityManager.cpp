#include <constants.hpp>
#include <entityManager.hpp>
#include <random>

EntityManager::EntityManager()
: player()
, base()
, enemies()
, bullets()
, enemySpawnTimer(ENEMY_SPAWN_TIMER)
, maxEnemyCount(MAX_ENEMY_COUNT)
{}

EntityManager::~EntityManager(){
  for (const auto& b : bullets) { delete b; }
  for (const auto& e : enemies) {delete e; }
  for (const auto& a : ammoBoxes) { delete a; }
}

void EntityManager::add(Enemy* enemy)
{
  enemies.push_back(enemy);
}

void EntityManager::add(Bullet* bullet)
{
  bullets.push_back(bullet);
}

void EntityManager::renderAll(sf::RenderWindow& window)
{
  base.render(window);
  player.render(window);
  for (const auto& b : bullets) { b->render(window); }
  for (const auto& e : enemies) { e->render(window); }
  for (const auto& a : ammoBoxes) { a->render(window); }
}

bool EntityManager::checkGameOver()
{
  return (player.getHealth() <= 0) | (base.getHealth() <= 0);
}

void EntityManager::processPlayerEvents(const sf::Event& event)
{
  if (event.type == sf::Event::MouseButtonPressed)
  {
    sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

    // Botão direito manda o jogador andar até aquela posição
    if (event.mouseButton.button == sf::Mouse::Right)
    {
      player.setTarget(mousePos);
    }

    // Botão esquerdo cria uma bala que sai do player naquela direção
    if (event.mouseButton.button == sf::Mouse::Left && player.getAmmo() > 0)
    {
      bool isPlayerBullet = true;
      Bullet* b = new Bullet(player.getPosition(), mousePos, isPlayerBullet);
      bullets.push_back(b);

      player.decreaseAmmo(1);
    }
  }
}

void EntityManager::spawnNewEnemies()
{
  if (enemySpawnTimer >= 0) {
    enemySpawnTimer -= 1;
    return;
  }

  if (enemies.size() >= maxEnemyCount) { return; }  

  sf::Vector2f spawnLocation = generateRandomEnemySpawn();

  Enemy* newEnemy = new Enemy(spawnLocation);
  EntityManager::add(newEnemy);

  int randInt = generateRandomInt(-30, 30);

  enemySpawnTimer = ENEMY_SPAWN_TIMER + randInt;
}

void EntityManager::updateAll(){
  player.update();
  base.update();
  for (const auto& b : bullets) {b->update(); }
  for (const auto& e : enemies) { e->update(); }
  for (const auto& box : ammoBoxes) { box->update(); }
}

void EntityManager::checkBulletLifetime()
{
  for (auto it = bullets.begin(); it != bullets.end();)
  {
    Bullet* bullet = *it;

    if (bullet->isExpired())
    {
       delete bullet;
       it = bullets.erase(it);
     }
     else { it++; }
  }
}

void EntityManager::checkAmmoBoxLifetime()
{
  for (auto it = ammoBoxes.begin(); it != ammoBoxes.end();)
  {
    AmmoBox* box = *it;

    if (box->isExpired())
    {
       delete box;
       it = ammoBoxes.erase(it);
    }
    else { it++; }
  }
}

void EntityManager::checkPlayerBulletCollision()
{
  for (auto it = bullets.begin(); it != bullets.end();)
  {
    Bullet* bullet = *it;

    if (!bullet->isPlayerBullet() && player.checkCollision(*bullet))
    {
      player.takeDamage(); 
      delete bullet;
      it = bullets.erase(it);
    }
    else{ it++; }
  }
}

void EntityManager::checkBaseBulletCollision()
{
  for (auto it = bullets.begin(); it != bullets.end();)
  {
    Bullet* bullet = *it;

    if (!bullet->isPlayerBullet() && base.checkCollision(*bullet))
    {
      base.takeDamage(1);

      delete bullet;
      it = bullets.erase(it);
    }
    else { it++; }
  }
}

void EntityManager::checkPlayerAmmoBoxCollision()
{
  for (auto it = ammoBoxes.begin(); it != ammoBoxes.end();)
  {
    bool hit = false;
    AmmoBox* ammoBox = *it;

    if (player.checkCollision(*ammoBox))
    {
      player.reload(AMMOBOX_RELOAD_AMMOUNT);
      delete ammoBox;
      it = ammoBoxes.erase(it);
    }
    else { it++; }
  }
}

void EntityManager::checkEnemyBulletCollision()
{
  for (auto eit = enemies.begin(); eit != enemies.end();)
  {
    Enemy* enemy = *eit;
    bool hit = false;

    // Checa colisão com alguma bala e deleta a bala em si
    for (auto bit = bullets.begin(); bit != bullets.end();)
    {
      Bullet* bullet = *bit;

      if (bullet->isPlayerBullet() && enemy->checkCollision(*bullet))
      {
        hit = true;

        delete bullet;
        bit = bullets.erase(bit);
      }
      else { bit++; }
    }

    if (hit)
    {
      // Cria uma caixinha de munição onde o inimigo morreu
      AmmoBox* newAmmoBox = new AmmoBox(enemy->getPosition());
      ammoBoxes.push_back(newAmmoBox);

      // E deleta o inimigo
      delete enemy;
      eit = enemies.erase(eit);
    }
    else { eit++; }
  }
}

void EntityManager::checkEnemyBaseCollision()
{
  for (auto it = enemies.begin(); it != enemies.end();)
  {
    Enemy* enemy = *it;

    if (enemy->checkCollision(base))
    {
      base.takeDamage(10);

      delete enemy;
      it = enemies.erase(it);
    }
    else { it++; }
  }
}

void EntityManager::makeEnemiesShoot()
{
  for (auto it = enemies.begin(); it != enemies.end();)
  {
    Enemy* enemy = *it;
    if (enemy->isAbleToShoot())
    {
      enemy->resetShootTimer();

      bool isPlayerBullet = false;
      Bullet* b = new Bullet(enemy->getPosition(), player.getPosition(), isPlayerBullet);
      bullets.push_back(b);
    }

    it++;
  }
}

int EntityManager::getPlayerHealth(){ return player.getHealth(); }

int EntityManager::getPlayerAmmo(){ return player.getAmmo(); }

int EntityManager::getBaseHealth(){ return base.getHealth(); }

int EntityManager::generateRandomInt(int from, int to)
{
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_real_distribution<double> dist(from, to);

  return dist(mt);
}

sf::Vector2f EntityManager::generateRandomEnemySpawn()
{
  int randInt = generateRandomInt(0, WINDOW_HEIGHT*2 + WINDOW_WIDTH*2);
  sf::Vector2f spawnLocation(0.f,0.f);

  if (randInt <= WINDOW_HEIGHT)
  {
    spawnLocation.y = randInt;
    return spawnLocation;
  } 
  else
  {
    spawnLocation.y = WINDOW_HEIGHT;
    randInt -= WINDOW_HEIGHT;
  }

  if (randInt <= WINDOW_WIDTH)
  {
    spawnLocation.x = randInt;
    return spawnLocation;
  }
  else
  {
    spawnLocation.x = WINDOW_WIDTH;
    randInt -= WINDOW_WIDTH;
  }

  if
  (randInt <= WINDOW_HEIGHT){
    spawnLocation.y -= randInt;
    return spawnLocation;
  }
  else
  {
    spawnLocation.y = 0;
    randInt -= WINDOW_HEIGHT;
  }

  if (randInt <= WINDOW_WIDTH)
  {
    spawnLocation.x -= randInt;
    return spawnLocation;
  }

  return spawnLocation;
}