#include <constants.hpp>
#include <game.hpp>
#include <GameState.hpp>
#include <PausedState.hpp>

#include <iostream>

using namespace std;

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Application", sf::Style::Close)
,currentState(new PausedState())
,previousState(nullptr)
{
  changeState(State::States::GameState);
}

Game::~Game()
{
  delete currentState;
  delete previousState;
}

void Game::run()
{
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  while(window.isOpen())
  {
    sf::Time elapsedTime = clock.restart();
    timeSinceLastUpdate += elapsedTime;

    while(timeSinceLastUpdate > TimePerFrame)
    {
      timeSinceLastUpdate -= TimePerFrame;

      sf::Event event;
      
      while(window.pollEvent(event))
      {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        currentState->processEvent(event);
      }

      currentState->update();
      currentState->render(window);
    }
  }
}

void Game::changeState(State::States newState)
{
  if (newState == State::States::Previous)
  {
    State* buffer = currentState;
    currentState = previousState;
    previousState = buffer;
    return;
  }

  switch (newState)
  {
  case State::States::Paused:
    delete previousState;
    previousState = currentState;

    currentState = new PausedState();
    break;
  
  case State::States::GameState:
    currentState = new GameState();
    break;
  }

  currentState->setStageChanger(
    [this](State::States newState){changeState(newState);}
  );
}