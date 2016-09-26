#ifndef __GAMESTATEMANAGER_HPP__
#define __GAMESTATEMANAGER_HPP__

#include <stack>
#include "GameState.hpp"

class GameStateManager {
  private:
    std::stack<GameState*> states;

  public:
    static GameStateManager* Instance();
    void insert(GameState* state);
    void extract();
    GameState* getState();

  private:
    GameStateManager();
    ~GameStateManager();
    static GameStateManager* instance;
};

#endif // __GAMESTATEMANAGER_HPP__
