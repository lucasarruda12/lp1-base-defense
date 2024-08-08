#include <constants.hpp>
#include <game.hpp>
#include <GameState.hpp>

#include <iostream>

using namespace std;

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Application", sf::Style::Close)
,currentState(new GameState())
,previousState(nullptr)
{}


void Game::run(){
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  while(window.isOpen()){
    sf::Time elapsedTime = clock.restart();
    timeSinceLastUpdate += elapsedTime;

    while(timeSinceLastUpdate > TimePerFrame){
      timeSinceLastUpdate -= TimePerFrame;
      sf::Event event;
      
      while(window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
            window.close();
        }
        currentState->processEvent(event);
      }

      currentState->update();
      currentState->render(window);
    }
  }
}