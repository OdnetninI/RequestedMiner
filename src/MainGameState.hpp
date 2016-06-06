#ifndef __MAINGAMESTATE_HPP__
#define __MAINGAMESTATE_HPP__

#include "GameState.hpp"
#include "Entity.hpp"

class MainGameState : public GameState {
  private:
    Entity entity;
    sf::Texture text;

  public:
    MainGameState();
    ~MainGameState();
    void init();
    void update();
    void render();
    void cleanup();
};

#endif // __MAINGAMESTATE_HPP__
