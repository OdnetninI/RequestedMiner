#ifndef __MAINGAMESTATE_HPP__
#define __MAINGAMESTATE_HPP__

#include "GameState.hpp"
#include "Entity.hpp"
#include "EntityManager.hpp"

class MainGameState : public GameState {
  private:
    EntityManager entityManager;
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
