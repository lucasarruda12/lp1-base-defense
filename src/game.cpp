#include "game.hpp"

const float Game::PlayerSpeed = 300.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: mWindow(sf::VideoMode(640, 480), "SFML Application", sf::Style::Close)
, mIsMovingUp(false)
, mIsMovingDown(false)
, mIsMovingRight(false)
, mIsMovingLeft(false)
, mPlayer(){
  mPlayer.setRadius(40.f);
  mPlayer.setPosition(100.f, 100.f);
  mPlayer.setFillColor(sf::Color::Green);
}

void Game::run(){
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  while(mWindow.isOpen()){
    // Mudar o estado do jogo {TimePerFrame} vezes por segundo
    sf::Time elapsedTime = clock.restart();
    timeSinceLastUpdate += elapsedTime;

    while(timeSinceLastUpdate > TimePerFrame){
      timeSinceLastUpdate -= TimePerFrame;
      processEvents();
      update(TimePerFrame);
    }

    // Renderizar o tempo todo
    render();
  }
}

void Game::processEvents(){
  sf::Event event;
  while(mWindow.pollEvent(event)){

    switch (event.type){

      case sf::Event::KeyPressed:
        handlePlayerInput(event.key.code, true);
        break;

      case sf::Event::KeyReleased:
        handlePlayerInput(event.key.code, false);
        break;

      case sf::Event::Closed:
        mWindow.close();
        break;

    }
  }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){
  if (key == sf::Keyboard::W)
    mIsMovingUp = isPressed;

  else if (key == sf::Keyboard::S)
    mIsMovingDown = isPressed;

  if (key == sf::Keyboard::A)
    mIsMovingLeft = isPressed;

  if (key == sf::Keyboard::D)
    mIsMovingRight = isPressed;
}

void Game::update(sf::Time elapsedTime){
  sf::Vector2f movement(0.f, 0.f);

  if(mIsMovingUp)
    movement.y -= PlayerSpeed;
  if(mIsMovingDown)
    movement.y += PlayerSpeed;
  if(mIsMovingLeft)
    movement.x -= PlayerSpeed;
  if(mIsMovingRight)
    movement.x += PlayerSpeed;

  mPlayer.move(movement * elapsedTime.asSeconds());
}

void Game::render(){
  mWindow.clear();
  mWindow.draw(mPlayer);
  mWindow.display();
}
