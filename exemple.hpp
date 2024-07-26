#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Game {
  public:
    Game();
    void run();

  private:
    void processevents();
    void update(sf::time elapsedtime);
    void render();
    void handleplayerinput(sf::keyboard::key key, bool ispressed);

  private:
    static const float playerspeed;
    static const sf::time timeperframe;

    sf::renderwindow mwindow;
    sf::CircleShape mPlayer;

    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingLeft;
    bool mIsMovingRight;
};

#endif
