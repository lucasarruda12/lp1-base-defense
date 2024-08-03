#include <entityManager.hpp>
#include <random>

EntityManager::EntityManager()
: player()
, enemies()
, bullets()
, enemySpawnTimer(0)
{}

void EntityManager::add(Enemy* enemy){
  enemies.push_back(enemy);
}

void EntityManager::add(Bullet* bullet){
  bullets.push_back(bullet);
}

void EntityManager::renderAll(sf::RenderWindow& window){
  player.render(window);

  for (const auto& b : bullets) {
    b->render(window);
  }

  for (const auto& e : enemies) {
    e->render(window);
  }
}

void EntityManager::processPlayerEvents(sf::Event& event){
  if (event.type == sf::Event::MouseButtonPressed){
    sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

    // Botão direito manda o jogador andar até aquela posição
    if (event.mouseButton.button == sf::Mouse::Right){
      player.setTarget(mousePos);
    }

    // Botão esquerdo cria uma bala que sai do player naquela direção
    if (event.mouseButton.button == sf::Mouse::Left && player.getAmmo() > 0){
      Bullet* b = new Bullet(player.getPosition(), mousePos);
      bullets.push_back(b);

      player.decreaseAmmo(1);
    }
  }
}

void EntityManager::spawnNewEnemies(){
  if (enemySpawnTimer <= 120) {
    enemySpawnTimer += 1;
    return;
  }
  
  sf::Vector2f spawnLocation = generateRandomEnemySpawn();

  Enemy* newEnemy = new Enemy(spawnLocation);
  EntityManager::add(newEnemy);

  enemySpawnTimer = 0;
}

sf::Vector2f EntityManager::generateRandomEnemySpawn(){
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_real_distribution<double> dist(0, 2239);

  int randInt = dist(mt);
  sf::Vector2f spawnLocation(0.f,0.f);

  if (randInt <= 480){
    spawnLocation.y = randInt;
    return spawnLocation;
  } else {
    spawnLocation.y = 480;
    randInt -= 480;
  }

  if (randInt <= 640){
    spawnLocation.x = randInt;
    return spawnLocation;
  } else {
    spawnLocation.x = 640;
    randInt -= 640;
  }

  if (randInt <= 480){
    spawnLocation.y -= randInt;
    return spawnLocation;
  } else {
    spawnLocation.y = 0;
    randInt -= 480;
  }

  if (randInt <= 640){
    spawnLocation.x -= randInt;
    return spawnLocation;
  }

  return spawnLocation;
}

void EntityManager::updateAll(){
  player.update();

  // Dar update em todas as balas
  for(auto it = bullets.begin(); it != bullets.end();){
    Bullet* bullet = *it;
    bullet->update();

   if (bullet->isExpired()){
      delete bullet;
      it = bullets.erase(it);
    } else {
      it++;
    }
  }

  // Dar update em todos os inimigos
  for(auto it = enemies.begin(); it != enemies.end();){
    Enemy* enemy = *it;
    enemy->update();

    it++;
  }

  // Checar colisão entre inimigos e balas
  for (auto eit = enemies.begin(); eit != enemies.end();) {
    Enemy* enemy = *eit;
    bool hit = false;

    // Checa colisão com alguma bala e deleta a bala em si
    for (auto bit = bullets.begin(); bit != bullets.end();){
      Bullet* bullet = *bit;

      if (enemy->checkCollision(*bullet)){
        hit = true;

        delete bullet;
        bit = bullets.erase(bit);
      } else {
        bit++;
      }
    }

    // Deleta o inimigo
    if (hit){
      delete enemy;
      eit = enemies.erase(eit);
    } else {
      eit++;
    }
  }
}
