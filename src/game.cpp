#include <game.hpp>
#include <bullet.hpp>
#include <HealthBar.hpp>

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

    player.handleEvent(event);
  }
}

void Game::update() {
  player.update();
  Bullet::updateAll();
}

void Game::render() {
  window.clear();
  player.render(window);

  HealthBar::render(window);
  Bullet::renderAll(window);

  window.display();
}

