#ifndef __MAINGAMESTATE_HPP__
#define __MAINGAMESTATE_HPP__

#include "GameState.hpp"
#include "../Entity/EntityManager.hpp"
#include "../System/TextureManager.hpp"
#include "../Entity/AnimationManager.hpp"
#include "../System/TiledScreen.hpp"
#include "../Map/Camera.hpp"

#include "../Entity/AnimatedEntity.hpp"
#include "../System/WorldTilesRetriever.hpp"
#include "../Map/Map.hpp"

#include "../Map/MapEntity.hpp"
#include "../Map/MapCharacter.hpp"
#include "../System/Controller.hpp"

class MainGameState : public GameState {
  private:
    TextureManager textureManager;
    AnimationManager animationManager;

    WorldTilesRetriever tileRetriever;
    TiledScreen tiledScreen;
    uint64_t x, y;
    AnimatedEntity* player;
    MapCharacter _player;

    Map* pallet;
    Map* route1;
    Map* verde;

    Controller controller;

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
