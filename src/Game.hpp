#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <cstdint>
#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include "GameStateManager.hpp"

#define NO_ERRORS 0
#define SCREEN_X 240
#define SCREEN_Y 160
#define SCALE_FACTOR 3
#define MAX_FRAMESKIP 10

class Game {
  private:
    sf::RenderWindow window;
    sf::View view;
    sf::Event events;
    sf::ContextSettings glContextSettings;
    bool running;
    GameStateManager* stateManager;
    GameState* currentState;

    // Clock things
    sf::Clock gameSpeedTimer;
    uint16_t ticks;
    uint16_t oldTick;
    uint16_t actualTick;
    uint16_t frameSkip;
    uint16_t frameTicks;

  public:
    static Game* Instance();
    int gameLoop();
    void update();
    void render();

  private:
    Game();
    ~Game();
    static Game* instance;
};


#endif // __GAME_HPP__
