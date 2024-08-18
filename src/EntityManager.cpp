#include <Constants.hpp>
#include <EntityManager.hpp>
#include <random>

EntityManager::EntityManager()
: player()
, base()
, enemies()
, bullets()
, enemySpawnTimer(ENEMY_SPAWN_TIMER)
, maxEnemyCount(MAX_ENEMY_COUNT)
, enemiesKilled(0)
{}

EntityManager::~EntityManager(){
  for (const auto& b : bullets) { delete b; }
  for (const auto& e : enemies) {delete e; }
  for (const auto& a : EnemyDrops) { delete a; }
}

void EntityManager::add(Enemy* enemy)
{
  enemies.push_back(enemy);
}

void EntityManager::add(Bullet* bullet)
{
  bullets.push_back(bullet);
}

void EntityManager::add(EnemyDrop* enemyDrop){
  EnemyDrops.push_back(enemyDrop);
}

void EntityManager::renderAll(sf::RenderWindow& window)
{
  base.render(window);
  player.render(window);
  for (const auto& b : bullets) { b->render(window); }
  for (const auto& e : enemies) { e->render(window); }
  for (const auto& a : EnemyDrops) { a->render(window); }
}

bool EntityManager::checkGameOver()
{
  return (player.getHealth() <= 0) || (base.getHealth() <= 0);
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
      Bullet* b = player.shoot(mousePos);
      bullets.push_back(b);
    }
  }
}

void EntityManager::updateAll(){
  player.update();
  base.update();
  for (const auto& b : bullets) {b->update(); }
  for (const auto& e : enemies) { e->update(); }
  for (const auto& box : EnemyDrops) { box->update(); }
}

void EntityManager::spawnNewEnemies()
{
  if (enemySpawnTimer >= 0) {
    enemySpawnTimer--;
    return;
  }

  // Existe um limite de inimigos na tela
  if (enemies.size() >= maxEnemyCount) { return; }

  // Decidimos a localização de spawn do inimigo
  // gerando um ponto aleatório no perímetro do retângulo
  // que forma a janela
  sf::Vector2f spawnLocation = generateRandomEnemySpawn();

  Enemy* newEnemy = new Enemy(spawnLocation);
  EntityManager::add(newEnemy);

  // Optamos por adicionar aleatoriedade ao tempo de 
  // spawn dos inimigos
  int randInt = generateRandomInt(-30, 30);
  enemySpawnTimer = ENEMY_SPAWN_TIMER + randInt;
}

// Checa cada bala, uma por uma, pra ver se ela já
// passou do tempo de vida.
// Se passou, deleta.
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

// Mesma coisa pras caixinhas de munição
void EntityManager::checkEnemyDropLifetime()
{
  for (auto it = EnemyDrops.begin(); it != EnemyDrops.end();)
  {
    EnemyDrop* box = *it;

    if (box->isExpired())
    {
       delete box;
       it = EnemyDrops.erase(it);
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
      // O player toma sempre 1 de dano
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
      // A base toma dano variado
      base.takeDamage(1);
      delete bullet;
      it = bullets.erase(it);
    }
    else { it++; }
  }
}

void EntityManager::checkPlayerEnemyDropCollision()
{
  for (auto it = EnemyDrops.begin(); it != EnemyDrops.end();)
  {
    EnemyDrop* enemyDrop = *it;

    if (player.checkCollision(*enemyDrop))
    {
      if (enemyDrop->getType() == EnemyDrop::Type::AmmoBox)
      {
        player.reload(AMMOBOX_RELOAD_AMMOUNT);
      }

      if (enemyDrop->getType() == EnemyDrop::Type::HealthPack)
      {
        player.heal(HEALTHPACK_HEAL_AMMOUNT);
      }

      delete enemyDrop;
      it = EnemyDrops.erase(it);
    }
    else { it++; }
  }
}

void EntityManager::checkEnemyBulletCollision()
{
  for (auto eit = enemies.begin(); eit != enemies.end();)
  {
    Enemy* enemy = *eit;
    // Guardo o hit numa variável separada para deletar o inimigo depois.
    // Como forma de evitar o cenário em que duas balas chegam no inimigo
    // no mesmo update e só uma é deletada.
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
      // aumenta o contador de inimigos mortos
      enemiesKilled++;

      // Cria uma caixinha de munição alguns pixels separado
      // de onde o inimigo morreu
      sf::Vector2f spawnPosition = generateOffsetPosition(enemy->getPosition(),-5,5);
      EnemyDrop* newEnemyDrop = new EnemyDrop(spawnPosition, EnemyDrop::Type::AmmoBox);
      EnemyDrops.push_back(newEnemyDrop);

      // Tem uma chance de 1 em 5 de criar um healthPack
      int randInt = generateRandomInt(1, 5);
      if (randInt == 2) 
      {
        // Gera uma nova posição um pouquinho fora de centro
        spawnPosition = generateOffsetPosition(enemy->getPosition(), -5, 5);
        EnemyDrop* newEnemyDrop = new EnemyDrop(enemy->getPosition(), EnemyDrop::Type::HealthPack);
        EnemyDrops.push_back(newEnemyDrop);
      }

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
      // A base toma dano variado
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
      Bullet* b = enemy->shoot(player.getPosition());
      bullets.push_back(b);
    }

    it++;
  }
}

int EntityManager::generateRandomInt(int from, int to)
{
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_real_distribution<double> dist(from, to);

  return dist(mt);
}

sf::Vector2f EntityManager::generateOffsetPosition(
  sf::Vector2f initial_position,
  int min_offset,
  int max_offset
)
{
  int offset_y = generateRandomInt(min_offset, max_offset);
  int offset_x = generateRandomInt(min_offset, max_offset);

  sf::Vector2f new_position;
  new_position.x = initial_position.x + offset_x;
  new_position.y = initial_position.y + offset_y;

  return new_position;
}

// A ideia é gerar um inteiro aleatório entre 0 e o perímetro da
// janela, e ir subtraindo o valor de cada "aresta" até saber
// em qual ele parou. Sabendo em qual ele parou,
// é só pegar o que sobrou dessas subtrações e usar como posição
// dentro daquela aresta.
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
