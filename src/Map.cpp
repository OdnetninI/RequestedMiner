#include "Map.hpp"

Map::Map(uint64_t minX, uint64_t maxX, uint64_t minY, uint64_t maxY) {
  this->minX = minX;
  this->minY = minY;
  this->maxX = maxX;
  this->maxY = maxY;
  this->w = maxX - minX + 1;
  this->h = maxY - minY + 1;
  for (uint16_t l = 0; l < UP_LAYERS; l++) {
    up[l] = new sf::Vector2u*[this->h];
    for (uint64_t i = 0; i < this->h; i++)
      up[l][i] = new sf::Vector2u[this->w];
  }
  for (uint16_t l = 0; l < DOWN_LAYERS; l++) {
    down[l] = new sf::Vector2u*[this->h];
    for (uint64_t i = 0; i < this->h; i++)
      down[l][i] = new sf::Vector2u[this->w];
  }
}

Map::~Map() {
  for (uint16_t l = 0; l < UP_LAYERS; l++) {
    for (uint64_t i = 0; i < this->h; i++)
      delete[] up[l][i];
    delete[] up[l];
  }
  for (uint16_t l = 0; l < DOWN_LAYERS; l++) {
    for (uint64_t i = 0; i < this->h; i++)
      delete[] down[l][i];
    delete[] down[l];
  }
}

sf::Vector2u Map::getTile (bool up, uint16_t l, uint64_t x, uint16_t y) {
  if (up) return this->up[l][y-minY][x-minX];
  else return down[l][y-minY][x-minX];
}

void Map::addAyacente (Map* m) {
  this->adyacentes.push_back(m);
}

#include <fstream>
#include "Logger.hpp"

void Map::loadFromFile (const char* filename, sf::Vector2u** data) {
  std::ifstream file (filename);

  if (!file.good()) {
    file.close();
    Logger::Instance() << "ERROR\n";
    return;
  }

  for (uint64_t y = 0; y < h; y++) {
    for (uint64_t x = 0; x < w; x++) {
      uint16_t tile = -1;
      char z;
      if (x != w-1) file >> tile >> z;
      else file >> tile;
      data[y][x].x = tile%8;
      data[y][x].y = tile/8;
    }
  }

  file.close();
}

void Map::load (bool up, uint16_t layer, const char* filename) {
  if (up) loadFromFile(filename, this->up[layer]);
  else loadFromFile(filename, down[layer]);
}
