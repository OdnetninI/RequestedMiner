#ifndef __MAINGAMESTATE_HPP__
#define __MAINGAMESTATE_HPP__

#include "GameState.hpp"
#include "EntityManager.hpp"
#include "TextureManager.hpp"
#include "AnimationManager.hpp"
#include "TiledScreen.hpp"
#include "Camera.hpp"

#include "AnimatedEntity.hpp"
#include "WorldTilesRetriever.hpp"
#include "Map.hpp"

#include "MapEntity.hpp"

class MainGameState : public GameState {
  private:
    TextureManager textureManager;
    AnimationManager animationManager;

    WorldTilesRetriever tileRetriever;
    TiledScreen tiledScreen;
    uint64_t x, y;
    AnimatedEntity* player;
    MapEntity _player;

    Map* pallet;
    Map* route1;
    Map* verde;

    Camera camera;
    MapEntity mapBall;

  public:
    MainGameState();
    ~MainGameState();
    void init();
    void update();
    void render();
    void cleanup();
};

#endif // __MAINGAMESTATE_HPP__
