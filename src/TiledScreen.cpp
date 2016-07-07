#include "TiledScreen.hpp"

TiledScreen::TiledScreen(WorldTilesRetriever* tileRetriever) {
  this->tileRetriever = tileRetriever;
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

void TiledScreen::setUpTile(uint16_t layer, uint16_t x, uint16_t y, uint16_t tx, uint16_t ty) {
  if (layer >= UP_LAYERS) return;
  sf::Vertex* quad = &this->up[layer][(x + y * MAP_WIDTH) * 4];
  quad[0].texCoords = sf::Vector2f(tx * TILE_SIZE, ty * TILE_SIZE);
  quad[1].texCoords = sf::Vector2f((tx + 1) * TILE_SIZE, ty * TILE_SIZE);
  quad[2].texCoords = sf::Vector2f((tx + 1) * TILE_SIZE, (ty + 1) * TILE_SIZE);
  quad[3].texCoords = sf::Vector2f(tx * TILE_SIZE, (ty + 1) * TILE_SIZE);
}

void TiledScreen::setDownTile(uint16_t layer, uint16_t x, uint16_t y, uint16_t tx, uint16_t ty) {
  if (layer >= DOWN_LAYERS) return;
  sf::Vertex* quad = &this->down[layer][(x + y * MAP_WIDTH) * 4];
  quad[0].texCoords = sf::Vector2f(tx * TILE_SIZE, ty * TILE_SIZE);
  quad[1].texCoords = sf::Vector2f((tx + 1) * TILE_SIZE, ty * TILE_SIZE);
  quad[2].texCoords = sf::Vector2f((tx + 1) * TILE_SIZE, (ty + 1) * TILE_SIZE);
  quad[3].texCoords = sf::Vector2f(tx * TILE_SIZE, (ty + 1) * TILE_SIZE);
}

void TiledScreen::update (uint64_t real_x, uint64_t real_y) {
  for (int16_t y = 0; y < MAP_HEIGTH; y++) {
    for (int16_t x = 0; x < MAP_WIDTH; x++) {
      for (int16_t l = 0; l < UP_LAYERS; l++) {
        sf::Vector2u tile = this->tileRetriever->getTile(true, l, x+real_x, y+real_y);
        this->vertexSet(this->up[l], x, y, tile.x, tile.y);
      }
      for (int16_t l = 0; l < DOWN_LAYERS; l++) {
        sf::Vector2u tile = this->tileRetriever->getTile(false, l, x+real_x, y+real_y);
        this->vertexSet(this->down[l], x, y, tile.x, tile.y);
      }
    }
  }
}

void TiledScreen::update (sf::Vector<uint64_t> realpos) {
  this->update(realpos.x, realpos.y);
}

TiledScreen::~TiledScreen() {

}

void TiledScreen::setPos(int8_t x, int8_t y) {
  this->setPosition((float)x, (float)y);
}

void TiledScreen::setTileset (sf::Texture *texture) {
  this->renderStates.texture = texture;
}

void TiledScreen::drawUnder(sf::RenderWindow *window) {
  this->renderStates.transform = getTransform();
  for (int16_t l = 0; l < DOWN_LAYERS; l++)
    window->draw(this->down[l], MAP_WIDTH*MAP_HEIGTH*VERS_PER_TILE, sf::Quads,this->renderStates);
}

void TiledScreen::drawUpper(sf::RenderWindow *window) {
  this->renderStates.transform = getTransform();
  for (int16_t l = 0; l < UP_LAYERS; l++)
    window->draw(this->up[l], MAP_WIDTH*MAP_HEIGTH*VERS_PER_TILE, sf::Quads,this->renderStates);
}
