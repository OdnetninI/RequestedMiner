#include "Map.hpp"

Map::Map(uint64_t minX, uint64_t maxX, uint64_t minY, uint64_t maxY) {
  this->minX = minX;
  this->minY = minY;
  this->maxX = maxX;
  this->maxY = maxY;
  this->w = maxX - minX + 1;
  this->h = maxY - minY + 1;
  this->animatedTimes = 2;
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

MapEventManager* Map::getEventManager() {
  return &this->mapEventManager;
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

void Map::setTile (bool up, uint16_t l, uint64_t x, uint16_t y, sf::Vector2u tile) {
  if (up ) this->up[l][y-minY][x-minX] = tile;
  else down[l][y-minY][x-minX] = tile;
}

uint16_t Map::getAnimationTime () {
  return animatedTimes;
}

void Map::update() {
  if (animatedTimes == 0) {
    for (uint64_t x = 0; x < this->w; x++) {
      for (uint64_t y = 0; y < this->h; y++) {
        for (uint16_t l = 0; l < UP_LAYERS; l++) {
          if (up[l][y][x].x == 4 && up[l][y][x].y == 0)
            up[l][y][x] = sf::Vector2u(2,2);
          else if (up[l][y][x].x == 2 && up[l][y][x].y == 2)
            up[l][y][x] = sf::Vector2u(4,0);
        }
        for (uint16_t l = 0; l < DOWN_LAYERS; l++) {
          if (down[l][y][x].x == 4 && down[l][y][x].y == 0)
            down[l][y][x] = sf::Vector2u(2,2);
          else if (down[l][y][x].x == 2 && down[l][y][x].y == 2)
            down[l][y][x] = sf::Vector2u(4,0);
        }
      }
    }
    animatedTimes = 60;
  }
  this->animatedTimes--;
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

// Type = How i interacted
// 0 = Talked
// 1 = Walked
// You can talk to event to get info u other things, but it can have
// a different interaction when walked on it.
void Map::checkEvent (uint64_t x, uint64_t y, uint8_t type) {
  MapEvent* evento = this->mapEventManager.find(x,y);
  if (!evento) return;
  if (!type) evento->whenTalked();
  else evento->whenWalked();
}

void Map::load (bool up, uint16_t layer, const char* filename) {
  if (up) loadFromFile(filename, this->up[layer]);
  else loadFromFile(filename, down[layer]);
}
