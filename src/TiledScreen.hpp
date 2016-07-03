#ifndef __TILEDSCREEN_HPP__
#define __TILEDSCREEN_HPP__

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "WorldTilesRetriever.hpp"

#define TILE_SIZE 16
#define MAP_WIDTH ((SCREEN_X/TILE_SIZE)+2)
#define MAP_HEIGTH ((SCREEN_Y/TILE_SIZE)+2)
#define UP_LAYERS 2
#define DOWN_LAYERS 2
#define VERS_PER_TILE 4

// Up layers: layers over sprites
// Down Layers: layers down sprites
class TiledScreen : private sf::Transformable {
  private:
    sf::RenderStates renderStates;
    sf::Vertex up[UP_LAYERS][MAP_WIDTH*MAP_HEIGTH*VERS_PER_TILE];
    sf::Vertex down[DOWN_LAYERS][MAP_WIDTH*MAP_HEIGTH*VERS_PER_TILE];

    void vertexSet (sf::Vertex vertex[], uint16_t x, uint16_t y, uint16_t tx, uint16_t ty);
    WorldTilesRetriever* tileRetriever;

  public:
    TiledScreen(WorldTilesRetriever* tileRetriever);
    ~TiledScreen();

    void update (uint64_t real_x, uint64_t real_y);
    void drawUnder (sf::RenderWindow *window);
    void drawUpper (sf::RenderWindow *window);
    void setTileset (sf::Texture *texture);
    void setPos (int8_t x, int8_t y);
    void setDownTile (uint16_t layer, uint16_t x, uint16_t y, uint16_t tx, uint16_t ty);
    void setUpTile (uint16_t layer, uint16_t x, uint16_t y, uint16_t tx, uint16_t ty);
};

#endif // __TILEDSCREEN_HPP__
