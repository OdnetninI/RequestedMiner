#ifndef __MAINGAMESTATE_HPP__
#define __MAINGAMESTATE_HPP__

#include "GameState.hpp"
#include "EntityManager.hpp"
#include "TextureManager.hpp"
#include "AnimationManager.hpp"
#include "TiledScreen.hpp"

#include "AnimatedEntity.hpp"
#include "WorldTilesRetriever.hpp"

class MainGameState : public GameState {
  private:
    EntityManager entityManager;
    TextureManager textureManager;
    AnimationManager animationManager;

    WorldTilesRetriever tileRetriever;
    TiledScreen tiledScreen;
    int8_t sx, sy;
    AnimatedEntity* pickaxe;

  public:
    MainGameState();
    ~MainGameState();
    void init();
    void update();
    void render();
    void cleanup();
};

#endif // __MAINGAMESTATE_HPP__
