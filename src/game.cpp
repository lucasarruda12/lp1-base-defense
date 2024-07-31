#include <game.hpp>
#include <bullet.hpp>
#include <HealthBar.hpp>
// #include <enemy.hpp>

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
  // Enemy* n = new Enemy(sf::Vector2f(10,100));

  while(window.isOpen()){
    sf::Time elapsedTime = clock.restart();
    timeSinceLastUpdate += elapsedTime;

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

      if (event.mouseButton.button == sf::Mouse::Right){
        player.setTarget(mousePos);
      }

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

  auto it = bullets.begin();

  while(it != bullets.end()){
    Bullet* bullet = *it;
    bullet->update();

    if (bullet->getLifetime() <= 0){
      it = bullets.erase(it);
    } else {
      it++;
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

  // Enemy::renderAll(window);

  window.display();
}

