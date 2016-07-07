#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <cstdint>
#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include "GameStateManager.hpp"

#define TILES_X 15
#define TILES_Y 12
#define TILE_SIZE 16
#define SCREEN_X TILES_X*TILE_SIZE
#define SCREEN_Y TILES_Y*TILE_SIZE

class Game {
  private:
    sf::RenderWindow window;
    sf::View view;
    sf::Event events;
    sf::ContextSettings glContextSettings;
    bool running;
    GameStateManager* stateManager;
    GameState* currentState;
    bool isFocused;

    // Clock things
    sf::Clock gameSpeedTimer;
    uint16_t ticks;
    uint16_t oldTick;
    uint16_t actualTick;
    uint16_t frameSkip;
    uint16_t frameTicks;

  public:
    static Game* Instance();
    static void destroy();
    int gameLoop();
    void update();
    void render();
    sf::RenderWindow* getWindow();
    bool getFocus();

  private:
    Game();
    ~Game();
    static Game* instance;
};


#endif // __GAME_HPP__
