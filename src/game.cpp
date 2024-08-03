#include <game.hpp>
#include <bullet.hpp>
#include <HealthBar.hpp>
#include <enemy.hpp>

#include <iostream>

using namespace std;

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
    :window(sf::VideoMode(640, 480), "SFML Application", sf::Style::Close)
    , player(){}


void Game::run(){
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  HealthBar::setHealth(10);
  Enemy* n = new Enemy(sf::Vector2f(10,100), sf::Vector2f(640/2, 480/2));
  enemies.push_back(n);

  while(window.isOpen()){
    sf::Time elapsedTime = clock.restart();
    timeSinceLastUpdate += elapsedTime;

    // Dar update no estado do jogo só a cada 1/60 segundos
    while(timeSinceLastUpdate > TimePerFrame){
      timeSinceLastUpdate -= TimePerFrame;
      processEvents();
      update();
    }

    // Renderizar o tempo todo
    render();
  }
}

void Game::processEvents(){
  sf::Event event;
  while(window.pollEvent(event)){
    if (event.type == sf::Event::Closed){
      window.close();
    }

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
}

void Game::update() {
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

void Game::render() {
  window.clear();

  player.render(window);
  HealthBar::render(window);
  for (const auto& b : bullets) {
    b->render(window);
  }
  for (const auto& e : enemies) {
    e->render(window);
  }

  window.display();
}

