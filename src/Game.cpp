#include <Constants.hpp>
#include <Game.hpp>
#include <States/GameState.hpp>
#include <States/PausedState.hpp>
#include <AssetManager.hpp>

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Application", sf::Style::Close)
// Usamos um sistema de estados para montar telas e o menu de pause.
// A todo tempo a gente tem guardado o estado atual e o anterior.
//
// Se eu quero pausar o jogo, o estado do jogo passa pro previousState
// E o currentState vira um novo PausedState.
//
// O jogo dá update, passa os eventos e renderiza só o currentState
,currentState(nullptr)
,previousState(nullptr)
{
  // Começa o jogo no GameState
  changeState(State::States::GameState);
}

void Game::run()
{
  // Todas os recursos do jogo são carregados no início
  // e ficam na memória durante toda a execução.
  //
  // Foi um meio termo que encontramos entre ter que dar um
  // load from file na textura do inimigo toda vez que for
  // criar um inimigo novo, e montar uma classe super complicada
  // para ir alocando e desalocando da memória as texturas que vão
  // ser utilizadas.
  AssetManager::loadAssets();

  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  while(window.isOpen())
  {
    sf::Time elapsedTime = clock.restart();
    timeSinceLastUpdate += elapsedTime;

    // O jogo roda em fixed-time steps.
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
    }

    // Mas desenha na tela sempre que possível
    currentState->render(window);
  }
}

Game::~Game()
{
  delete currentState;
  delete previousState;
}


void Game::changeState(State::States newState)
{
  // Mudar para o estado anterior é um pouco mais
  // complicado do que só trocar para um qualquer.
  // Então ficou nesse if separado.
  if (newState == State::States::Previous)
  {
    State* buffer = currentState;
    currentState = previousState;
    previousState = buffer;
    return;
  }

  // Independente de qual estado eu vou,
  // o previousState é sempre deletado
  delete previousState;
  previousState = currentState;

  switch (newState)
  {
  case State::States::Paused:
    currentState = new PausedState();
    break;

  case State::States::GameState:
    currentState = new GameState();
    break;
  }

  // Para evitar que a classe State saiba da existência
  // da classe Game. A gente usou um sistema de função
  // de callback.
  currentState->setStageChanger(
    // A classe State tem uma função de mudar o estado,
    // mas não sabe como ela funciona. So sabe que se ela quiser
    // mudar, ela chama isso.
    [this](State::States newState){changeState(newState);}
  );
}
