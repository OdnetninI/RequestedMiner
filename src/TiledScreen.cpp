#include "TiledScreen.hpp"

TiledScreen::TiledScreen() {
  for (int16_t x = 0; x < MAP_WIDTH; x++) {
    for (int16_t y = 0; y < MAP_HEIGTH; y++) {
      for (int16_t l = 0; l < UP_LAYERS; l++)
        vertexSet(up[l], x, y, 0, 0);
      for (int16_t l = 0; l < DOWN_LAYERS; l++)
        vertexSet(down[l], x, y, 0, 0);
    }
  }
  vertexSet(down[0], 1,1, 0,1);
  vertexSet(down[0], 2,1, 1,0);
  vertexSet(down[0], 1,2, 1,0);
  vertexSet(down[0], 2,2, 0,1);
  vertexSet(down[1], 2,2, 2,0);
}

void TiledScreen::vertexSet(sf::Vertex vertex[], uint16_t x, uint16_t y, uint16_t tx, uint16_t ty) {
  sf::Vertex* quad = &vertex[(x + y * MAP_WIDTH) * 4];
  quad[0].position = sf::Vector2f((x - 1) * TILE_SIZE, (y - 1) * TILE_SIZE);
  quad[1].position = sf::Vector2f(x * TILE_SIZE, (y - 1) * TILE_SIZE);
  quad[2].position = sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE);
  quad[3].position = sf::Vector2f((x - 1) * TILE_SIZE, y * TILE_SIZE);

  quad[0].texCoords = sf::Vector2f(tx * TILE_SIZE, ty * TILE_SIZE);
  quad[1].texCoords = sf::Vector2f((tx + 1) * TILE_SIZE, ty * TILE_SIZE);
  quad[2].texCoords = sf::Vector2f((tx + 1) * TILE_SIZE, (ty + 1) * TILE_SIZE);
  quad[3].texCoords = sf::Vector2f(tx * TILE_SIZE, (ty + 1) * TILE_SIZE);
}

TiledScreen::~TiledScreen() {

}

void TiledScreen::setTileset (sf::Texture *texture) {
  this->renderStates.texture = texture;
}

void TiledScreen::drawUnder(sf::RenderWindow *window) {
  for (int16_t l = 0; l < DOWN_LAYERS; l++)
    window->draw(this->down[l], MAP_WIDTH*MAP_HEIGTH*VERS_PER_TILE, sf::Quads,this->renderStates);
}

void TiledScreen::drawUpper(sf::RenderWindow *window) {
  for (int16_t l = 0; l < UP_LAYERS; l++)
    window->draw(this->up[l], MAP_WIDTH*MAP_HEIGTH*VERS_PER_TILE, sf::Quads,this->renderStates);
}
