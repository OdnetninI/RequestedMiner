#include "WorldTilesRetriever.hpp"
#include "Map.hpp"
#include <iostream>
sf::Vector2u WorldTilesRetriever::getTile (bool up, uint16_t l, uint64_t x, uint64_t y) {
  Map* m = this->posFinder.buscar(x,y);
  if (m)return m->getTile(up,l,x,y);
  return sf::Vector2u(0,0);
}
