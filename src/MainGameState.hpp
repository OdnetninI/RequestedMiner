#ifndef __MAINGAMESTATE_HPP__
#define __MAINGAMESTATE_HPP__

#include "GameState.hpp"
#include "EntityManager.hpp"
#include "TextureManager.hpp"
#include "AnimationManager.hpp"

class MainGameState : public GameState {
  private:
    EntityManager entityManager;
    TextureManager textureManager;
    AnimationManager animationManager;

  public:
    MainGameState();
    ~MainGameState();
    void init();
    void update();
    void render();
    void cleanup();
};

#endif // __MAINGAMESTATE_HPP__
