#ifndef __TILEDSCREEN_HPP__
#define __TILEDSCREEN_HPP__

#include <SFML/Graphics.hpp>
#include "Game.hpp"

#define TILE_SIZE 16
#define MAP_WIDTH ((SCREEN_X/TILE_SIZE)+2)
#define MAP_HEIGTH ((SCREEN_Y/TILE_SIZE)+2)
#define UP_LAYERS 2
#define DOWN_LAYERS 2
#define VERS_PER_TILE 4

// Up layers: layers over sprites
// Down Layers: layers down sprites
class TiledScreen {
  private:
    sf::Texture* tileset = nullptr;
    sf::Vertex up[UP_LAYERS][MAP_WIDTH*MAP_HEIGTH*VERS_PER_TILE];
    sf::Vertex down[DOWN_LAYERS][MAP_WIDTH*MAP_HEIGTH*VERS_PER_TILE];

  public:
    TiledScreen();
    ~TiledScreen();
};

#endif // __TILEDSCREEN_HPP__
